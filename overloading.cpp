#include <iostream>

using namespace std;

// function overloading
// same function name, different number of param OR at least one different param type
// different return type, modifier on param (call by value/reference) does not help distinguish functions (understand function signature will help) 
double avg(double a, double b)
{	
	return (a + b) / 2.0;
}

int avg(int a, int b)
{
	return (a + b) / 2;
}

void f(int a, double b)
{
	cout << "int " << a << " double " << b << endl; 
}

void f(double a, int b)
{
	cout << "double " << a << " int " << b << endl;
}

int main()
{
	cout << avg(2, 4) << endl;
	cout << avg(2.1, 4.5) << endl;

	f(32, 31.3);
	f(30.1, 33);
	// f(32, 33); // error

	return 0;
}
