#include <bits/stdc++.h>

using namespace std;

class Sample
{
public:
    Sample(const char *string);
    ~Sample();
    void output() const;
    static void setA(int aa = 1);

private:
    static int a;
    const char *string;
};

Sample::Sample(const char *string) : string(string)
{
    cout << "Constructor of " << string << " called" << endl;
}

Sample::~Sample()
{
    // cout << "Destructor of " << string << " called" << endl;
}

void Sample::setA(int aa)
{
    a = aa;
    printf("%d\n", a);
}

void Sample::output() const
{
    printf("%s\n", string);
}

class ClassOfClass
{
public:
    ClassOfClass(const char *string);

private:
    Sample s;
};

ClassOfClass::ClassOfClass(const char *string) : s(string)
{
    cout << "ClassOfClass constructor called" << endl;
}

void printData(const Sample s)
{
    s.output();
}

int Sample::a = 0; // must be given a type, and done outside main

int main()
{
    /*
    int feet = 15000;
    printf("%f\n", 5000 * (feet / 5280.0));
    printf("%d\n", 5000 * (feet / 5280));
    printf("%f\n", 5000.0 * (feet / 5280));
    */

    /*
    // weird
    const char* str = "Hello!";
    Sample s(str);
    s.output();

    const char *str1 = "Bye!";
    s = Sample(str1);
    s.output();

    cout << "Hahaha" << endl;
    */

    const char *str2 = "Hey";
    // ClassOfClass coc(str2);

    Sample s(str2);
    printData(s);
    s.setA(10);

    return 0;
}
