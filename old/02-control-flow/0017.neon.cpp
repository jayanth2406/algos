#include <iostream>
using namespace std;

/// Neon number is a number where the sum of digits of square of the number is equal to the number.
/// example: 9 is a neon number because 9^2 = 81 and 8 + 1 = 9
/// example: 12 is not a neon number because 12^2 = 144 and 1 + 4 + 4 = 9

int isNeon1(int n) {
    int square = n * n;
    int sum = 0;
    while (square != 0) {
        sum += square % 10;
        square /= 10;
    }
    return sum == n;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (isNeon1(n)) {
        cout << n << " is a neon number." << endl;
    } else {
        cout << n << " is not a neon number." << endl;
    }
    return 0;
}