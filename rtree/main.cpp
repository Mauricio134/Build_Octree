#include <vtkSmartPointer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkCamera.h>

#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "RTree.h"

using namespace std;


vector<pair<pair<double, double>, pair<double, double>>> recta;
vector<pair<double, double>> puntos;

void print(const int& command, vector<vector<vector<pair<int, int>>>>& objects_n, string& output) {
	output.resize(0);
	output = command;

	switch (command)
	{
	case 0:// OBJECTS
		output += "|" + to_string(objects_n[0].size());
		for (auto& polygon : objects_n[0]) {
			output += "|" + to_string(polygon.size());

			for (auto& point : polygon) {
				output += "|" + to_string(point.first) + "|" + to_string(point.second);
			}
		}
		break;

	case 1: //MBRS:
		cout << " number of (objects) :" << to_string(objects_n.size()) << endl;
		output += "|" + to_string(objects_n.size());
		for (auto& objects : objects_n) {
			output += "|" + to_string(objects.size());
			cout << " number of polygons :" << to_string(objects.size()) << endl;
			for (auto& polygon : objects) {
				output += "|" + to_string(polygon.size());
				cout << " number of points :" << to_string(polygon.size()) << endl;
				for (auto& point : polygon) {
					output += "|" + to_string(point.first) + "|" + to_string(point.second);
					cout << "   point:" << to_string(point.first) << " | " << to_string(point.second) << endl;

				}
			}
			cout << endl << "--------------------" << endl;
		}
		break;
	default:
		output += "|0";
		break;
	}

	output += "|END";
	cout << output;
}

void print_pair(vector<pair<int, int>> output) {
	for (auto& x : output)
	{
		cout << x.first << " ; " << x.second << " - ";
	}
}

int main(int argc, char* argv[])
{
	vector<vector<pair<int, int>>> vpoints;


	float coord[16] = { 20, 59, 20, 43, 50, 58 , 48,67, 105, 68, 74, 64, 83, 40, 104, 54 };
	srand(time(0));

	vector<pair<int, int>> points;
	for (int i = 0; i < 2000; i += 2) {
		pair<int, int> A;
		float xr = abs(fmod(static_cast<float>(rand()) ,(float)1000.0));
		float yr = abs(fmod(static_cast<float>(rand()) ,(float)1000.0));
		A.first = xr;
		A.second = yr;
		points.push_back(A);
	}
	for (unsigned int i = 0; i < 1000; i += 2) {
		//v_points.insertpush_back(A);          
		vector<pair<int, int>>  sub1(&points[i], &points[i + 2]);
		vpoints.push_back(sub1);

	}




	RTree rtree;

	string output;
	vector<vector<pair<int, int>>> objects;

	vector<vector<vector<pair<int, int>>>> objects_n;

	for (auto& x : vpoints)
	{
		cout << "inserting " << x.size() << ": ";
		print_pair(x);
		Rect rect = rtree.MBR(x);
		rtree.Insert(rect.m_min, rect.m_max, x);
		cout << endl;
	}
	rtree.getMBRs(objects_n);
	print(1, objects_n, output);
	rtree.LEAF_(recta, puntos);
	cout << endl;
	Rect * rectangulo = new Rect(20,70,50,100);
	vector<pair<pair<int,int>, pair<int,int>>> result = rtree.S(rectangulo);

	for(auto p:result){
		cout << p.first.first << "," << p.first.second << " " << p.second.first << "," << p.second.second << "\n";
	}

    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->AddRenderer(renderer);
    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    renderWindowInteractor->SetRenderWindow(renderWindow);

    for(auto rec:recta){
        double x1 = rec.first.first;
        double y1 = rec.first.second;
        double x2 = rec.second.first;
        double y2 = rec.second.second;

        double pointsArray[4][3] = {
            {x1, y1, 0.0},
            {x2, y1, 0.0},
            {x2, y2, 0.0},
            {x1, y2, 0.0}
        };

        vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
        for (int i = 0; i < 4; ++i)
        {
            points->InsertNextPoint(pointsArray[i]);
        }

        vtkSmartPointer<vtkCellArray> lines = vtkSmartPointer<vtkCellArray>::New();
        vtkIdType lineIndices[5] = {0, 1, 2, 3, 0}; // Connect the vertices to form a closed loop
        lines->InsertNextCell(5, lineIndices);

        // Create a vtkPolyData object and assign the points and lines
        vtkSmartPointer<vtkPolyData> rectanglePolyData = vtkSmartPointer<vtkPolyData>::New();
        rectanglePolyData->SetPoints(points);
        rectanglePolyData->SetLines(lines);

        // Create a mapper and actor for visualization
        vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper->SetInputData(rectanglePolyData);

        vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
        actor->SetMapper(mapper);

        actor->GetProperty()->SetLineWidth(2.0); 
        renderer->AddActor(actor);

    }

    vtkSmartPointer<vtkPoints> puntitos = vtkSmartPointer<vtkPoints>::New();
    vtkIdType pointId = 0;
    vtkSmartPointer<vtkCellArray> vertices = vtkSmartPointer<vtkCellArray>::New();
    for(auto poi:puntos){
        puntitos->InsertNextPoint(poi.first, poi.second, 0.0);
        vertices->InsertNextCell(1, &pointId);
        pointId++;
    }

    // Crear un vtkPolyData y asignar los puntos
    vtkSmartPointer<vtkPolyData> pointPolyData = vtkSmartPointer<vtkPolyData>::New();
    pointPolyData->SetPoints(puntitos);
    pointPolyData->SetVerts(vertices);
    // Set up the rendering window and start the interaction

    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputData(pointPolyData);

    // Crear un vtkActor para los puntos
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);

    // Setear propiedades para los puntos (color y tamaño)
    actor->GetProperty()->SetColor(1.0, 0.0, 0.0); // Color rojo
    actor->GetProperty()->SetPointSize(10.0);       // Tamaño de los puntos

    // Agregar el actor al renderer
    renderer->AddActor(actor);
    renderWindow->Render();
    renderWindowInteractor->Start();

	return 0;
}