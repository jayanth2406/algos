#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a={1, 2, 3, 4, 5, 6, 7};
    int n=a.size();
    vector<int> f;
    int l=0, r=n-1;
    while(l<=r) {
        if(l==r) {
            f.push_back(a[l]);
            break;
        }
        f.push_back(a[r]);
        r--;
        f.push_back(a[l]);
        l++;
    }
    for(auto x : f) {
        cout << x << " ";
    }
    return 0;
}