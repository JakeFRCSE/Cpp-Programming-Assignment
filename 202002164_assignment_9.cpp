#include <queue>
#include <iostream>
#define  PI 3.14

using namespace std;

class Geometry {
    int     type;
public:
    enum {RECT, CIRCLE, SQUARE, POINT};
    Geometry(int t): type(t) {}
    Geometry() {}
    friend bool     operator==(const Geometry& a, const Geometry& b) {return (a == b);} // a==b if and only if a.area()==b.area()
    friend bool     operator<(const Geometry& a, const Geometry& b) {return !(a>b && a==b); } // a>b iff a.area()>b.area()
    friend bool     operator>(const Geometry& a, const Geometry& b) { return !(a<b && a==b); }
    virtual float   area()=0;
};


class Point: public Geometry {
    float   a, b;
public:
    Point(float x, float y): Geometry(POINT), a(x), b(y) {}
    Point() {}
    float   area() { return 0.0; }
    float   geta() { return a; }
    float   getb() { return b; }
};

class Circle: public Geometry {
    Point   center;
    float   radius;
public:
    Circle(float x, float y, float r):
        Geometry(CIRCLE), center(x,y), radius(r) {}
    Circle() {}
    float area() {return PI * radius * radius;}
};

class Rectangle: public Geometry {
    Point   p1; // bottom left corner point
    Point   p2; // top right corner point
public:
    Rectangle(float x1, float y1, float x2, float y2):
        Geometry(RECT), p1(x1,y1), p2(x2,y2) {}
    Rectangle() {}
    float area() {return (p2.geta() - p1.geta()) * (p2.getb() - p1.getb()); }
};

class Square: public Geometry {
    Point   p;    // bottom left corner point
    float   side; // side length
public:
    Square(float x, float y, float s):
        Geometry(CIRCLE), p(x,y), side(s) {}
    Square() {}
    float area() {return side * side;}
};

struct geomindex {
    Geometry* geom;
    int index;
    geomindex(Geometry* g, int i): geom(g), index(i) {}
};

struct compareArea {
    bool operator()(geomindex a, geomindex b) {
        return a.geom->area() < b.geom->area();
    }
};

int main() {
    Geometry            *geom;
    char            geomType;
    float temp1, temp2, temp3, temp4;
    priority_queue<geomindex, vector<geomindex>, compareArea>       geoms;
    vector<int> indices;
    int i = 0;
    while (true){
        cin>>geomType;
        if(cin.eof() == true) {
            break;
        }
        switch(geomType) {
        case 'R' :
            cin>>temp1>>temp2>>temp3>>temp4;
            geom = new Rectangle(temp1, temp2, temp3, temp4);
            break;
        case 'S' :
            cin>>temp1>>temp2>>temp3;
            geom = new Square(temp1, temp2, temp3);
            break;
        case 'P' :
            cin>>temp1>>temp2;
            geom = new Point(temp1, temp2);
            break;
        case 'C' :
            cin>>temp1>>temp2>>temp3;
            geom = new Circle(temp1, temp2, temp3);
            break;
        }
        geoms.emplace(geom, i);
        i++;

    }
    float check;
    check = geoms.top().geom->area();
    indices.push_back(geoms.top().index);
    geoms.pop();
    while (!geoms.empty()){
        if (check == geoms.top().geom->area()){
            geoms.pop();
        }
        else {
            check = geoms.top().geom->area();
            indices.push_back(geoms.top().index);
            geoms.pop();
        }
    }
    for (vector<int>::iterator it = indices.begin(); it != indices.end(); it++) {
        cout<<*it<<endl;
    }





}

