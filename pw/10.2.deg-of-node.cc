#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a, b;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++) {
        cin >> a;
        cin >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int k;
    cin >> k;
    cout << "Degree: " << adj[k-1].size();
    return 0;
}