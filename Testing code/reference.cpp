#include <bits/stdc++.h>

using namespace std;

void test(int &x)
{
    cout << "In test: " << x << endl;
    cout << "In test x address: " << &x << endl;
    x = 100;
}

// void mySwap(const int &a, const int &b) // just call-by-value
void mySwap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int iNum(0);
    cout << iNum << endl;
    cout << &iNum << endl;

    test(iNum);
    // test(iNum); // invalid
    cout << iNum << endl;

    int num1 = 10, num2 = 20;
    cout << num1 << " " << num2 << endl;
    mySwap(num1, num2);
    cout << num1 << " " << num2 << endl;

    return 0;
}
