#include <iostream>
using namespace std;

/// Palindrome Definition
/// A palindrome is a word, number, phrase, or other sequence of characters
/// which reads the same backward as forward, such as madam, racecar.
/// example: 121 is a palindrome because 121 reads the same backward as forward.

// 1. Using a for loop
// Time complexity: O(n)
// Space complexity: O(1)
bool isPalindrome1(int num)
{
    int reversed = 0, remainder, original = num;
    while (num != 0)
    {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }
    if (original == reversed)
    {
        return true;
    }
    return false;
}

// 2. Using recursion
// Time complexity: O(n)
// Space complexity: O(n)
bool isPalindrome2(int num) {
    static int reversed = 0, remainder, original = num;
    if (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        isPalindrome2(num / 10);
    }
    if (original == reversed) {
        return true;
    }
    return false;
}

int main()
{
    int num;
    cout << "Enter a positive number: ";
    cin >> num;
    cout << num << (isPalindrome1(num) ? " is " : " is not ")
         << "a palindrome." << endl;
    return 0;
}