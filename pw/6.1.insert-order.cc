#include <bits/stdc++.h>
using namespace std;

void inspos(int l, int r, vector<int> a, int t)
{
    int m = l + (r - l) / 2;
    if (t > a[m - 1] && t <= a[m])
    {
        cout << m;
        return;
    }
    if (t > a[m])
    {
        inspos(m, r, a, t);
    }
    else
    {
        inspos(l, m, a, t);
    }
}

int main()
{
    vector<int> a = {1, 3, 5, 6};
    int n = a.size();
    int t = 5;
    if (t > a[n - 1])
    {
        cout << n;
        return 0;
    }
    inspos(0, n - 1, a, t);
    return 0;
}