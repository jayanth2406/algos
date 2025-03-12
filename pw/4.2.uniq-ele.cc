#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {3, 2, 2, 5, 3, 6, 7};
    int n = a.size();
    unordered_map<int, int> f;
    for (int i = n-1; i >= 0; i--)
    {
        f[a[i]]++;
    }
    for (auto x : f)
    {
        if (x.second <= 1)
            cout << x.first << ", ";
    }
    return 0;
}