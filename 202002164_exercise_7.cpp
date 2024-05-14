#include <iostream>

using namespace std;

class IntegerSet {
private:
    int     numElements,maxNumElements;
    int     *elements;
public:
    IntegerSet(int max) {
        numElements=0;
        maxNumElements=max;
        elements=new int[max];
    }

    IntegerSet(): numElements(0), maxNumElements(100) {}
    ~IntegerSet(); // to implement
    void swap_ahead(int);
    int     operator+(int);  // add an integer element, duplication is allowed
    int     operator-(int);  // remove an integer element
    int     operator[](int);  // search a value, return the number of elements matched with key
    friend ostream& operator<<(ostream&, IntegerSet&); // given as below
};

IntegerSet::~IntegerSet() {
    delete[] elements;
}

int IntegerSet::operator+(int a){
    elements[numElements] = a; // put the number into the array
    numElements++; // increase numElements
    return numElements;
}
//need to check again
int IntegerSet::operator-(int a){
    int find_index = 0;
    for (int i = 0; i < numElements; i++) {
        if (elements[i] == a) { //if the element is equal to a
            find_index = i; // set find_index as the index
            swap_ahead(find_index); // push into the last element
            elements[numElements - 1] = 0; // the last element is deleted
            numElements--; // decrease numElements
            break;
        }
    }
    return numElements;
}

void IntegerSet::swap_ahead(int find_index) {
    int temp;
    for (int i = find_index; i < numElements - 1; i++) {
        temp = elements[i];
        elements[i] = elements[i + 1];
        elements[i + 1] = temp;
    }
}

int IntegerSet::operator[](int a){
    // search a in the IntegerSet, return the number of elements matched with a
    int cnt = 0;
    for (int i = 0; i < numElements; i++) {
        if(elements[i] == a) {
            cnt++;
        }
    }
    return cnt; // modify it properly
}

ostream& operator<<(ostream& os, IntegerSet& set) {

  for(int i=0;i<set.numElements;i++) cout<<set.elements[i]<<endl;
  return os;

}

int main()
{
    IntegerSet  mySet(100);
    int         numLines;
    char        op;
    int temp;
    cin>>numLines;
    for(int i=0;i<numLines;i++) {
        cin>>op;
        switch(op) {
            case '+': cin>>temp; cout<<mySet+temp<<endl; break;
            case '-': cin>>temp; cout<<mySet-temp<<endl; break;
            case '=': cout<<mySet<<endl; break;
            default: cin>>temp; cout<<mySet[temp]<<endl;
        }

    }

    return 0;
}
