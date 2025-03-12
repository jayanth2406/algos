#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0, m = 0, x = 0, k = 0;
    cout << "Enter matrix dimensions: " << endl;
    cin >> n >> m;
    cout << "Enter matrix row-wise: " << endl;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            mat[i][j] = x;
        }
    }
    cout << "Enter target value: " << endl;
    cin >> k;

    int a = 0, b = 0, r = 0;
    for (int i = 0; i < m; i++)
    {
        if (k <= mat[n - 1][i])
        {
            b = i;
            break;
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (k == mat[j][b])
        {
            r++;
            a = j;
            break;
        }
    }
    if (r)
    {
        cout << "Found at: " << a << " " << b << endl;
    }
    else
    {
        cout << "Not found " << a << " " << b << endl;
    }
    return 0;
}