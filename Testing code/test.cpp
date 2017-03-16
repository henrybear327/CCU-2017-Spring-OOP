#include<bits/stdc++.h>

int theSize(int b[])
{
	return sizeof(b);
}

int main()
{
	int a[10];
	printf("%d %d\n", sizeof(a), theSize(a));
	return 0;
}
