#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkCellArray.h>
#include <vtkCubeSource.h>
#include <vtkFloatArray.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPointData.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSmartPointer.h>
#include <vtkTransform.h>

#include <array>

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <math.h>

#define NOMBRE_ARCHIVO "points.csv"
using namespace std;


class Octree;
struct Point;
class Cubo;

vector<Point> puntos;
vector<Cubo> cubos;

#ifndef OCTREE_H
#define OCTREE_H

class Cubo{
public:
    double x;
    double y;
    double z;
    double h;
    Cubo(double a, double b, double c, double H) : x(a), y(b), z(c), h(H) {}
};

struct Point{
    double x;
    double y;
    double z;
    Point(){
        x = 0.0;
        y = 0.0;
        z = 0.0;
    }
    Point(double a, double b, double c) : x(a), y(b), z(c) {}
};


class Octree {
private:
   Octree *children[8];
   Point *points;


   Point bottomLeft;
   double h;

   int nPoints;

public:
    Octree();
    Octree(Point , double);
    bool exist( const Point & );
    void insert( const Point & );
    Point find_closest( const Point &) const;
    void VTK();
};

Octree::Octree(){
    points = nullptr;
    nPoints = 0;
}

Octree::Octree(Point punto, double height){
    for (int i = 0; i < 8; ++i) children[i] = new Octree();
    points = nullptr;
    bottomLeft = punto;
    h = height;
    nPoints = 0;
}

#endif

bool Octree::exist(const Point & p){
    if(p.x < bottomLeft.x || p.x > bottomLeft.x + h || p.y < bottomLeft.y || p.y > bottomLeft.y + h || p.z < bottomLeft.z || p.z > bottomLeft.z + h ) return 0;

    if(nPoints == 0){
        return 0;
    }
    if(points != nullptr){
        if(p.x == points->x && p.y == points->y && p.z == points->z) return 1;
        return 0;
    }

    int child = 0;
    double childH = h / 2.0;
    if(p.x > bottomLeft.x + childH) child |= 1;
    if(p.y > bottomLeft.y + childH) child |= 2;
    if(p.z > bottomLeft.z + childH) child |= 4;

    return children[child]->exist(p);
}

void Octree::insert(const Point &p){
    if(p.x < bottomLeft.x || p.x > bottomLeft.x + h || p.y < bottomLeft.y || p.y > bottomLeft.y + h || p.z < bottomLeft.z || p.z > bottomLeft.z + h ) return;
    
    if(nPoints == 0){
        double childH = h / 2.0;
        for (int i = 0; i < 8; ++i) {
            double childX = (i & 1) ? bottomLeft.x + childH : bottomLeft.x;
            double childY = (i & 2) ? bottomLeft.y + childH : bottomLeft.y;
            double childZ = (i & 4) ? bottomLeft.z + childH : bottomLeft.z;
            children[i] = new Octree(Point(childX, childY, childZ), childH);
        }
        points = new Point(p.x,p.y,p.z);
        nPoints++;
        return;
    }
    else if(points != nullptr){
        if(p.x == points->x && p.y == points->y && p.z == points->z) return;
        Point * n_p = points;
        points = nullptr;
        int child = 0;
        double childH = h / 2.0;
        for (int i = 0; i < 8; ++i) {
            double childX = (i & 1) ? bottomLeft.x + childH : bottomLeft.x;
            double childY = (i & 2) ? bottomLeft.y + childH : bottomLeft.y;
            double childZ = (i & 4) ? bottomLeft.z + childH : bottomLeft.z;
            children[i] = new Octree(Point(childX, childY, childZ), childH);
        }
        if(n_p->x > bottomLeft.x + childH) child |= 1;
        if(n_p->y > bottomLeft.y + childH) child |= 2;
        if(n_p->z > bottomLeft.z + childH) child |= 4;
        children[child]->insert(*n_p);
    }
    int child = 0;
    double childH = h / 2.0;
    if(p.x > bottomLeft.x + childH) child |= 1;
    if(p.y > bottomLeft.y + childH) child |= 2;
    if(p.z > bottomLeft.z + childH) child |= 4;

    children[child]->insert(p);
    nPoints++;
    return;
}

