/*
Chun-Hung Tseng
403410033
Department of Computer Science
Junior year student
*/
#include <iostream>
#include <cstdlib>

using namespace std;

#define DEBUG 1

// define terminal color
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"
#define NONE "\x1B[0m"

class Rational
{
	public:
	Rational(); 
	Rational(int numerator, int denominator);
	Rational(int wholeNumber);

	int getNumerator() const;
	int getDenominator() const;

	friend const Rational operator*(const Rational& a, const Rational& b);
	friend const Rational operator/(const Rational& a, const Rational& b);
	friend bool operator==(const Rational& a, const Rational& b);
	friend ostream& operator<<(ostream &out, const Rational& a);
	friend istream& operator>>(istream &in, Rational& a);

	bool operator<(const Rational &b) const;
	bool operator<=(const Rational &b) const;
	bool operator>(const Rational &b) const;
	bool operator>=(const Rational &b) const;
	int operator[](int index) const;

	private:
	int numerator;
	int denominator;
	void normalize();
	int gcd(int x, int y);
};

Rational::Rational()
{
	numerator = 0;
	denominator = 1;
}

Rational::Rational(int numerator, int denominator)
{
	this->numerator = numerator;
	this->denominator = denominator;
	normalize();
}

Rational::Rational(int wholeNumber)
{
	numerator = wholeNumber;
	denominator = 1;
}

int Rational::gcd(int x, int y)
{
	x = abs(x);
	y = abs(y);
	return x == 0 ? y : gcd(y % x, x);
}

void Rational::normalize()
{
	if(denominator < 0) {
		denominator *= -1;
		numerator *= -1;
	}

	int g = gcd(numerator, denominator);
	numerator = numerator / g;
	denominator = denominator / g;
}

int Rational::getNumerator() const
{
	return numerator;
}

int Rational::getDenominator() const
{
	return denominator;
}

const Rational operator+(const Rational& a, const Rational& b)
{
	int denominator = a.getDenominator() * b.getDenominator();
	int numerator = a.getNumerator() * b.getDenominator() + b.getNumerator() * a.getDenominator();

	return Rational(numerator, denominator);
}

const Rational operator-(const Rational& a, const Rational& b)
{
	int denominator = a.getDenominator() * b.getDenominator();
	int numerator = a.getNumerator() * b.getDenominator() - b.getNumerator() * a.getDenominator();

	return Rational(numerator, denominator);
}

const Rational operator-(const Rational& a)
{
	int denominator = a.getDenominator();
	int numerator = a.getNumerator();

	return Rational(numerator * -1, denominator);
}

const Rational operator*(const Rational& a, const Rational& b)
{
	int numerator = a.numerator * b.numerator;
	int denominator = a.denominator * b.denominator;

	return Rational(numerator, denominator);
}

const Rational operator/(const Rational& a, const Rational& b)
{
	// (p / q) / (x / y) = (py / qx)
	int numerator = a.numerator * b.denominator;
	int denominator = a.denominator * b.numerator;

	return Rational(numerator, denominator);
}

bool operator==(const Rational& a, const Rational& b)
{
	return (a.numerator == b.numerator) && (a.denominator == b.denominator);
}

ostream& operator<<(ostream &out, const Rational& a)
{
	cout << a.getNumerator() << "/" << a.getDenominator();

	return out;
}

istream& operator>>(istream &in, Rational& a)
{
	int newNumerator, newDenominator;
	in >> newNumerator >> newDenominator;
	
	a.numerator = newNumerator;
	a.denominator = newDenominator;
	a.normalize();

	return in;
}

bool Rational::operator<(const Rational &b) const
{
	int numeratorA = numerator * b.denominator;
	int numeratorB = b.numerator * denominator;

	return numeratorA < numeratorB;
}

bool Rational::operator<=(const Rational &b) const
{
	int numeratorA = numerator * b.denominator;
	int numeratorB = b.numerator * denominator;

	return numeratorA <= numeratorB;
}

bool Rational::operator>(const Rational &b) const
{
	int numeratorA = numerator * b.denominator;
	int numeratorB = b.numerator * denominator;

	return numeratorA > numeratorB;
}

bool Rational::operator>=(const Rational &b) const
{
	int numeratorA = numerator * b.denominator;
	int numeratorB = b.numerator * denominator;

	return numeratorA >= numeratorB;
}

int Rational::operator[](int index) const
{
	if(index == 0)
		return numerator;
	else
		return denominator;
}

int main()
{
	
#if DEBUG == 1
	cout << CYAN "Testing init..." << endl;
	
	Rational default1, default2(100, -400), default3(3);
	
	cout << default1.getNumerator() << "/" << default1.getDenominator() << endl;
	cout << default2.getNumerator() << "/" << default2.getDenominator() << endl;
	cout << default3.getNumerator() << "/" << default3.getDenominator() << endl;

	cout << NONE << endl;
#endif

#if DEBUG == 1
	cout << CYAN "Testing overloading. Please enter two rationals:" << endl;
	
	Rational a(2, 3), b(3, 5);
	
	cin >> a;
	cin >> b;
	
	cout << "The rationals you entered... " << endl;
	cout << a << endl;
	cout << b << endl;
	cout << endl;
	
	cout << "a + b" << endl;
	cout << a + b << endl;
	cout << "a - b" << endl;
	cout << a - b << endl;
	cout << "a * b" << endl;
	cout << a * b << endl;
	cout << "a / b" << endl;
	cout << a / b << endl;
	cout << "-a" << endl;
	cout << -a << endl;
	cout << "-b" << endl;
	cout << -b << endl;
	
	cout << "a == b" << endl;
	string res = (a == b) ? "True" : "False";
	cout << res << endl;
	cout << "a == a" << endl;
	res = (a == a) ? "True" : "False";
	cout << res << endl;
	cout << "a < b" << endl;
	res = (a < b) ? "True" : "False";
	cout << res << endl;
	cout << "a <= b" << endl;
	res = (a <= b) ? "True" : "False";
	cout << res << endl;
	cout << "a > b" << endl;
	res = (a > b) ? "True" : "False";
	cout << res << endl;
	cout << "a >= b" << endl;
	res = (a >= b) ? "True" : "False";
	cout << res << endl;

	cout << "a[0] a[1]" << endl;
	cout << a[0] << " " << a[1] << endl;
	cout << "b[0] b[1]" << endl;
	cout << b[0] << " " << b[1] << endl;

	cout << NONE << endl;
#endif


    return 0;
}
