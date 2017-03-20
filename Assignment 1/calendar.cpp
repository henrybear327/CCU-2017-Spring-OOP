/*
Chun-Hung Tseng 曾俊宏
403410033
Junior in department of computer science and information technology, CCU
*/

#include <cassert>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

// define terminal color
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"
#define RESET "\x1B[0m"

// DEBUGGING CONSTANT
// 0 for assignment turnin and demo
// 1 print out all months in a certain year
// 2 using java driver program
// 3 using c++ driver program
#define DEBUG 0

const char *monthName[13] = {
    "",     "January", "February",  "March",   "April",    "May",     "June",
    "July", "August",  "September", "October", "November", "December"
};

const char *weekdayName[8] = {"",    "SUN", "MON", "TUE",
                              "WED", "THU", "FRI", "SAT"
                             };

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
        Given two references to integer
    Post-condition:
        Returns if true if the year and month input is valid.
        Otherwise, return false.

        The year and month received from stdin will always be stored in the
        integer referneces.
    */
    cout << GREEN << "Please enter a year: " << RESET;
    cin >> year;
    cout << GREEN << "Please enter a month: " << RESET;
    cin >> month;

    return checkInputDataValidity(year, month);
}

bool isLeapYear(int year)
{
    /*
    Pre-condition:
        Given valid year in integer
    Post-condition:
        Returns true if the input year is a leap year, false otherwise.
    */
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

void get1stDayOfMonth(int year, int month, int &firstWeekDay,
                      int &daysInMonth)
{
    /*
    Pre-condition:

    Post-condition:

    */

    const int daysInMonthData[13] = {29, 31, 28, 31, 30, 31, 30,
                                     31, 31, 30, 31, 30, 31
                                    };
    if (month == 2 && isLeapYear(year))
        daysInMonth = daysInMonthData[0];
    else
        daysInMonth = daysInMonthData[month];

    // 1901/1/1 is Tuesday
    firstWeekDay = 2; // range 1 - 7
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

void printDivider(int width)
{
    /*
    Pre-condition:

    Post-condition:

    */

    for (int i = 0; i < width; i++) {
        cout << "_";
    }
    cout << endl;
}

int getOffsetForTitle(int width, int month)
{
    /*
    Pre-condition:

    Post-condition:

    */

    int titleLength = 4 + 1 + strlen(monthName[month]);
    return width / 2 - titleLength / 2;
}

void printTitle(int width, int year, int month)
{
    /*
    Pre-condition:

    Post-condition:

    */

    const int titleOffset = getOffsetForTitle(width, month);
    for (int i = 0; i < titleOffset; i++) {
        cout << " ";
    }
    cout << year << " " << monthName[month] << endl;
}

void printWeekdayTitle(int width, int &spacing)
{
    /*
    Pre-condition:

    Post-condition:

    */

    spacing = (width - 2 - 7 * 3) / 6;
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

void printContent(int firstWeekDay, int daysInMonth, int spacing)
{
    /*
    Pre-condition:

    Post-condition:

    */

    cout << " ";
    int count = 0;

    // if the first day is Sunday, don't print out an empty line
    for (int i = 0; firstWeekDay != 7 && i < firstWeekDay; i++) {
        if (count != 0) {
            for (int j = 0; j < spacing; j++) {
                cout << " ";
            }
        }

        for (int j = 0; j < 3; j++) {
            cout << " ";
        }

        count++;
    }

    for (int i = 1; i <= daysInMonth; i++) {
        if (count % 7 == 0) {
            if (count != 0) {
                cout << endl;
                cout << " ";
            }
        } else {
            for (int j = 0; j < spacing; j++) {
                cout << " ";
            }
        }

        cout << " ";
        cout << setw(2) << i;

        count++;
    }

    cout << endl;
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

    int spacing;
    printWeekdayTitle(width, spacing);

    // cout << firstWeekDay << endl;
    printContent(firstWeekDay, daysInMonth, spacing);

    printDivider(width);
}

// Will only be invoked when DEBUG level is set to 2
void forJavaDriverProgram()
{
    /*
    Pre-condition:

    Post-condition:

    */

    int year, month, firstWeekDay;
    do {
        // cout << "Driver program testing! Enter -1 -1 to quit" << endl;

        // cin >> year >> month;

        // if (year == -1 && month == -1)
        // return;
        for (year = 1901; year <= 2099; year++) {
            for (month = 1; month <= 12; month++) {
                int daysInMonth;
                get1stDayOfMonth(year, month, firstWeekDay, daysInMonth);
                cout << year << " " << month << " " << firstWeekDay << endl;
            }
        }
        break;
    } while (1);
}

// Will only be invoked when DEBUG level is set to 3
int get1stDayOfMonthByFormula(int year, int month)
{
    /*
    Pre-condition:

    Post-condition:

    */

    int y = year % 100;
    if (month <= 2)
        y--;
    int c = year / 100;
    int d = 1;
    // 1  2  3  4  5  6  7  8  9  10 11 12
    // 11 12 1  2  3  4  5  6  7  8  9  10
    int m = (month <= 2 ? month + 10 : month - 2);

    // printf("%d %d %d %d\n", d, m, y, c);

    int w = (d + int(floor(2.6 * m - 0.2)) + y + int(floor(y / 4.0)) +
             int(floor(c / 4.0)) - 2 * c);
    w %= 7;
    w += 7;
    w %= 7;
    w = (w == 0 ? w + 7 : w);

    return w;
}

// Will only be invoked when DEBUG level is set to 3
// Program will be aborted if the firstWeekDay calculation failed
void forCppDriverProgram()
{
    /*
    Pre-condition:

    Post-condition:

    */

    int year, month, firstWeekDay;
    do {
        // cout << "Driver program testing! Enter -1 -1 to quit" << endl;

        // cin >> year >> month;

        // if (year == -1 && month == -1)
        // return;
        for (year = 1901; year <= 2099; year++) {
            for (month = 1; month <= 12; month++) {
                int daysInMonth;
                get1stDayOfMonth(year, month, firstWeekDay, daysInMonth);
                cout << year << " " << month << " " << firstWeekDay << endl;
                int w = get1stDayOfMonthByFormula(year, month);
                cout << year << " " << month << " " << w << endl;
                assert(w == firstWeekDay);
            }
        }
        break;
    } while (1);
}

int main()
{
#if DEBUG == 2
    forJavaDriverProgram();
    return 0;
#endif

#if DEBUG == 3
    forCppDriverProgram();
    return 0;
#endif

    // read and check input
    int year, month;
    while (inputYrMn(year, month) == false) {
        cout << RED << "The input is invalid, please try again!" << RESET << endl
             << endl;
    }

    assert(1901 <= year && year <= 2099);
    assert(1 <= month && month <= 12);

#if DEBUG == 1
    for (month = 1; month <= 12; month++) {
#endif
        cout << YELLOW << "The input year " << year << " and month " << month
             << " is valid." << RESET << endl;

        // display the calendar in proper format
        int firstWeekDay, daysInMonth;
        get1stDayOfMonth(year, month, firstWeekDay, daysInMonth);

        showCalendar(year, month, firstWeekDay, daysInMonth);
#if DEBUG == 1
    }
#endif

    return 0;
}
