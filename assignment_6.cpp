#include<iostream>
using namespace std;

class Student{
public:
    static int curr_num;
    unsigned ID;
    string name;
    Student();
    Student(const Student&);
    ~Student();
};

int Student::curr_num = 0;

Student::Student() {
    curr_num++;
    cout<<curr_num<<endl;
}

Student::Student(const Student& student){
    curr_num++;
    cout<<curr_num<<endl;
}

Student::~Student(){
    curr_num--;
    cout<<curr_num<<endl;
}

class Lecture{
public:
    string prof;
    Student *students;
    int number;
    Lecture(int);
    Lecture(const Lecture&);
    ~Lecture();
    unsigned operator[](string);
};

Lecture::Lecture(int n) {
    students = new Student[n];
    number = n;
}

Lecture::Lecture(const Lecture&lecture) {
}

Lecture::~Lecture(){
    delete[] students;
}

unsigned Lecture::operator[](string a) {
    for (int i = 0; i < number; i++) {
        if (students[i].name == a){
            return students[i].ID;
        }
    }
    return 0;
}

int main() {
    int n;
    cin>>n;
    Lecture lecture(n);
    for (int i = 0; i < n; i++) {
        cin>>lecture.students[i].ID>>lecture.students[i].name;
    }
    string key_name;
    cin>>key_name;
    cout<<lecture[key_name]<<endl;
}

