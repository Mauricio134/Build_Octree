// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkNewickTreeReader.h"

#include "vtkByteSwap.h"
#include "vtkCellArray.h"
#include "vtkDataSetAttributes.h"
#include "vtkDoubleArray.h"
#include "vtkFieldData.h"
#include "vtkInformation.h"
#include "vtkInformationVector.h"
#include "vtkMutableDirectedGraph.h"
#include "vtkNew.h"
#include "vtkObjectFactory.h"
#include "vtkStreamingDemandDrivenPipeline.h"
#include "vtkStringArray.h"
#include "vtkTree.h"
#include "vtkTreeDFSIterator.h"
#include "vtksys/FStream.hxx"

#include <fstream>
#include <iostream>

VTK_ABI_NAMESPACE_BEGIN
vtkStandardNewMacro(vtkNewickTreeReader);

#ifdef read
#undef read
#endif

//------------------------------------------------------------------------------
vtkNewickTreeReader::vtkNewickTreeReader()
{
  vtkTree* output = vtkTree::New();
  this->SetOutput(output);
  // Releasing data for pipeline parallelism.
  // Filters will know it is empty.
  output->ReleaseData();
  output->Delete();
}

//------------------------------------------------------------------------------
vtkNewickTreeReader::~vtkNewickTreeReader() = default;

//------------------------------------------------------------------------------
vtkTree* vtkNewickTreeReader::GetOutput()
{
  return this->GetOutput(0);
}

//------------------------------------------------------------------------------
vtkTree* vtkNewickTreeReader::GetOutput(int idx)
{
  return vtkTree::SafeDownCast(this->GetOutputDataObject(idx));
}

//------------------------------------------------------------------------------
void vtkNewickTreeReader::SetOutput(vtkTree* output)
{
  this->GetExecutive()->SetOutputData(0, output);
}

//------------------------------------------------------------------------------
int vtkNewickTreeReader::ReadNewickTree(const char* buffer, vtkTree& tree)
{
  // Read through the input file to count the number of nodes in the tree.
  vtkIdType numNodes = 0;
  this->CountNodes(buffer, &numNodes);

  // Create the edge weight array
  vtkNew<vtkDoubleArray> weights;
  weights->SetNumberOfComponents(1);
  weights->SetName("weight");
  weights->SetNumberOfValues(numNodes - 1); // the number of edges = number of nodes -1 for a tree
  weights->FillComponent(0, 0.0);

  // Create the names array
  vtkNew<vtkStringArray> names;
  names->SetNumberOfComponents(1);
  names->SetName("node name");
  names->SetNumberOfValues(numNodes);

  // parse the input file to create the graph
  vtkNew<vtkMutableDirectedGraph> builder;
  this->BuildTree(const_cast<char*>(buffer), builder, weights, names, -1);

  builder->GetVertexData()->AddArray(names);

  if (!tree.CheckedShallowCopy(builder))
  {
    vtkErrorMacro(<< "Edges do not create a valid tree.");
    return 1;
  }

  // check if our input file contained edge weight information
  bool haveWeights = false;
  for (vtkIdType i = 0; i < weights->GetNumberOfTuples(); ++i)
  {
    if (weights->GetValue(i) != 0.0)
    {
      haveWeights = true;
      break;
    }
  }
  if (!haveWeights)
  {
    return 1;
  }

  tree.GetEdgeData()->AddArray(weights);

  vtkNew<vtkDoubleArray> nodeWeights;
  nodeWeights->SetNumberOfTuples(tree.GetNumberOfVertices());

  // set node weights
  vtkNew<vtkTreeDFSIterator> treeIterator;
  treeIterator->SetStartVertex(tree.GetRoot());
  treeIterator->SetTree(&tree);
  while (treeIterator->HasNext())
  {
    vtkIdType vertex = treeIterator->Next();
    vtkIdType parent = tree.GetParent(vertex);
    double weight = 0.0;
    if (parent >= 0)
    {
      weight = weights->GetValue(tree.GetEdgeId(parent, vertex));
      weight += nodeWeights->GetValue(parent);
    }
    nodeWeights->SetValue(vertex, weight);
  }

  nodeWeights->SetName("node weight");
  tree.GetVertexData()->AddArray(nodeWeights);

  return 1;
}

