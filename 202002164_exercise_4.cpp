#include<iostream>

using namespace std;


class Point{
private:

public:
    float x;
    float y;
    Point();
    Point(const Point&);
    Point operator+(float A);
    Point operator+(Point B);
    friend ostream& operator<<(ostream&, const Point&);
    friend istream& operator>>(istream&, Point&);
};

ostream& operator<<(ostream& os, const Point& p){
    os<<""<<p.x<<" "<<p.y<<"\n";
    return os;
}

istream& operator>>(istream& is, Point& p){
    is>>p.x>>p.y;
    return is;
}

Point::Point(const Point & rhs) {
    Point temp;
    temp.x = rhs.x; temp.y = rhs.y;
}

Point::Point(){
}

Point *temp0;
Point *temp2;

Point Point::operator+(Point op){
    Point temp;
    Point *op1;
    op1 = &op;

    temp.x = x + op1->x;
    temp.y = y + op1->y;

    return temp;
}



Point Point::operator+(float op){
    Point temp;

    temp.x = x + op;
    temp.y = y + op;

    return temp;
}

int main() {
    Point A, B, C;
    float D;
    cin>>A; cin>>B;
    C=A+B;
    cout<<C;
    cin>>D;
    C = C + D;
    cout<<C;
}
