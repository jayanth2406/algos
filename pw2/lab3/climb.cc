#include <bits/stdc++.h>
using namespace std;

int f1(int64_t n, vector<int64_t> a, int64_t r, int64_t l)
{
    for (int64_t i = 0; i < n - 1; i++)
    {
        if (a[i] < a[i + 1])
        {
            if (r > 0)
            {
                r -= (a[i + 1] - a[i]);
            }
            else if (l > 0)
            {
                l -= (a[i + 1] - a[i]);
            }
            else
            {
                return i + 1;
            }
        }
    }
    return n - 1;
}

int f2(int64_t n, vector<int64_t> a, int64_t r, int64_t l)
{
    priority_queue<pair<int64_t, int64_t>, vector<pair<int64_t, int64_t>>, greater<pair<int64_t, int64_t>>> pq;
    for (int64_t i = 0; i < n - 1; i++)
    {
        if (a[i] < a[i + 1])
        {
            int64_t g = a[i + 1] - a[i];
            pair<int64_t, int64_t> x;
            x.first = g;
            x.second = i;
            pq.push(x);
        }
    }
    while (pq.size() > 0)
    {
        if (l > 0)
        {
            pq.pop();
            l--;
        }
        if (l <= 0)
        {
            pair<int64_t, int64_t> x = pq.top();
            if (r > 0)
            {
                r -= x.first;
                if (r > 0)
                {
                    pq.pop();
                }
                else
                {
                    return x.second;
                }
            }
            else
            {
                pq.pop();
                x = pq.top();
                return x.second;
            }
        }
    }
    return n - 1;
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int64_t n, x, r, l;
    while (cin >> n)
    {
        clock_t st = clock();

        vector<int64_t> a;
        for (int64_t i = 0; i < n; i++)
        {
            cin >> x;
            a.push_back(x);
        }

        cin >> r;
        cin >> l;

        cout << f2(n, a, r, l);

        clock_t et = clock();
        double duration = double(et - st) / CLOCKS_PER_SEC;
        cout << "\t--Execution Time: " << duration << " seconds\n";
    }
}