#include <bits/stdc++.h>
using namespace std;

int64_t f(vector<int64_t> &a, int64_t i, vector<int64_t> &dp)
{
    int64_t n = a.size();
    if (i >= n)
    {
        return 0;
    }

    if (dp[i] != INT64_MAX)
    {
        return dp[i];
    }
    int64_t t1 = a[i] - f(a, i + 1, dp);

    int64_t t2 = INT64_MIN;
    if (i + 1 < n)
    {
        t2 = a[i] + a[i + 1] - f(a, i + 2, dp);
    }

    int64_t t3 = INT64_MIN;
    if (i + 2 < n)
    {
        t3 = a[i] + a[i + 1] + a[i + 2] - f(a, i + 3, dp);
    }

    return dp[i] = max({t1, t2, t3});
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);

    int64_t n, c, x;
    while (cin >> n)
    {
        clock_t st = clock();

        vector<int64_t> a;
        for (int64_t i = 0; i < n; i++)
        {
            cin >> x;
            a.push_back(x);
        }

        vector<int64_t> dp(a.size(), INT64_MAX);
        int64_t ans = f(a, 0, dp);
        if (ans < 0)
        {
            cout << "bob wins" << " ";
        }
        else if (ans > 0)
        {
            cout << "alice wins" << " ";
        }
        else
        {
            cout << "tie" << " ";
        }

        clock_t et = clock();
        double duration = double(et - st) / CLOCKS_PER_SEC;
        cout << "\t--Execution Time: " << duration << " seconds\n";
    }
}