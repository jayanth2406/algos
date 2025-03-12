#include <iostream>
using namespace std;


// 1. Using Modulus operator
bool isPrime1(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i < num; i++)
        if (num % i == 0)
            return false;
    return true;
}

// 2. Using Square Root
// Time Complexity: O(n) 
// Auxiliary Space: O(1)
bool isPrime2(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0)
            return false;
    return true;
}

// 3. Prime number between a range
void printPrime(int low, int high)
{
    for (int i = low; i <= high; i++)
        if (isPrime1(i))
            cout << i << " is a prime number.";
}

int main()
{
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    cout << n << (isPrime1(n) ? " is " : " is not ")
         << "a prime number";

    return 0;
}