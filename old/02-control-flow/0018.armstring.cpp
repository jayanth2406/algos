#include <iostream>
using namespace std;

// Armstrong Number is a number where the sum of digits of cube of the number is equal to the number.
// example 1. 153: 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
// example 2. 371: 3^3 + 7^3 + 1^3 = 27 + 343 + 1 = 371

// Method 1: using while loop
bool isArmstrong1(int n)
{
    int t = n;
    int sum = 0;
    while (t != 0)
    {
        sum += (t % 10) * (t % 10) * (t % 10);
        t /= 10;
    }
    return sum == n;
}

// Method 2: using goto
bool isArmstrong2(int n)
{
    int sum = 0;
    int temp = n;
loop:
    sum += (temp % 10) * (temp % 10) * (temp % 10);
    temp /= 10;
    if (temp != 0)
    {
        goto loop;
    }
    return sum == n;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << n << (isArmstrong2(n) ? " is an armstrong number." : " is not an armstrong number.") << endl;

    return 0;
}