#include <iostream>
#include <numeric>
using namespace std;

// 1. Using loop to find minimum of two numbers divisble by both
int lcm1(int a, int b)
{
    int max = (a > b) ? a : b;
    while (true)
    {
        if (max % a == 0 && max % b == 0)
        {
            return max;
        }
        max++;
    }
}
// 2. Using GCD
// Time Complexity: O(log(min(a, b)))
// Space Complexity: O(log(min(a, b)))
int lcm2(int a, int b)
{
    int max = (a > b) ? a : b;
    int min = (a < b) ? a : b;
    int gcd = 1;
    for (int i = 1; i <= min; i++)
    {
        if (max % i == 0 && min % i == 0)
        {
            gcd = i;
        }
    }
    return (max * min) / gcd;
}

// 3. Using Inbuilt function in <numeric> header file
// Time Complexity: O(log(min(a, b)))
// Space Complexity: O(log(min(a, b)))
int lcm3(int a, int b)
{
    return lcm(a, b);
}

int main()
{
    int a, b, lcm;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    lcm = lcm3(a, b);
    cout << "The LCM of " << a << " and " << b << " is " << lcm << endl;
    return 0;
}