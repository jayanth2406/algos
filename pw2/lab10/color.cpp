#include <bits/stdc++.h>
using namespace std;

bool ok(int v, int c, vector<int> &col, vector<vector<int>> &g)
{
    for (int u : g[v])
        if (col[u] == c)
            return false;
    return true;
}

void dfs(int v, int n, int m, vector<int> &col, vector<vector<int>> &g, vector<vector<int>> &res, int &cnt)
{
    if (v == n)
    {
        res.push_back(col);
        cnt++;
        return;
    }
    for (int c = 1; c <= m; c++)
    {
        if (ok(v, c, col, g))
        {
            col[v] = c;
            dfs(v + 1, n, m, col, g, res, cnt);
            col[v] = 0;
        }
    }
}

void solve()
{
    int n, e, m;
    if (!(cin >> n >> e))
        return;
        
    vector<vector<int>> g(n);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> m;
    vector<int> col(n, 0);
    vector<vector<int>> res;
    int cnt = 0;
    dfs(0, n, m, col, g, res, cnt);
     cout << cnt << " valid colorings" << endl;
    if (cnt == 0)
    {
         cout << "No valid colorings exist." << endl;
    }
    else
    {
         cout << "Color assignments:" << endl;
        for (auto &c : res)
        {
             cout << "(";
            for (int i = 0; i < n; i++)
            {
                 cout << "Vertex " << i + 1 << ": Color " << c[i];
                if (i < n - 1)
                     cout << ", ";
            }
             cout << ")" << endl;
        }
    }
     cout << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string line;
    while (!cin.eof())
    {
        if (cin.tellg() == -1) break;
        solve();
        if (cin.eof()) break;
    }
    return 0;
}