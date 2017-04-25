#include <bits/stdc++.h>

using namespace std;

#define sz(x) (x * 1024 * 1024 / 4)

#define N 2000

// stack 8 MB
int main()
{
    srand(time(NULL));
    printf("%d\n", sz(N));
    // int arr[sz(N)];
    int *arr = (int *)malloc(sz(N) * 4);
    for (int i = 0; i < 1000000000; i++) {
        arr[rand() % sz(N)] = rand();
    }

    return 0;
}
