#include<iostream>

using namespace std;

class Complex {
        public:
    float real;
    float im;
    Complex operator+(Complex &A);
    Complex operator*(Complex &B);
    Complex operator*(float &C);
    friend istream& operator>>(istream&, Complex&);
    friend ostream& operator<<(ostream&, const Complex&);
};

istream& operator>>(istream& is, Complex& p){
    is>>p.real>>p.im;
    return is;
}

ostream& operator<<(ostream& os, const Complex& p){
    os<<""<<p.real<<" "<<p.im<<"\n";
    return os;
}

Complex Complex::operator+(Complex &op){
    Complex temp;
    temp.real = 0;
    temp.im = 0;

    temp.real = real + op.real;
    temp.im = im + op.im;

    return temp;
}

Complex Complex::operator*(Complex &op){
    Complex temp;
    temp.real = 0;
    temp.im = 0;

    temp.real = (real * op.real);
    temp.im = (im * op.im);

    return temp;
}

Complex Complex::operator*(float &op){
    Complex temp;
    temp.real = 0;
    temp.im = 0;

    temp.real = real * op;
    temp.im = im * op;

    return temp;
}

int main() {
 Complex A,B,C;
 float D;
 cin>>A; cin>>B;
 C=A+B;
 cout<<C;
 C=A*B;
 cout<<C;
 cin>>D;
 C=C*D;
 cout<<C;
}
