#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, int n, int m, vector<vector<int>> &t, vector<vector<int>> &v)
{
    v[i][j]++;
    vector<int> xt = {1, 1, 1, 0, 0, -1, -1, -1};
    vector<int> yt = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int k = 0; k < xt.size(); k++)
    {
        int rx = xt[k] + i;
        int ry = yt[k] + j;
        if (rx >= 0 && rx < n &&
            ry >= 0 && ry < m &&
            !v[rx][ry] && t[rx][ry] == '1')
        {
            dfs(rx, ry, n, m, t, v);
        }
    }
}

int main()
{
    int n = 5, m = 5;
    vector<vector<int>> t = {
        {'1', '1', '0', '0', '0'},
        {'0', '1', '0', '0', '1'},
        {'1', '0', '0', '1', '1'},
        {'0', '0', '0', '0', '0'},
        {'1', '0', '1', '1', '0'},
    };

    int p = 0;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (t[i][j] == '1' && !v[i][j])
            {
                p++;
                dfs(i, j, n, m, t, v);
            }
        }
    }
    cout << p;
}