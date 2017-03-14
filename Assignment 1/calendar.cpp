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

int daysInMonthData[13] = {29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeapYear(int year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

void get1stDayOfMonth(int year, int month, int &firstWeekDay,
                      int &daysInMonth)
{
    /*
        TODO: write driver program to test this
    Pre-condition:
    Post-condition:
    */

    // 1901/1/1 is Tuesday
    firstWeekDay = 2;
    for (int i = 1901; i <= year; i++) {
        bool isLeap = isLeapYear(i);
        for (int j = 1; j <= 12; j++) {
            if (year == i && month == j)
                return;
            int retrieve = (j == 2 ? (isLeap ? 0 : 2) : j);
            int diff = daysInMonthData[retrieve] % 7;

            firstWeekDay = ((firstWeekDay - 1) + diff + 7) % 7 + 1;
        }
    }

    assert(1 == -1); // should be run
    return;
}

const char *monthName[13] = {
    "",     "January", "February",  "March",   "April",    "May",     "June",
    "July", "August",  "September", "October", "November", "December"
};

const char *weekdayName[8] = {"",    "SUN", "MON", "TUE",
                              "WED", "THU", "FRI", "SAT"
                             };

void printDivider(int width)
{
    for (int i = 0; i < width; i++) {
        cout << "_";
    }
    cout << endl;
}

int getOffsetForTitle(int width, int month)
{
    int titleLength = 4 + 1 + strlen(monthName[month]);
    return width / 2 - titleLength / 2;
}

void printTitle(int width, int year, int month)
{
    const int titleOffset = getOffsetForTitle(width, month);
    for (int i = 0; i < titleOffset; i++) {
        cout << " ";
    }
    cout << year << " " << monthName[month] << endl;
}

void printWeekdayTitle(int width)
{
    const int spacing = (width - 2 - 7 * 3) / 6;
    assert(spacing > 0);

    cout << " ";
    for (int i = 1; i <= 7; i++) {
        cout << weekdayName[i];
        if (i < 7) {
            for (int j = 0; j < spacing; j++) {
                cout << " ";
            }
        } else {
            cout << endl;
        }
    }
}

void showCalendar(int year, int month, int firstWeekDay, int daysInMonth)
{
    /*
    Pre-condition:
    Post-condition:
    */

    const int width = 38;

    printDivider(width);

    printTitle(width, year, month);

    printDivider(width);

    printWeekdayTitle(width);

    cout << firstWeekDay << endl;

    printDivider(width);
}

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

    cout << YELLOW << "The input year " << year << " and month " << month
         << " is valid." << RESET << endl;

    // display the calendar in proper format
    int firstWeekDay;
    get1stDayOfMonth(year, month, firstWeekDay, daysInMonthData[month]);

    showCalendar(year, month, firstWeekDay, daysInMonthData[month]);

    return 0;
}