//------------------------------------------------------------------------------
int vtkNewickTreeReader::ReadMeshSimple(const std::string& fname, vtkDataObject* doOutput)
{
  vtkDebugMacro(<< "Reading Newick tree ...");

  if (!this->ReadFromInputString)
  {
    if (fname.empty())
    {
      vtkErrorMacro("FileName not set.");
      return 1;
    }

    vtksys::ifstream ifs(fname.c_str(), vtksys::ifstream::in);
    if (!ifs.good())
    {
      vtkErrorMacro(<< "Unable to open " << fname << " for reading");
      return 1;
    }

    // Read the input file into a char *
    ifs.seekg(0, std::ios::end);
    this->InputStringLength = ifs.tellg();
    ifs.seekg(0, std::ios::beg);
    this->InputString = new char[this->InputStringLength];
    ifs.read(this->InputString, this->InputStringLength);
    ifs.close();
  }
  else
  {
    if ((!this->InputString) || (this->InputStringLength == 0))
    {
      vtkErrorMacro(<< "Input string is empty!");
      return 1;
    }
  }

  vtkTree* const output = vtkTree::SafeDownCast(doOutput);

  if (!ReadNewickTree(this->InputString, *output))
  {
    vtkErrorMacro(<< "Error reading a vtkTree from the input.");
    return 1;
  }

  vtkDebugMacro(<< "Read " << output->GetNumberOfVertices() << " vertices and "
                << output->GetNumberOfEdges() << " edges.\n");

  return 1;
}

//------------------------------------------------------------------------------
void vtkNewickTreeReader::CountNodes(const char* buffer, vtkIdType* numNodes)
{
  char* current;
  char* start;
  char temp;
  int childCount;

  start = const_cast<char*>(buffer);

  if (*start != '(')
  {
    // Leaf node. Separate name from weight.
    // If weight doesn't exist then take care of name only
    current = const_cast<char*>(buffer);
    while (*current != '\0')
    {
      current++;
    }
    ++(*numNodes);
  }
  else
  {
    ++(*numNodes);
    // Search for all child nodes
    // Find all ',' until corresponding ')' is encountered
    childCount = 0;
    start++;
    current = start;
    while (childCount >= 0)
    {
      switch (*current)
      {
        case '(':
          // Find corresponding ')' by counting
          start = current;
          current++;
          childCount++;
          while (childCount > 0)
          {
            if (*current == '(')
            {
              childCount++;
            }
            else if (*current == ')')
            {
              childCount--;
            }
            current++;
          }
          while (*current != ',' && *current != ')')
          {
            current++;
          }

          temp = *current;
          *current = '\0';
          // Count child nodes using recursion
          this->CountNodes(start, numNodes);
          *current = temp;

          if (*current != ')')
          {
            current++;
          }
          break;

        case ')':
          // End of this tree. Go to next part to retrieve distance
          childCount--;
          break;

        case ',':
          // Impossible separation since according to the algorithm, this symbol will never
          // encountered. Currently don't handle this and don't create any node
          break;

        default:
          // leaf node encountered
          start = current;
          while (*current != ',' && *current != ')')
          {
            current++;
          }

          temp = *current;
          *current = '\0';
          // Count child nodes using recursion
          this->CountNodes(start, numNodes);
          *current = temp;

          if (*current != ')')
          {
            current++;
          }
          break;
      }
    }

    // If start at ':', then the internal node has no name.
    current++;
    if (*current == ':')
    {
      while (*current != '\0' && *current != ';')
      {
        current++;
      }
    }
    else if (*current != ';' && *current != '\0')
    {
      while (*current != ':' && *(current + 1) != ';' && *(current + 1) != '\0')
      {
        current++;
      }
      current++;
      while (*current != '\0' && *current != ';')
      {
        current++;
      }
    }
  }
}

