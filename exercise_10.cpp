#include <iostream>
#define MaxStackSize  100
using namespace std;

template<typename T>
class StackTemplate
{
	T element[MaxStackSize];
	int top;
public:
	StackTemplate();
	bool isFulled();
	bool isEmpty();
	int  Push(const T element);
	T  Pop();
};

template<typename T>
StackTemplate<T>::StackTemplate() { top=-1; }

template<typename T>
bool StackTemplate<T>::isFulled()
{
    bool out;
    if (top >= MaxStackSize) {
        out = true;
    }
    else {
        out = false;
    }
    return out;
    // complete here
}

template<typename T>
bool StackTemplate<T>::isEmpty()
{
    bool out;
    if (top < 0) {
        out = true;
    }
    else {
        out = false;
    }
    return out;
    // complete here
}

template<typename T>
int  StackTemplate<T>::Push(const T element)
{
	if (isFulled()) return 0;

	top++;
	this->element[top]=element;
	return 1;
}

template<typename T>
T StackTemplate<T>::Pop()
{
	T element;

	if (isEmpty()) return 0;

	element=this->element[top--];
	return element;
}

int main() // modify main properly
{
    char    t;
    int     number;
    string  s;
    int     inti;
    float   floati;

    StackTemplate<string> stringS;
    StackTemplate<int> intS;
    StackTemplate<float> floatS;

    cin>>t;

    switch(t) {
        case 'S':
            cin>>number;
            for(int i=0;i<number;i++) {
                cin>>s;
                stringS.Push(s);
            }
        	while(!stringS.isEmpty()) cout << stringS.Pop() << endl;
            break;
        case 'I': // complete here exactly as case 'S'
            cin>>number;
            for(int i=0;i<number;i++) {
                cin>>inti;
                intS.Push(inti);
            }
        	while(!intS.isEmpty()) cout << intS.Pop() << endl;
            break;
        case 'F': // complete here
            cin>>number;
            for(int i=0;i<number;i++) {
                cin>>floati;
                floatS.Push(floati);
            }
        	while(!floatS.isEmpty()) cout << floatS.Pop() << endl;
            break;
        default: cout<<"No match\n";
            break;
    }

	return 0;
}
