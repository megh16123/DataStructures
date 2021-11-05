#include <iostream>
using namespace std;

class A {
public:
	int a;
	A() 
	{
		a = 10;
	}
};

class B : public virtual A {
    int data;
};

class C : public virtual A {
int data1;
};

class D : public B, public C {
int data2;
};

int main()
{
	D object; 
	cout << "Data of A = " << object.a << endl;

	return 0;
}
