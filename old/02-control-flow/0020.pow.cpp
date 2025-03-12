#include <iostream>
using namespace std;

long long int power(int base, int exponent) {
    long long int result = 1;
    for (int i = 1; i <= exponent; i++) {
        result *= base;
    }
    return result;
}

int main() {
    int base, exponent;
    long long result = 1;
    
    cout << "Enter a base number: ";
    cin >> base;
    cout << "Enter an exponent: ";
    cin >> exponent;

    result = power(base, exponent);
    cout << base << "^" << exponent << " = " << result << endl;
    return 0;
}