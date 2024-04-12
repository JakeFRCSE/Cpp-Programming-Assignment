#include<iostream>
using namespace std;

class Complex {
    int real;
    int im;
public:
    Complex(int, int);
    Complex(const Complex&);
    void operator+(Complex);
};

Complex::Complex(int a, int b) {
    real = a;
    im = b;
    cout<<"Constructor"<<" "<<real<<" "<<im<<endl;
}

Complex::Complex(const Complex &c) {
    real = c.real;
    im = c.im;
    cout<<"Copy"<<endl;
}

void Complex:: operator+(Complex d) {
    cout<<"+"<<" "<<real + d.real<<" "<<im + d.im<<endl;
}

int main(){
    int a, b, c, d;
    cin>>a>>b;
    Complex complex1(a, b);
    cin>>c>>d;
    Complex complex2(c, d);
    complex1+complex2;
}
