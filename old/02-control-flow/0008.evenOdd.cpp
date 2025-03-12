#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    // method 1: using if-else statement
    if (num % 2 == 0)
    {
        cout << num << " is even." << endl;
    }
    else
    {
        cout << num << " is odd." << endl;
    }

    // method 2: using switch statement
    switch (num % 2)
    {
    case 0:
        cout << num << " is even." << endl;
        break;
    case 1:
        cout << num << " is odd." << endl;
        break;
    }

    // method 3: using ternary operator
    (num % 2 == 0) ? cout << num << " is even." << endl : cout << num << " is odd." << endl;

    // method 4: using bitwise operator
    if (num & 1)
    {
        cout << num << " is odd." << endl;
    }
    else
    {
        cout << num << " is even." << endl;
    }

    return 0;
}