//------------------------------------------------------------------------------
vtkIdType vtkNewickTreeReader::BuildTree(char* buffer, vtkMutableDirectedGraph* g,
  vtkDoubleArray* weights, vtkStringArray* names, vtkIdType parent)
{
  char* current;
  char* start;
  char* colon = nullptr;
  char temp;
  int childCount;
  vtkIdType node;

  start = buffer;

  if (*start != '(')
  {
    // Leaf node. Separate name from weight (if it exists).
    current = buffer;
    while (*current != '\0')
    {
      if (*current == ':')
      {
        colon = current;
      }
      current++;
    }
    node = g->AddChild(parent);
    if (colon == nullptr)
    {
      // Name only
      std::string name(start, strlen(start));
      names->SetValue(node, name);
    }
    else
    {
      // Name
      *colon = '\0';
      std::string name(start, strlen(start));
      names->SetValue(node, name);
      *colon = ':';
      // Weight
      colon++;
      weights->SetValue(g->GetEdgeId(parent, node), atof(colon));
    }
  }
  else
  {
    // Create node
    if (parent == -1)
    {
      node = g->AddVertex();
      names->SetValue(node, "");
    }
    else
    {
      node = g->AddChild(parent);
    }

    // Search for all child nodes
    // Find all ',' until corresponding ')' is encountered
    childCount = 0;
    start++;
    current = start;
    while (childCount >= 0)
    {
      switch (*current)
      {
        case '(':
          // Find corresponding ')' by counting
          start = current;
          current++;
          childCount++;
          while (childCount > 0)
          {
            if (*current == '(')
            {
              childCount++;
            }
            else if (*current == ')')
            {
              childCount--;
            }
            current++;
          }
          while (*current != ',' && *current != ')')
          {
            current++;
          }
          temp = *current;
          *current = '\0';
          // Create a child node using recursion
          this->BuildTree(start, g, weights, names, node);
          *current = temp;
          if (*current != ')')
          {
            current++;
          }
          break;

        case ')':
          // End of this tree. Go to next part to retrieve distance
          childCount--;
          break;

        case ',':
          // Impossible separation since according to the algorithm, this symbol will never
          // encountered. Currently don't handle this and don't create any node
          break;

        default:
          // leaf node encountered
          start = current;
          while (*current != ',' && *current != ')')
          {
            current++;
          }
          temp = *current;
          *current = '\0';
          // Create a child node using recursion
          this->BuildTree(start, g, weights, names, node);
          *current = temp;
          if (*current != ')')
          {
            current++;
          }
          break;
      }
    }

    // If start at ':', then the internal node has no name.
    current++;
    if (*current == ':')
    {
      start = current + 1;
      while (*current != '\0' && *current != ';')
      {
        current++;
      }
      temp = *current;
      *current = '\0';
      weights->SetValue(g->GetEdgeId(parent, node), atof(start));
      names->SetValue(node, "");
      *current = temp;
    }
    else if (*current != ';' && *current != '\0')
    {
      // Find ':' to retrieve distance, if any.
      // At this time *current should equal to ')'
      start = current;
      while (*current != ':' && *current != ';')
      {
        current++;
      }
      temp = *current;
      *current = '\0';
      std::string name(start, strlen(start));
      names->SetValue(node, name);
      *current = temp;
      if (*current != ';')
      {
        current++;
        start = current;
        while (*current != '\0' && *current != ';')
        {
          current++;
        }
        temp = *current;
        *current = '\0';
        weights->SetValue(g->GetEdgeId(parent, node), atof(start));
        *current = temp;
      }
    }
  }

  return node;
}

//------------------------------------------------------------------------------
int vtkNewickTreeReader::FillOutputPortInformation(int, vtkInformation* info)
{
  info->Set(vtkDataObject::DATA_TYPE_NAME(), "vtkTree");
  return 1;
}

//------------------------------------------------------------------------------
void vtkNewickTreeReader::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
  os << indent << "InputString: " << (this->InputString ? this->InputString : "(none)") << endl;
  os << indent << "ReadFromInputString: " << (this->ReadFromInputString ? "on" : "off") << endl;
}
VTK_ABI_NAMESPACE_END
