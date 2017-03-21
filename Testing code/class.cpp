#include <bits/stdc++.h>

using namespace std;

class DayOfYear 
{
	public: // private, protected
		void init();
		void output();
		int month;
		int day;	
};

// :: for class
// . for object only -> different from Java, Swift, etc.
void DayOfYear::init() 
{
	month = 3;
	day = 27;
}

void DayOfYear::output() 
{
	printf("%d %d\n", this->month, day);
}

int main()
{
	DayOfYear today; // don't need to new??
	
	today.output();
	today.init();
	today.output();

	return 0;
}
