#include <bits/stdc++.h>
using namespace std;

int64_t f(vector<int64_t> &a, int64_t n)
{
    vector<vector<int64_t>> dp(n, vector<int64_t>(n, 0));

    for (int64_t l = 2; l < n; l++)
    {
        for (int64_t i = 1; i < n - l + 1; i++)
        {
            int64_t j = i + l - 1;
            dp[i][j] = INT64_MAX;
            for (int64_t k = i; k < j; k++)
            {
                int64_t c = a[i - 1] * a[k] * a[j] + dp[i][k] + dp[k + 1][j];
                dp[i][j] = min(dp[i][j], c);
            }
        }
    }
    
    return dp[1][n - 1];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int64_t n, x;
    while (cin >> n)
    {
        clock_t st = clock();
        vector<int64_t> a;
        for (int64_t i = 0; i < n; i++)
        {
            cin >> x;
            a.push_back(x);
        }

        cout << f(a, n);

        clock_t et = clock();
        double duration = double(et - st) / CLOCKS_PER_SEC;
        cout << "\t--Execution Time: " << duration << " seconds\n";
    }
}