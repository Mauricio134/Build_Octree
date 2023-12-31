"""Test iterating through a vtkCollection with the standard python syntax"""


from vtkmodules.vtkCommonCore import (
    vtkCollection,
    vtkDataArrayCollection,
    vtkIntArray,
    vtkObject,
)
from vtkmodules.test import Testing


class TestIterateCollection(Testing.vtkTest):
    def setUp(self):
        self.vtkObjs = [vtkObject() for _ in range(30)]
        self.collection = vtkCollection()
        for obj in self.vtkObjs:
            self.collection.AddItem(obj)

        self.emptyCollection = vtkCollection()

    def testIterateCollection(self):
        newObjsList = [obj for obj in self.collection]
        self.assertEqual(self.vtkObjs, newObjsList)

        counter = 0
        for _ in self.collection:
            counter += 1
        self.assertEqual(counter, 30)

        counter = 0
        for _ in self.emptyCollection:
           counter += 1
        self.assertEqual(counter, 0)

    def testCollectionChild(self):
        #check that iteration is being inherited correctly
        dataArray = vtkIntArray()

        dataArrayCollection = vtkDataArrayCollection()
        dataArrayCollection.AddItem(dataArray)

        self.assertEqual([obj for obj in dataArrayCollection],
                         [dataArray])

    def testOperators(self):
        self.assertTrue(self.vtkObjs[0] in self.collection)
        self.assertEqual(list(self.collection), self.vtkObjs)

    def testReferenceCounting(self):
        initialReferenceCount = self.collection.GetReferenceCount()
        list(self.collection)
        self.assertEqual(self.collection.GetReferenceCount(), initialReferenceCount)


if __name__ == "__main__":
    Testing.main([(TestIterateCollection, 'test')])
