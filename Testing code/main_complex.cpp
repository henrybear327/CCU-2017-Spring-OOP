#include <bits/stdc++.h>

using namespace std;

class Sample
{
	public:
	Sample(const char* string);
	~Sample();
	void output();
	private:
	const char* string;
};

Sample::Sample(const char* string): string(string)
{
	cout << "Constructor called" << endl;
}

Sample::~Sample()
{
	cout << "Destructor called" << endl;
}

void Sample::output()
{
	printf("%s\n", string);
}

int main()
{
	int feet = 15000;
	printf("%f\n", 5000 * (feet / 5280.0));
	printf("%d\n", 5000 * (feet / 5280));
	printf("%f\n", 5000.0 * (feet / 5280));
	
	const char* str = "Hello!";
	Sample s(str);
	s.output();
	
	const char *str1 = "Bye!";
	s = Sample(str1);
	s.output();

	cout << "Hahaha" << endl;

	return 0;
}
