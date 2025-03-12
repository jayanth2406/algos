#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {4, 2}};
    unordered_map<int, int> f;
    for (auto e : edges) {
        f[e[0]]++;
        f[e[1]]++;
    }
    int center = 0;
    int n = edges.size() + 1;
    for (auto i : f) {
        if (i.second == n - 1) {
            center = i.first;
        }
    }
    cout << "Center of Star: " << center;
    return 0;
}