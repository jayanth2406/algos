#include <iostream>
using namespace std;

/// Fibonacci Series: is a series of numbers where the next number is the sum of previous two numbers.
/// Series: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ... and so on.


// Method 1: using for loop
void fibonacci1(int n)
{
    int t1 = 0;
    int t2 = 1;
    int nextTerm = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << nextTerm << " ";
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }
}

// Method 2: using recursion
int fibonacci2(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fibonacci2(n - 1) + fibonacci2(n - 2);
}


int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    fibonacci1(n); 


    return 0;
}