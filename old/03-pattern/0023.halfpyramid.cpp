#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    /// Right half pyramid
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++) cout << "* ";

        cout << endl;
    }

    /// Left half pyramid
    for (int i = 1; i <= n; i++)
    {
        for (int k = 0; k < n-i; k++) cout << "  ";
        for (int j = n; j >= i; j--) cout << "* ";
        cout << endl;
    }

    return 0;
}