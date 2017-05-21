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

/*
   0 normal mode
   1 default testing
   2 debug print
 */
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

    string toString() const;
    string toCmpString(int n) const;

private:
    BigInt(int *num, int dataSize, bool isNegative);
    int *data;
    int dataSize;
    bool isNegative;
    BigInt negate() const;
};

BigInt::BigInt()
{
#if DEBUG == 2
    cout << "BigInt() called" << endl;
#endif

    // initialize to 0
    isNegative = false;
    dataSize = 1;
    data = new int[dataSize];

    data[0] = 0;
}

BigInt::BigInt(int num)
{
#if DEBUG == 2
    cout << "BigInt(int num) called" << endl;
#endif

    if (num < 0) {
        isNegative = true;
        num *= -1;
    } else
        isNegative = false;

    if (num == 0) {
        // initialize to 0
        isNegative = false;
        dataSize = 1;
        data = new int[dataSize];

        data[0] = 0;
        return;
    }

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

BigInt::BigInt(int *num, int dataSize, bool isNegative)
{
#if DEBUG == 2
    cout << "BigInt(int num[], int dataSize) called" << endl;
#endif

    this->dataSize = dataSize;
    this->isNegative = isNegative;
    data = new int[dataSize];
    for (int i = 0; i < dataSize; i++)
        this->data[i] = num[i];
}

BigInt::BigInt(string num)
{
#if DEBUG == 2
    cout << "BigInt(string num) called" << endl;
#endif

    if (num[0] == '-') {
        isNegative = true;
        dataSize = num.length() - 1;
    } else {
        isNegative = false;
        dataSize = num.length();
    }

    data = new int[dataSize];
    for (int i = num.length() - 1, j = 0; i >= (num[0] == '-' ? 1 : 0); i--, j++)
        data[j] = num[i] - '0';
}

string BigInt::toString() const
{
    int firstNonZero = dataSize - 1;
    while (firstNonZero > 0 && data[firstNonZero] == 0)
        firstNonZero--;

    string res = "";
    if (isNegative)
        res += "-";
    for (int i = firstNonZero; i >= 0; i--)
        res += data[i] + '0';
    return res;
}

string BigInt::toCmpString(int n) const
{
    // fill with leading 0
    // 2 cmp with 10 != 2 cmp with 10
    string res = "";

    for (int i = 0; i < n - dataSize; i++)
        res += "0";

    for (int i = dataSize - 1; i >= 0; i--)
        res += data[i] + '0';
    return res;
}

ostream &operator<<(ostream &out, const BigInt &other)
{
    cout << other.toString();

    return out;
}

BigInt BigInt::negate() const
{
    BigInt ret(this->toString());

    if (ret.isNegative)
        ret.isNegative = false;
    else
        ret.isNegative = true;

    return ret;
}

const BigInt BigInt::operator+(const BigInt &other) const
{
    int mx = max(this->dataSize, other.dataSize);

    if (isNegative == other.isNegative) {
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

        BigInt res = BigInt(sum, mx + 1, isNegative);
        delete[] sum;
        return res;
    } else {
        if (isNegative == true) {
            return other - (*this).negate();
        } else {
            return (*this) - other.negate();
        }
    }
}

const BigInt BigInt::operator-(const BigInt &other) const
{
    /*
    cout << *this << " " << other << endl;
    cout << (*this).toString() << " " << other.toString() << endl;
    cout << ((*this).toString() < other.toString()) << endl;
    cout << isNegative << " " << other.isNegative << endl;
    */

    int mx = max(this->dataSize, other.dataSize);

    if (isNegative == false && other.isNegative == false) {
        if ((*this).toCmpString(other.dataSize) <
            other.toCmpString((*this).dataSize)) {
            return (other - (*this)).negate();
        }

        int *res = new int[mx];
        memset(res, 0, sizeof(int) * (mx));

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

        BigInt ret = BigInt(res, mx, false);
        delete[] res;
        return ret;
    } else {
        if (isNegative != other.isNegative) {
            if (isNegative) {
                return ((*this).negate() + other).negate();
            } else {
                return (*this) + other.negate();
            }
        } else {
            return (*this) + other.negate();
        }
    }
}

BigInt &BigInt::operator=(const BigInt &other)
{
#if DEBUG == 2
    cout << "operator=(const BigInt &other) called" << endl;
#endif

    delete[] data;

    dataSize = other.dataSize;
    isNegative = other.isNegative;
    data = new int[dataSize];

    for (int i = 0; i < dataSize; i++)
        data[i] = other.data[i];

    return *this;
}

BigInt::BigInt(const BigInt &other)
{
#if DEBUG == 2
    cout << "BigInt(const BigInt &other) called" << endl;
#endif

    dataSize = other.dataSize;
    isNegative = other.isNegative;
    data = new int[dataSize];

    for (int i = 0; i < dataSize; i++)
        data[i] = other.data[i];
}

BigInt::~BigInt()
{
#if DEBUG == 2
    cout << "BigInt object with value " << *this << " is being deleted" << endl;
#endif

    delete[] data;
}

string BigIntOutput(int i, int j)
{
    string res = "";
    BigInt num1(i);
    BigInt num2(j);

    // BigInt num1(to_string(i));
    // BigInt num2(to_string(j));

    BigInt sum = num1 + num2;
    res =
        num1.toString() + " + " + num2.toString() + " = " + sum.toString() + "\n";

    return res;
}

string normalOutout(int i, int j)
{
    string res = "";

    res = to_string(i) + " + " + to_string(j) + " = " + to_string(i + j) + "\n";

    return res;
}

void invoke(int type, int range)
{
    switch (type) {
    case 1:
        // type 1: + +
        for (int i = 0; i < range; i++) {
            if (i % 1000 == 0)
                cout << "type 1, i = " << i << endl;

            for (int j = 0; j < range; j++) {
                string r1 = BigIntOutput(i, j);
                string r2 = normalOutout(i, j);

                if (r1 != r2) {
                    cout << "Mismatch!!!" << endl;
                    cout << r1;
                    cout << r2;
                    cout << endl;
                }
            }
        }
        break;
    case 2:
        // type 2: + -
        for (int i = 0; i < range; i++) {
            if (i % 1000 == 0)
                cout << "type 2, i = " << i << endl;

            for (int j = 0; j < range; j++) {
                string r1 = BigIntOutput(i, -j);
                string r2 = normalOutout(i, -j);

                if (r1 != r2) {
                    cout << "Mismatch!!!" << endl;
                    cout << r1;
                    cout << r2;
                    cout << endl;
                }
            }
        }
        break;
    case 3:
        // type 3: - +
        for (int i = 0; i < range; i++) {
            if (i % 1000 == 0)
                cout << "type 3, i = " << i << endl;

            for (int j = 0; j < range; j++) {
                string r1 = BigIntOutput(-i, j);
                string r2 = normalOutout(-i, j);

                if (r1 != r2) {
                    cout << "Mismatch!!!" << endl;
                    cout << r1;
                    cout << r2;
                    cout << endl;
                }
            }
        }
        break;
    case 4:
        // type 4: - -
        for (int i = 0; i < range; i++) {
            if (i % 1000 == 0)
                cout << "type 4, i = " << i << endl;

            for (int j = 0; j < range; j++) {
                string r1 = BigIntOutput(-i, -j);
                string r2 = normalOutout(-i, -j);

                if (r1 != r2) {
                    cout << "Mismatch!!!" << endl;
                    cout << r1;
                    cout << r2;
                    cout << endl;
                }
            }
        }
        break;
    default:
        break;
    }
}

void tester(int range)
{
    for (int i = 1; i <= 4; i++) {
        printf("Type %d testing...\n", i);
        invoke(i, range);
    }
}

int main()
{
#if DEBUG >= 1
    // +
    {
        BigInt num1;
        BigInt num2(100);
        BigInt num3("1000");

        BigInt sum = num2 + num3;
        cout << num2 << " + " << num3 << " = " << sum << endl;
    } {
        BigInt num1;
        BigInt num2(-5);
        BigInt num3("50");

        BigInt sum = num2 + num3;
        cout << num2 << " + " << num3 << " = " << sum << endl;
    }

    {
        BigInt num1;
        BigInt num2(50);
        BigInt num3("-5");

        BigInt sum = num2 + num3;
        cout << num2 << " + " << num3 << " = " << sum << endl;
    }

    {
        BigInt num1;
        BigInt num2(-50);
        BigInt num3("-5");

        BigInt sum = num2 + num3;
        cout << num2 << " + " << num3 << " = " << sum << endl;
    }

    // -
    {
        BigInt num1;
        BigInt num2(100);
        BigInt num3("1000");

        BigInt sum = num2 - num3;
        cout << num2 << " - " << num3 << " = " << sum << endl;
    } {
        BigInt num1;
        BigInt num2(-5);
        BigInt num3("50");

        BigInt sum = num2 - num3;
        cout << num2 << " - " << num3 << " = " << sum << endl;
    }

    {
        BigInt num1;
        BigInt num2(50);
        BigInt num3("-5");

        BigInt sum = num2 - num3;
        cout << num2 << " - " << num3 << " = " << sum << endl;
    }

    {
        BigInt num1;
        BigInt num2(-50);
        BigInt num3("-5");

        BigInt sum = num2 - num3;
        cout << num2 << " - " << num3 << " = " << sum << endl;
    }

    BigInt a("314159265358979323846264338327950288419716939937510"), c(a);
    BigInt *b = new BigInt(1618033988);
    c = a + *b;
    cout << a << " + " << *b << " = " << c << endl;
    c = a - *b;
    cout << a << " - " << *b << " = " << c << endl;
#endif

    tester(5000);

    // BigInt a(72), b(-913);
    // cout << a + b << endl;

    return 0;
}
