#include <iostrea>
#define PI  3.14

using namespace std;

//This function finds the closest point of x-coordinate or y-coordinate of rectangle
//a and b is boundary coordinate of rectangle and c is center coordinate
float closest(float a, float b, float c) {
    if (c <= a) {
        return a;
    }
    else if (a < c && c < b) {
        return c;
    }
    else if (b <= c) {
        return b;
    }
    return -1;
}


//define Geom class
class Geom {
protected:
    int nmbr; //variable to print out the answer
    int type;
public:
    enum {RECT, CIRCLE, SQUARE, POINT};
    Geom(int t, int n): type(t), nmbr(n) {}
    Geom() {}
    // Functions needed
    int getType() {return type;}
    virtual float getA() {return -1.0;} // get x-coordinate
    virtual float getB() {return -1.0;} // get y-coordinate
    virtual float getRadius() {return -1.0;} // get radius
    virtual float getP2A() {return -1.0;} // get second x-coordinate of rectangle
    virtual float getP2B() {return -1.0;} // get second y-coordinate of rectangle
    virtual float getSide() {return -1.0;} // get length of edge of square
    virtual bool overlap(Geom **other) {cout<<"fail in Geom\n"; return false;} // check if the two geoms are overlapped
    friend ostream& operator<<(ostream& os, Geom *geom); // output operator
    int getNmbr() {return nmbr;} //get nmbr
};

//output operator
ostream& operator<<(ostream& os,Geom *geom) {
    cout<<(geom->nmbr + 1);
    return os;
}

//define Point class
class Point: public Geom {
    float   a, b;
public:
    Point(float x, float y, int n): Geom(POINT, n), a(x), b(y) {}
    Point() {}
    float getA() {return a;}
    float getB() {return b;}
};

//define Circle class
class Circle: public Geom {
    Point   center;
    float   radius;
public:
    Circle(float x, float y, float r, int n): Geom(CIRCLE, n), center(x, y, n), radius(r) {}
    Circle() {}
    float getA() {return center.getA();}
    float getB() {return center.getB();}
    float getRadius() {return radius;}
    bool overlap(Geom **other) {
        float dist = radius * radius;
        if ((*other)->getType() == RECT) { // compare circle and rectangle
            float closestA = closest((*other)->getA(), (*other)->getP2A(), getA()) - getA();
            float closestB = closest((*other)->getB(), (*other)->getP2B(), getB()) - getB();
            if (dist >= (closestA)* (closestA) + (closestB * (closestB))) {
                return true;
            }
            return false;
        }
        else if ((*other)->getType() == SQUARE){ // compare circle and square
            float closestA = closest((*other)->getA(), (*other)->getA() + (*other)->getSide(), getA()) - getA();
            float closestB = closest((*other)->getB(), (*other)->getB() + (*other)->getSide(), getB()) - getB();
            if (dist >= (closestA)* (closestA) + (closestB) * (closestB)) {
                return true;
            }
            return false;
        }
        else if ((*other)->getType() == CIRCLE) { // compare circle and circle
            float dist_x = getA() - (*other)->getA();
            float dist_y = getB() - (*other)->getB();
            float dist_xy = (dist_x * dist_x) + (dist_y * dist_y);
            if (dist >= dist_xy) {
                return true;
            }
            return false;
        }
        return false;
    }
};

class Rectangle: public Geom {
    Point   p1; // bottom left corner point
    Point   p2; // top right corner point
public:
    Rectangle(float p1x, float p1y, float p2x, float p2y, int n): Geom(RECT, n), p1(p1x, p1y, n), p2(p2x, p2y, n) {} // implement it
    Rectangle() {}
    float getA() {return p1.getA();}
    float getB() {return p1.getB();}
    float getP2A() {return p2.getA();}
    float getP2B() {return p2.getB();}
    bool overlap(Geom **other) { // compare rectangle and rectangle
        if ((*other)->getType() == RECT) {
            if (getA() > (*other)->getP2A() ||
                getP2A() < (*other)->getA() ||
                getB() > (*other)->getP2B() ||
                getP2B() < (*other)->getB()
            ){
                return false;
            }
                return true;
        }
        else if ((*other)->getType() == SQUARE){ // compare  rectangle and square
            if (getA() > (*other)->getA() + (*other)->getSide() ||
                getP2A() < (*other)->getA() ||
                getB() > (*other)->getB() + (*other)->getSide() ||
                getP2B() < (*other)->getB()
            ){
                return false;
            }
                return true;
        }
        else if ((*other)->getType() == CIRCLE) { // compare rectangle  and circle
            Geom *newGeom;
            newGeom = this;
            return (*other)->overlap(&newGeom);
        }
        return false;
    }
};

class Square: public Geom {
    Point   p;    // bottom left corner point
    float   side; // side length
public:
    Square(float px, float py, float side, int n): Geom(SQUARE, n), p(px, py, n), side(side) {}// implement here
    Square() {}
    float getA() {return p.getA();}
    float getB() {return p.getB();}
    float getSide() {return side;}
    bool overlap(Geom **other) {
        if ((*other)->getType() == SQUARE) { // compare square  and square
            if (getA() > (*other)->getA() + (*other)->getSide() ||
                getA() + getSide() < (*other)->getA() ||
                getB() > (*other)->getB() + (*other)->getSide() ||
                getB() + getSide() < (*other)->getB()
            ){
                return false;
            }
                return true;
        }
        else if ((*other)->getType() == RECT){ // compare square  and rectangle
            Geom *newGeom;
            newGeom = this;
            return (*other)->overlap(&newGeom);
        }
        else if ((*other)->getType() == CIRCLE) { // compare square  and circle
            Geom *newGeom;
            newGeom = this;
            return (*other)->overlap(&newGeom);
        }
        return false;
    }
};


int main()
{
    int     numGeom;
    cin >> numGeom;
    Geom    *queryGeom;
    Geom    *geoms[numGeom];

    char shape;
    Rectangle *myRectangle;
    Square *mySquare;
    Circle *myCircle;
    float temp1, temp2, temp3, temp4;

    //input part
    for(int i=0;i<numGeom;i++) {
        cin>>shape;
        switch(shape){
            case 'R' :
                cin>>temp1>>temp2>>temp3>>temp4;
                myRectangle = new Rectangle(temp1, temp2, temp3, temp4, i);
                geoms[i] = myRectangle;
                break;
            case 'S' :
                cin>>temp1>>temp2>>temp3;
                mySquare = new Square(temp1, temp2, temp3, i);
                geoms[i] = mySquare;
                break;
            default :
                cin>>temp1>>temp2>>temp3;
                myCircle = new Circle(temp1, temp2, temp3, i);
                geoms[i] = myCircle;
        }
    }

    //input for queryGeom
    cin>>shape;
    switch(shape){
        case 'R' :
            cin>>temp1>>temp2>>temp3>>temp4;
            myRectangle = new Rectangle(temp1, temp2, temp3, temp4, numGeom);
            queryGeom = myRectangle;
            break;
        case 'S' :
            cin>>temp1>>temp2>>temp3;
            mySquare = new Square(temp1, temp2, temp3, numGeom);
            queryGeom = mySquare;
            break;
        default :
            cin>>temp1>>temp2>>temp3;
            myCircle = new Circle(temp1, temp2, temp3, numGeom);
            queryGeom = myCircle;
    }

    //output part
    for(int i=0; i<numGeom;i++){
        if(queryGeom->overlap(&geoms[i])==true) {
            cout<<geoms[i]<<endl;
            return 0; // end of main
        }
    }
    cout<<-1;
    return 0;
}
