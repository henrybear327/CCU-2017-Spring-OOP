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



    return 0;
}
