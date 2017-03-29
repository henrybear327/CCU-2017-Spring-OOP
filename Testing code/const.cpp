#include <bits/stdc++.h>

using namespace std;

// static var: a variable that is shared by all objects of that class


class Bank // basically, this is the c equiv of java interface
{
	public:
	Bank(int dollar);
	void output() const; // protect calling obj
	void output1();
	void inlineFunction()
	{
		printf("I am inline function\n");
	}
	private:
	int amount;
};

Bank::Bank(int dollar)
{
	amount = dollar;
}

void Bank::output() const // const must be added
{
	// amount = 10; // error
	printf("1 = %d\n", amount);
}

void Bank::output1() 
{
	// amount = 10; // error
	printf("2 = %d\n", amount);
}

void welcome(const Bank& b)
{
	b.output();
	// b.output1(); // due to const protection, output1() needs to be const protected, too
}

int main()
{
	Bank b(100);
	b.output();
	b.inlineFunction();

	welcome(b);

	return 0;
}
