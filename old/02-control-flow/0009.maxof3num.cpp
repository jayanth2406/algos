#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int num1 = 9, num2 = 4, num3 = 6;

    // 1. using if-else statement
    if (num1 > num2 && num1 > num3)
    {
        cout << num1 << " is the largest number." << endl;
    }
    else if (num2 > num1 && num2 > num3)
    {
        cout << num2 << " is the largest number." << endl;
    }
    else
    {
        cout << num3 << " is the largest number." << endl;
    }

    // 2. using ternary operator
    (num1 > num2 && num1 > num3)
        ? cout << num1 << " is the largest number." << endl
    : (num2 > num1 && num2 > num3)
        ? cout << num2 << " is the largest number." << endl
        : cout << num3 << " is the largest number." << endl;

    // 3. using temporary variable
    int largest = num1;
    if (num2 > largest)
    {
        largest = num2;
    }
    if (num3 > largest)
    {
        largest = num3;
    }
    cout << largest << " is the largest number." << endl;


    // 4. using max inbuilt statement inside algorithm header file
    cout << max(max(num1, num2), num3) << " is the largest number." << endl;

    return 0;
}