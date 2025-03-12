#include<bits/stdc++.h>
using namespace std;

int main(){
    
    vector<int> a={3, 6, 9, 1};
    int n=a.size();
    int hi=INT_MIN, lo=INT_MAX;
    for(auto x : a) {
        hi=max(hi, x);
        lo=min(lo, x);
    }
    if(n<2 || hi==lo) {
        cout << "0";
        return 0;
    }
    int bs=min(1, (hi-lo)/n-1);
    int bc=(hi-lo)/bs+1;
    vector<pair<int, int>> b(bc, {INT_MAX, INT_MIN});
    for(auto x : a) {
        int in=(x-lo)/bs;
        b[in].first = min(b[in].first, x);
        b[in].second = max(b[in].second, x);
    }
    int mg=0, pr=INT_MAX;
    for(auto p : b) {
        if(p.first > p.second) continue;
        mg = max(mg, p.first-pr);
        pr=p.second;
    }
    cout << mg << endl;
    return 0;
}