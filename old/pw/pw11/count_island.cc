#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int v, vector<vector<bool>> &vis, vector<vector<char>> &island)
{
    vector<int> row = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> col = {-1, 0, 1, -1, 1, -1, 0, 1};
    vis[u][v] = true;
    for (int i = 0; i < 8; i++)
    {
        int rx = u + row[i];
        int ry = v + col[i];
        if (rx >= 0 && rx < island.size() 
            && ry >= 0 && ry < island[0].size() 
            && island[rx][ry] == '1' && vis[rx][ry]==false)
        {
            dfs(rx, ry, vis, island);
        }
    }
}

void countisland(int n, int m, vector<vector<char>> &island)
{
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (island[i][j] == '1' && vis[i][j]==false)
            {
                dfs(i, j, vis, island);
                cnt++;
            }
        }
    }
    cout << "Num. of Islands: " << cnt << endl;
}

int main()
{
    vector<vector<char>> island = {
        {'1', '1', '0', '0', '0'},
        {'0', '1', '0', '0', '1'},
        {'1', '0', '0', '1', '1'},
        {'0', '0', '0', '0', '0'},
        {'1', '0', '1', '1', '0'}};

    int n = island.size(), m = island[0].size();
    countisland(n, m, island);
    return 0;
}