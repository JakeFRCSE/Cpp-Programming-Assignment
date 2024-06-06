#include <iostream>
#include <vector>
#define PI  3.14

using namespace std;

class Geom {
protected:
    int type;
public:
    enum {RECT, CIRCLE, SQUARE, POINT};
    Geom(int t): type(t) {}
    Geom() {}
    virtual float area()=0;
};

class Point: public Geom {
    float   x, y;
public:
    Point(float a, float b): Geom(POINT), x(a), y(b) {}
    Point() {}
    float   area() { return 0.0; }
    float   getx() { return x; }
    float   gety() { return y; }
};

class Circle: public Geom {
    Point   center;
    float   radius;
public:
    Circle(float x, float y, float r):
        Geom(CIRCLE), center(x,y), radius(r) {}
    Circle() {}
    float area() {return PI * radius * radius;} // complete it
};

class Rectangle: public Geom {
    Point   p1; // bottom left corner point
    Point   p2; // top right corner point
public:
    Rectangle(float x1, float y1, float x2, float y2):
        Geom(RECT), p1(x1,y1), p2(x2,y2) {}
    Rectangle() {}
    float area() {return (p2.getx() - p1.getx()) * (p2.gety() - p1.gety()); } // complete it
};

class Square: public Geom {
    Point   p;    // bottom left corner point
    float   side; // side length
public:
    Square(float x, float y, float s):
        Geom(CIRCLE), p(x,y), side(s) {}
    Square() {}
    float area() {return side * side;} // complete it
};


int main()
{
    int             numGeom;
    Geom            *geom;
    vector<Geom*>   geomVector;
    char            geomType;
    float temp1, temp2, temp3, temp4;
    Rectangle *myRectangle;
    Square *mySquare;
    Point *myPoint;
    Circle *myCircle;
    cin>> numGeom;

    for(int i=0;i<numGeom;i++) {
        cin>>geomType;
        switch(geomType) {
        case 'R' :
            cin>>temp1>>temp2>>temp3>>temp4;
            myRectangle = new Rectangle(temp1, temp2, temp3, temp4);
            geom = myRectangle;
            break;
        case 'S' :
            cin>>temp1>>temp2>>temp3;
            mySquare = new Square(temp1, temp2, temp3);
            geom = mySquare;
            break;
        case 'P' :
            cin>>temp1>>temp2;
            myPoint = new Point(temp1, temp2);
            geom = myPoint;
            break;
        default :
            cin>>temp1>>temp2>>temp3;
            myCircle = new Circle(temp1, temp2, temp3);
            geom = myCircle;
            // complete here
        }
        geomVector.push_back(geom);
    }

    float   maxArea=0.0;
    int     maxGeomIndex=0;

    for(int k=0;k<geomVector.size();k++) {
        if (maxArea < geomVector[k]->area()) {
            maxArea = geomVector[k]->area();
            maxGeomIndex = k;
        }
        // complete here
    }

    cout<<maxGeomIndex<<" "<<maxArea<<endl;

    return 0;
}
