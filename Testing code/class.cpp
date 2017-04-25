#include <bits/stdc++.h>

using namespace std;

class DayOfYear
{
public: // private, protected
    // void init();
    // constructor
    DayOfYear(int monthValue, int dayValue);
    DayOfYear(); // default constructor, only will be given automatically by
    // compiler when no constructor is provided at all
    void output();
    void set(int newMonth, int newDay);
    void set(int newMonth);
    int getMonth();
    int getDay();

private: // encapsulation
    int month;
    int day;
};

// :: for class
// . for object only -> different from Java, Swift, etc.

DayOfYear::DayOfYear()
{
    printf("default\n");
}

DayOfYear::DayOfYear(int monthValue, int dayValue)
{
    month = monthValue;
    day = dayValue;
}

/*
void DayOfYear::init()
{
        month = 3;
        day = 27;
}
*/

void DayOfYear::output()
{
    printf("%d %d\n", this->month, day);
}

void DayOfYear::set(int newMonth, int newDay)
{
    month = newMonth;
    day = newDay;
}

void DayOfYear::set(int newMonth)
{
    month = newMonth;
}

int DayOfYear::getMonth()
{
    return month;
}

int DayOfYear::getDay()
{
    return day;
}

int main()
{
    int aa, bb, cc;
    aa = 3;
    bb = int(4);
    cc = int();

    printf("%d %d %d\n", aa, bb, cc);

    DayOfYear today(3, 27),
              hey; // default constructor call (no arg, no parenthesis)

    DayOfYear test = DayOfYear(); // default constructor call

    today.output();
    // today.init();
    today.output();

    today.set(12, 31);
    today.output();
    printf("%d %d\n", today.getMonth(), today.getDay());

    today.set(11);
    today.output();
    printf("%d %d\n", today.getMonth(), today.getDay());

    return 0;
}
