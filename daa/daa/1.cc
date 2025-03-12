#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {2, 4, 1, 6, 9, 0};
    unordered_map<int, int> frq;
    for(int i : a) {
        frq[i]++;
    }
    int smn, sc;
    for(auto x : frq) {
        if(x.second > sc) {
            x.second = INT_MAX;
        }
    }
    for(auto x : frq) {
        if(x.second > sc) {
            sc = x.second;
            smn = x.first;
        }
    }
    return 0;
}