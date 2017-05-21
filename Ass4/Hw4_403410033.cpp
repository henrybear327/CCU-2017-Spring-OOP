/*
Chun-Hung Tseng
403410033
Computer Science and Information Technology
Junior year student
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

#define DEBUG 0

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
    BigInt(int *num, int dataSize);
    int *data;
    int dataSize;
    bool isNegative;
    string toString() const;
};

BigInt::BigInt()
{
// initialize to 0
#if DEBUG == 1
    cout << "BigInt() called" << endl;
#endif

    isNegative = false;
    dataSize = 1;
    data = new int[dataSize];

    data[0] = 0;
}

BigInt::BigInt(int num)
{
#if DEBUG == 1
    cout << "BigInt(int num) called" << endl;
#endif

    if (num < 0) {
        isNegative = true;
        num *= -1;
    } else
        isNegative = false;

    int tmp = num;
    dataSize = 0;
    while (tmp > 0) {
        dataSize++;
        tmp /= 10;
    }

    tmp = num;
    data = new int[dataSize];
    for (int i = 0; tmp > 0; i++, tmp /= 10)
        data[i] = tmp % 10;
}

BigInt::BigInt(int *num, int dataSize)
{
#if DEBUG == 1
    cout << "BigInt(int num[], int dataSize) called" << endl;
#endif

    this->dataSize = dataSize;
    data = new int[dataSize];
    for (int i = 0; i < dataSize; i++)
        this->data[i] = num[i];
}

BigInt::BigInt(string num)
{
#if DEBUG == 1
    cout << "BigInt(string num) called" << endl;
#endif
    dataSize = num.length();
    data = new int[dataSize];
    for (int i = num.length() - 1, j = 0; i >= 0; i--, j++)
        data[j] = num[i] - '0';
}

string BigInt::toString() const
{
    int firstNonZero = dataSize - 1;
    while (firstNonZero > 0 && data[firstNonZero] == 0)
        firstNonZero--;

    string res = "";
    for (int i = firstNonZero; i >= 0; i--)
        res += data[i] + '0';
    return res;
}

ostream &operator<<(ostream &out, const BigInt &other)
{
    cout << other.toString();

    return out;
}

const BigInt BigInt::operator+(const BigInt &other) const
{
    int mx = max(this->dataSize, other.dataSize);

    int *sum = new int[mx + 1];
    memset(sum, 0, sizeof(int) * (mx + 1));
    for (int i = 0; i < mx; i++) {
        if (i < this->dataSize)
            sum[i] += this->data[i];
        if (i < other.dataSize)
            sum[i] += other.data[i];

        sum[i + 1] += sum[i] / 10;
        sum[i] %= 10;
    }

    BigInt res = BigInt(sum, mx + 1);
    delete[] sum;
    return res;
}

const BigInt BigInt::operator-(const BigInt &other) const
{
    int mx = max(this->dataSize, other.dataSize);

    int *res = new int[mx];
    memset(res, 0, sizeof(int) * (mx));

    // TODO: handle small - big
    int borrow = 0;
    for (int i = 0; i < mx; i++) {
        int current = borrow;
        borrow = 0;

        if (i < this->dataSize)
            current += this->data[i];
        if (i < other.dataSize)
            current -= other.data[i];

        if (current < 0) {
            borrow = -1;
            current += 10;
        }

        res[i] = current;
    }

    BigInt ret = BigInt(res, mx);
    delete[] res;
    return ret;
}

BigInt &BigInt::operator=(const BigInt &other)
{
#if DEBUG == 1
    cout << "operator=(const BigInt &other) called" << endl;
#endif

    delete[] data;

    dataSize = other.dataSize;
    data = new int[dataSize];

    for (int i = 0; i < dataSize; i++)
        data[i] = other.data[i];

    return *this;
}

BigInt::BigInt(const BigInt &other)
{
#if DEBUG == 1
    cout << "BigInt(const BigInt &other) called" << endl;
#endif

    dataSize = other.dataSize;
    data = new int[dataSize];

    for (int i = 0; i < dataSize; i++)
        data[i] = other.data[i];
}

BigInt::~BigInt()
{
#if DEBUG == 1
    cout << "BigInt object with value " << *this << " is being deleted" << endl;
#endif

    delete[] data;
}

int main()
{
    BigInt num1;
    BigInt num2(100);
    BigInt num3("1000");

    BigInt sum = num2 + num3;
    cout << num2 << " + " << num3 << " = " << sum << endl;

    BigInt a("314159265358979323846264338327950288419716939937510"), c(a);
    BigInt *b = new BigInt(1618033988);
    c = a + *b;
    cout << a << " + " << *b << " = " << c << endl;
    c = a - *b;
    cout << a << " - " << *b << " = " << c << endl;

    return 0;
}
