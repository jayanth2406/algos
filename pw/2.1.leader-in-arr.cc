#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a={16, 17, 4, 3, 5, 2};
    int n=a.size();
    int mx=INT_MIN;
    list<int> ld;
    for(int i=n-1; i>=0; i--) {
        if(a[i] > mx) {
            mx=a[i];
            ld.push_front(mx);
        }
    }
    for(auto l : ld) {
        cout << l << " ";
    }
    return 0;
}