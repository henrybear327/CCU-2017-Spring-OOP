#include <bits/stdc++.h>

using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void ptrFormatting(int *a)
{
    return;
}

int main()
{
    int v = 10;
    int *p1 = &v, p2 = v, *p3;
    printf("v %d %p %p\n", v, &v, p1);

    vector<int> a(10, 1);
    vector<int> b(10, 2);

    for (int i = 0; i < 10; i++)
        printf("%d%c", a[i], i == 9 ? '\n' : ' ');
    for (int i = 0; i < 10; i++)
        printf("%d%c", b[i], i == 9 ? '\n' : ' ');

    for (int i = 0; i < 10; i++)
        swap(a[i], b[i]);

    for (int i = 0; i < 10; i++)
        printf("%d%c", a[i], i == 9 ? '\n' : ' ');
    for (int i = 0; i < 10; i++)
        printf("%d%c", b[i], i == 9 ? '\n' : ' ');

    return 0;
}
