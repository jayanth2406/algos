#include <iostream>
using namespace std;

int main()
{
    int a = 5, b = 7;

    // swap a and b using 3rd variable
    int temp = a;
    a = b;
    b = temp;

    // swap a and b without using 3rd variable
    a = a + b;
    b = a - b;
    a = a - b;

    // swap a and b using XOR operator
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    // swap a and b using multiplication and division
    a = a * b;
    b = a / b;
    a = a / b;

    // swap a and b using cpp STL library -  swap()
    swap(a, b);

    return 0;
}