Point Octree::find_closest( const Point &p) const{
    if(p.x < bottomLeft.x || p.x > bottomLeft.x + h || p.y < bottomLeft.y || p.y > bottomLeft.y + h || p.z < bottomLeft.z || p.z > bottomLeft.z + h ) return Point(0,0,0);
    if(points != nullptr){
        if(p.x == points->x && p.y == points->y && p.z == points->z) return p;
        return Point(0,0,0);
    }

    int child = 0;
    double childH = h / 2.0;
    if(p.x > bottomLeft.x + childH) child |= 1;
    if(p.y > bottomLeft.y + childH) child |= 2;
    if(p.z > bottomLeft.z + childH) child |= 4;

    Point k = children[child]->find_closest(p);

    if(k.x == 0 && k.y == 0 && k.z == 0){
        return Point(0,0,0);
    }

    double dist = 1e6;
    for(int i = 0; i < 8; i++){
        if(children[i]->points != nullptr){
            double ndist = sqrt(pow((p.x - children[i]->points->x),2) + pow((p.y - children[i]->points->y),2) + pow((p.z - children[i]->points->z),2));
            if(ndist < dist){
                k = Point(children[i]->points->x, children[i]->points->y, children[i]->points->z);
                dist = ndist;
            }
        }
    }
    return k;
}

void Octree::VTK(){
    if(points == nullptr && nPoints == 0){
        return;
    }
    if(points != nullptr){
        cubos.push_back(Cubo(bottomLeft.x,bottomLeft.y,bottomLeft.z,h));
        return;
    }

    for(int i = 0; i < 8; i++){
        children[i]->VTK();
    }
    return;
}

void Insercion_Datos(){
    ifstream archivo(NOMBRE_ARCHIVO);
    string linea;
    char delimitador = ',';
    double altura;
    double mxx = -1e6, mxy = -1e6, mxz = -1e6;
    double mnx = 1e6, mny = 1e6, mnz = 1e6;
    while(getline(archivo,linea)){

        stringstream stream(linea);
        string x, y, z;
        getline(stream, x, delimitador);
        getline(stream, y, delimitador);
        getline(stream, z, delimitador);
        double x_;
        istringstream(x) >> x_;
        double y_;
        istringstream(y) >> y_;
        double z_;
        istringstream(z) >> z_;
        mxx = max(mxx, x_);
        mxy = max(mxy,y_);
        mxz = max(mxz,z_);
        mnx = min(mnx,x_);
        mny = min(mny,y_);
        mnz = min(mnz,z_);
        puntos.push_back(Point(x_,y_,z_));
    }
    archivo.close();
    Point k(mnx,mny,mnz);
    altura = max((mxx-mnx),max((mxy-mny),(mxz-mnz)));
    Octree tree(k,altura);
    for(int i = 0; i < puntos.size(); i++){
        tree.insert(Point(puntos[i].x,puntos[i].y,puntos[i].z));
    }
    tree.VTK();
    return;
}

int main(int, char *[])
{
    Insercion_Datos();
    // Crear un renderizador y una ventana de renderizado
    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->AddRenderer(renderer);

    // Crear una ventana de renderizado interactiva
    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    renderWindowInteractor->SetRenderWindow(renderWindow);
    for(int i = 0; i < cubos.size(); i++){

        // Crear un objeto vtkCubeSource para generar el cubo
        vtkSmartPointer<vtkCubeSource> cubeSource = vtkSmartPointer<vtkCubeSource>::New();

        // Configurar las dimensiones del cubo basado en la altura
        cubeSource->SetBounds(cubos[i].x, cubos[i].x + cubos[i].h, cubos[i].y, cubos[i].y + cubos[i].h, cubos[i].z, cubos[i].z + cubos[i].h);


        // Crear un mapper y un actor para el cubo
        vtkSmartPointer<vtkPolyDataMapper> cubeMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        cubeMapper->SetInputConnection(cubeSource->GetOutputPort());

        vtkSmartPointer<vtkActor> cubeActor = vtkSmartPointer<vtkActor>::New();
        cubeActor->SetMapper(cubeMapper);

        // Agregar el actor al renderizador
        renderer->AddActor(cubeActor);
    }
    // Renderizar la escena
    renderWindow->Render();

    // Iniciar el bucle de interacción
    renderWindowInteractor->Start();

    return EXIT_SUCCESS;
}