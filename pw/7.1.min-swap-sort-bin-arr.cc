#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {0, 1, 0, 1, 1, 0};
    int n = a.size();
    int msp=0;
    vector<int> zpos;
    for(int i=0; i<n; i++) {
        if(a[i] == 0) zpos.push_back(i);
    }
    for(int i : zpos) {
        int ocnt=0;
        for(int j=0; j<i; j++) {
            if(a[j] == 1) ocnt++; 
        }
        msp+=ocnt;
    }
    cout << msp;
    return 0;
}