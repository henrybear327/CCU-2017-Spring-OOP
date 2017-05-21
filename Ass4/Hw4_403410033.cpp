/*
Chun-Hung Tseng
403410033
Computer Science and Information Technology
Junior year student
*/

#include <iostream>

#define DEBUG 1

using namespace std;

class BigInt
{
public:
    BigInt();
    BigInt(int num);
    BigInt(string num);

    // + - <<
    const BigInt operator+(const BigInt &other) const;
    const BigInt operator-(const BigInt &other) const;
    friend ostream &operator<<(ostream &out, const BigInt &other);

    // assignment, copy constructor, destructor
    BigInt &operator=(const BigInt &other);
    BigInt(const BigInt &other);
    ~BigInt();

private:
    int *data;
	int dataSize;
	string toString() const;
};

BigInt::BigInt()
{
    // initialize to 0
	dataSize = 1;
    data = new int[dataSize];

    data[0] = 0;
}

string BigInt::toString() const
{	
	string res = "";
	for(int i = dataSize - 1; i >= 0; i--)
		res += data[i] + '0';
	return res;
}

ostream& operator<<(ostream &out, const BigInt &other)
{
	cout << other.toString();

	return out;
}	

BigInt::~BigInt()
{
#if DEBUG == 1
	cout << "BigInt object with value " << *this << " is being deleted"  << endl;
#endif

	delete [] data;
}

int main()
{
    BigInt num1;

    return 0;
}
