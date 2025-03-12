#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "w", stdout);
    srand(time(0));
    int mm = 100;
    while (mm--)
    {
        int i = 1;
        int j = pow(10, 3);
        int n = i + rand() % (j - i + 1);
        cout << n << endl;
        for (int k = i; k < n; k++)
        {
            int x = i + rand() % (j - i + 1);
            cout << x << " ";
        }
        cout << endl;
    }
}