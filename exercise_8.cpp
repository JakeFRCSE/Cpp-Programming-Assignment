#include <iostream>
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
protected:
    float   a, b;
public:
    Point(float x, float y): Geom(POINT), a(x), b(y) {}
    Point() {}
    float getA() {return a;}
    float getB() {return b;}
    float   area() { return 0.0; }
};

class Circle: public Geom {
    Point   center;
    float   radius;
public:
    Circle(float x, float y, float r):
        Geom(CIRCLE), center(x,y), radius(r) {}
    Circle() {}
    float area() { return PI*radius*radius; }
};

class Rectangle: public Geom {
    Point   p1; // bottom left corner point
    Point   p2; // top right corner point
public:
    Rectangle(float p1x, float p1y, float p2x, float p2y): Geom(RECT), p1(p1x, p1y), p2(p2x, p2y) {} // implement it
    Rectangle() {};
    float area() {return (p2.getA() - p1.getA()) * (p2.getB() - p1.getB());} // implement here
};

class Square: public Geom {
    Point   p;    // bottom left corner point
    float   side; // side length
public:
    Square(float px, float py, float side): Geom(SQUARE), p(px, py), side(side) {}// implement here
    Square() {}
    float area() {return side * side;}
};


int main()
{
    int     numGeom;
    cin>> numGeom;
    Geom    *geom;
    char shape;
    Rectangle *myRectangle;
    Square *mySquare;
    Point *myPoint;
    Circle *myCircle;
    float temp1, temp2, temp3, temp4;
    for(int i=0;i<numGeom;i++) {
        cin>>shape;
        switch(shape){
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
            case 'C' :
                cin>>temp1>>temp2>>temp3;
                myCircle = new Circle(temp1, temp2, temp3);
                geom = myCircle;
                break;
        }
        // complete here

        cout<<geom->area()<<endl;

    }

    return 0;
}
