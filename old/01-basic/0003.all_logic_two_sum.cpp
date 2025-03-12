#include <iostream>
#include <cmath>
using namespace std;

/// @brief 1. Using addition operator
/// Time Complexity: O(1)
/// Space Complexity: O(1)
int add2Nums1(int a, int b)
{
    return a + b;
}
/// @return

/// @brief 2. Using subtraction operator
/// Time Complexity: O(1)
/// Space Complexity: O(1)
int add2Nums2(int a, int b)
{
    return a - (-b);
}
/// @return

/// @brief 3. Using increment & decrement operator
/// Time Complexity: O(N), where N is the min(A,B)
/// Space Complexity: O(1)
int add2Nums3(int a, int b)
{
    // when b is positive
    while (b > 0)
    {
        a++;
        b--;
    }
    // when b is negative
    while (b < 0)
    {
        a--;
        b++;
    }
    return a;
}
/// @return

/// @brief 4. Using print() method
/// Time Complexity: O(1)
/// Space Complexity: O(1)
int add2Nums4(int a, int b)
{
    return printf("%*s%*s", a, "", b, "");
}
/// @return

/// @brief 5. Using goto statement - similar to 3rd method
/// Time Complexity: O(N), where N is the min(A,B)
/// Space Complexity: O(1)
int add2Nums5(int a, int b)
{
    int result = a;
    if (b > 0)
    {
        goto positive;
    }
    else
    {
        goto negative;
    }
positive:
    while (b > 0)
    {
        result++;
        b--;
    }
    return result;
negative:
    while (b < 0)
    {
        result--;
        b++;
    }
    return result;
}
/// @return

/// @brief 6. Using Half Adder Method - Binary operator
/// Time Complexity: O(log n)
/// Space Complexity: O(1)
int add2Nums6(int a, int b)
{
    while (b != 0)
    {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }

    return a;
}
/// @return

/// @brief 7. Using Exponnential and Logarithmic.
/// Time Complexity: O(log n)
/// Space Complexity: O(1)
int add2Nums7(int a, int b)
{
    return log(exp(a) * exp(b));
}
/// @return

/// @brief 8. Using Recursion
/// Time Complexity: O(log n)
/// Space Complexity: O(1)
int add2Nums8(int a, int b)
{
    if (b == 0)
        return a;
    else
        return add2Nums8(a ^ b, (a & b) << 1);
}
/// @return

int main()
{
    int a = 13, b = 42;
    cout << "The sum of " << a << " and " << b << " is " << add2Nums1(a, b) << endl;

    return 0;
}