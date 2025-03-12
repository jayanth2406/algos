#include <numeric>
#include <iostream>
using namespace std;

// 1. Using loop to find minimum of two numbers divisble by both
int gcd1(int a, int b)
{
    int gcd;
    for (int i = 1; i <= a && i <= b; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}

// 2. Using Euclidean Algorithm
// Time Complexity: O(log(min(a, b)))
// Space Complexity: O(log(min(a, b)))
int gcd2(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a > b)
        return gcd2(a - b, b);
    return gcd2(a, b - a);
}

// 3. Using Euclidean Algorithm (Optimized)
// Time Complexity: O(log(min(a, b)))
// Space Complexity: O(log(min(a, b)))
int gcd3(int a, int b)
{
    if (b == 0)
        return a;
    return gcd3(b, a % b);
}

// 4. Using Inbuilt function in <numeric> header file
// Time Complexity: O(log(min(a, b)))
// Space Complexity: O(log(min(a, b)))
int gcd4(int a, int b)
{
    gcd(a, b);
}

// 5. Using Bitwise Operators
// Time Complexity: O(log(min(a, b)))
// Space Complexity: O(1)
int gcd5(int a, int b)
{
    if (b == 0)
        return a;
    return gcd5(b, a & b);
}

// 6. Using Stein's Algorithm from STL <numeric> header file
// Time Complexity: O(log(min(a, b)))
// Space Complexity: O(1)
int gcd6(int a, int b)
{
    int shift;
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    for (shift = 0; ((a | b) & 1) == 0; ++shift)
    {
        a >>= 1;
        b >>= 1;
    }
    while ((a & 1) == 0)
        a >>= 1;
    do
    {
        while ((b & 1) == 0)
            b >>= 1;
        if (a > b)
        {
            unsigned int t = b;
            b = a;
            a = t;
        }
        b = (b - a);
    } while (b != 0);
    return a << shift;
}

int main()
{
    int a, b, gcd;

    cout << "Enter two numbers: ";
    cin >> a >> b;
    gcd = gcd1(a, b);
    cout << "GCD of " << a << " and " << b << " is " << gcd << endl;

    return 0;
}

/*
Euclidean Algorithm:
- The Euclidean Algorithm is based on the principle that the GCD of two numbers a and b is the same as the GCD of b and a % b (where % is the modulus operator).
- It uses subtraction and modulus operations.
- It works by repeatedly subtracting the smaller number from the larger one until the numbers become equal (which will then be the GCD), or one of them becomes 0 (in which case the other number is the GCD).
- The time complexity is O(log min(a, b)).

Stein's Algorithm:
- Stein's Algorithm is based on the properties of even and odd numbers and the bitwise AND and shift operations.
- It works by eliminating factors of 2 (because they are common) and reducing the problem size.
- It is more efficient than the Euclidean Algorithm when dealing with large integers, especially when the numbers have a large difference in magnitude.
- The time complexity is also O(log min(a, b)), but in practice, it often performs fewer operations than the Euclidean Algorithm for large integers.
*/