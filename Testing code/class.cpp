#include <bits/stdc++.h>

using namespace std;

class DayOfYear 
{
	public: // private, protected
		void init();
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
void DayOfYear::init() 
{
	month = 3;
	day = 27;
}

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
	DayOfYear today; // don't need to new??
	
	today.output();
	today.init();
	today.output();

	today.set(12, 31);
	today.output();
	printf("%d %d\n", today.getMonth(), today.getDay());

	today.set(11);
	today.output();
	printf("%d %d\n", today.getMonth(), today.getDay());

	return 0;
}
