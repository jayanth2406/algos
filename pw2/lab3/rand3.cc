#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input2.txt", "w", stdout);
    srand(time(0));
    int mm = 100;
    while (mm--)
    {
        int n = 3 + rand() % 10000;
        cout << n << endl;
        for (int k = 0; k < n; k++)
        {
            int x = 1 + rand() % 100000;
            cout << x << " ";
        }
        cout << endl;
        int r = 0 + rand() % 100000;
        int l = 0 + rand() % 100;
        cout << r << " " << l << endl;
    }
}