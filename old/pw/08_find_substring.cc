#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> sar;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        sar.push_back(s);
    }

    for(auto x : sar) {
        for(auto y : sar) {
            if (x.find(y) != string::npos && x!=y) {
                cout << y << " ";
            }
        }
    }
    return 0;
}