#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input2.txt", "w", stdout);
    srand(time(0));
    int mm = 1000;
    while (mm--)
    {
        int i = 0;
        int j = pow(10, 2);
        int n = i + 10 + rand() % (j - i + 1);
        int c = i + rand() % (n - i + 1);
        cout << n << " " << c << endl;
        for (int k = i; k < n; k++)
        {
            int x = i + rand() % (j - i + 1);
            cout << x << " ";
        }
        cout << endl;
    }
}