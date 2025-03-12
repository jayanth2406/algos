#include <iostream>
using namespace std;

/*
    Logic:
    if (year % 400 = 0)
            return true (Leap year)
    else if (year % 100 = 0)
            return false (Not a leap year)
    else if (year % 4 = 0)
            return true (Leap year)
    else
            return false (Not a leap year)
    endif
*/

int main()
{
    int year;
    cout << "Enter a year: ";
    cin >> year;

    if (year % 400 == 0)
    {
        cout << year << " is a leap year." << endl;
    }
    else if (year % 100 == 0)
    {
        cout << year << " is not a leap year." << endl;
    }
    else if (year % 4 == 0)
    {
        cout << year << " is a leap year." << endl;
    }
    else
    {
        cout << year << " is not a leap year." << endl;
    }

    return 0;
}