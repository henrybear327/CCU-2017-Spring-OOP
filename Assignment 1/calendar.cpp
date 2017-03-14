/*
Chun-Hung Tseng 曾俊宏
403410033
Junior in department of computer science and information technology, CCU
*/
#include <cassert>
#include <iostream>

// define terminal color
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"
#define RESET "\x1B[0m"

using namespace std;

bool checkInputDataValidity(int year, int month)
{
    /*
    Check if year and month is within proper range
    Pre-condition:
            Given two integers, year and month
    Post-condition:
            Returns boolean true if year is within range 1901 and 2099, inclusive,
    and month is within range 1 and 12, inclusive
    */
    if (!(1901 <= year && year <= 2099))
        return false;
    else if (!(1 <= month && month <= 12))
        return false;
    return true;
}

bool inputYrMn(int &year, int &month)
{
    /*
    Pre-condition:
    Post-condition:
    */
    cout << GREEN << "Please enter a year: " << RESET;
    cin >> year;
    cout << GREEN << "Please enter a month: " << RESET;
    cin >> month;

    return checkInputDataValidity(year, month);
}

void get1stDayOfMonth(int year, int month, int &firstWeekDay,
                      int &daysInMonth)
{
    /*
    Pre-condition:
    Post-condition:
    */
}

void showCalendar(int year, int month, int firstWeekDay, int dayInMonth) {}

int main()
{
    // read and check input
    int year, month;
    while (inputYrMn(year, month) == false) {
        cout << RED << "The input is invalid, please try again!" << RESET << endl
             << endl;
    }

    assert(1901 <= year && year <= 2099);
    assert(1 <= month && month <= 12);

    cout << YELLOW << "THe input year " << year << " and month " << month
         << " is valid." << RESET << endl;

    // display the calendar in proper format

    return 0;
}
