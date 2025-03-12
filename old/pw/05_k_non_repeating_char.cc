#include<bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;
    string s;
    cin >> s;

    vector<int> freq = {0, 256};
    for (auto c : s) {
        freq[c]++;
    }

    for(auto c : s) {
        if(freq[c]==1) {
            if(k==1) {
                cout << c;
                return 0;
            } else {
                k--;
            }
        }
    }
    cout << "kth doesn't exist";
    
    return 0;
}