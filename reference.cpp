#include <bits/stdc++.h>

using namespace std;

void test(int& x)
{
	cout << "In test: " << x << endl;
	x = 100;
}

int main()
{
	int iNum(0);
	cout << iNum << endl;

	test(iNum);
	cout << iNum << endl;

	return 0;
}
