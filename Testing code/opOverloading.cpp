#include <bits/stdc++.h>

using namespace std;

class Money
{
	public:
	Money(int m);
	int getMoney() const;
	void setMoney(int m);
	void output();
	const Money operator+(const Money& others) const;
	friend const Money operator-(const Money& a, const Money& b);
	friend const Money operator-(const Money& a);

	friend bool operator==(const Money& a, const Money& b);
	Money operator++(); // no starting, ending const
	Money operator++(int); // no starting, ending const

	friend ostream& operator<<(ostream& cout, const Money& others); //must be friend?
	friend istream& operator>>(istream& in, Money& others);//must be friend?
	
	void operator=(const Money& others); // must be member func, no ending const

	// support lvalue -> use ref
	int& operator[](int index);
	private:
	int val;
};

Money::Money(int m)
{
	val = m;
}

int Money::getMoney() const
{
	return val;
}

void Money::setMoney(int m)
{
	val = m;
}

void Money::output()
{
	printf("output = %d\n", val);
}

const Money Money::operator+(const Money& others) const
{
	return Money(val + others.getMoney());
}

const Money operator-(const Money& a, const Money& b)
{
	return Money(a.val - b.val);
}

const Money operator-(const Money& a)
{
	return Money(a.val * -1);
}

bool operator==(const Money& a, const Money& b)
{
	return a.getMoney() == b.getMoney();
}

void Money::operator=(const Money& others)
{
	printf("=\n");
	val = others.val;
}
/*
const Money operator+(const Money& a, const Money& b)
{
	return Money(a.getMoney() + b.getMoney());
}

const Money operator-(const Money& a, const Money& b)
{
	return Money(a.getMoney() - b.getMoney());
}

const Money operator-(const Money& a)
{
	return Money(a.getMoney() * -1);
}

bool operator==(const Money& a, const Money& b)
{
	return a.getMoney() == b.getMoney();
}
*/

int& useless(int &var)
{
	return var;
}

ostream& operator<<(ostream& cout, const Money& others)
{
	return cout << others.getMoney();
}

istream& operator>>(istream& in, Money& others)
{
	int tmp;
	in >> tmp;
	others.val = tmp;
	return in;
}

Money Money::operator++()
{
	val += 1;
	return Money(val);
}

Money Money::operator++(int)
{
	val += 1;
	return Money(val - 1);
}

int& Money::operator[](int index)
{
	printf("index = %d\n", index);
	return val;
}

int main()
{
	Money obj1(10), obj2(200);
	obj1.output();
	obj1.setMoney(100);
	obj1.output();

	printf("%d\n", (obj1 + obj2).getMoney());
	printf("%d\n", (obj1 - obj2).getMoney());
	printf("%d\n", obj1 == obj2);
	printf("%d\n", (-obj1).getMoney());

	printf("%d\n", (obj1 + obj2 + obj1).getMoney());

	int var = 10;
	printf("%d\n", var);
	useless(var) = 5;
	printf("%d\n", var);

	cout << obj1 << " " << obj2 << endl;

	cin >> obj1 >> obj2;
	cout << obj1 << " " << obj2 << endl;
	cout << &obj1 << " " << &obj2 << endl;
	obj1 = obj2;
	cout << obj1 << " " << obj2 << endl;
	cout << &obj1 << " " << &obj2 << endl;

	cout << ++obj1 << endl;
	cout << obj1++ << endl;
	cout << obj1 << endl;

	cout << obj1[10] << endl;
	obj1[10] = 10;
	cout << obj1[10] << endl;

	return 0;
}
