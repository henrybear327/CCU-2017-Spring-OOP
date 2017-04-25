#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x;
    double y;
    long long int color;

    void init(double x, double y, int color)
    {
        this->x = x;
        this->y = y;
        this->color = color;
    }

    void print()
    {
        printf("%f %f %lld\n", x, y, color);
    }
};

int main()
{
    // struct Point p;
    // Point p({1.5, 2.7, 4});
    Point p = {1.5, 2.7, 4};
    p.print();
    p.init(1, 2, 3);
    p.print();

    /*
    Point pp = {1.5}; // without initializer -> 0 -> warning!!
    pp.print();
    */

    // Point a, b;
    // a = b; // this works

    return 0;
}
