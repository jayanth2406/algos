#include<bits/stdc++.h>
using namespace std;

void ttlpth(int s, int d, int &p, vector<vector<int>> &adj, vector<int> &v) {
    v[s]++;
    if(s == d) p++;
    for(auto x : adj[s]) {
        if(!v[x]) ttlpth(x, d, p, adj, v);
        if(v[x] && x == d) p++;
    }
}

int main() {
    vector<vector<int>> adjlt = {
        {1, 2, 4}, // b, c, e
        {3, 4}, // d, e
        {4}, // e
        {3}, //c
        {}
    };

    int src = 0;
    int des = 4;
    int pth = 0;
    vector<int> v(adjlt.size(), 0);
    ttlpth(src, des, pth, adjlt, v);
    cout << pth << endl;
    return 0;
}