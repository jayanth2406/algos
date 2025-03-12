#include <iostream>
using namespace std;

void printFactors(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            cout << i << ((i != n) ? ", " : "");
    }
}

int main()
{
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    cout << "Factors of " << n << " are: " << endl;
    printFactors(n);
    return 0;
}