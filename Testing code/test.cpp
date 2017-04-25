#include <bits/stdc++.h>

int theSize(char a[])
{
    return sizeof(a);
}

int theSize(int b[])
{
    return sizeof(b);
}

int theSize(double c[])
{
    return sizeof(c);
}

int main()
{
    char a[10];
    int b[10];
    double c[10];

    //  g++ -Wall -Wextra -std=c++11 -O2 test.cpp -m32 && ./a.out
    //  pointer size will be 32-bit
    printf("%lu %lu %lu\n", sizeof(a), sizeof(b), sizeof(c));
    printf("%d %d %d\n", theSize(a), theSize(b), theSize(c));
    return 0;
}
