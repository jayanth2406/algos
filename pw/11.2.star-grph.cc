#include<bits/stdc++.h>
using namespace std;

int main() {
    int n=4;
    vector<vector<int>> eg = {{1, 2}, {2, 3}, {4, 2}};
    vector<vector<int>> adj(n+1);
    for(auto a : eg) {
        adj[a[0]].push_back(a[1]);
        adj[a[1]].push_back(a[0]);
    }
    for(int i=0; i<n+1; i++) {
        if(adj[i].size() == n-1) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}