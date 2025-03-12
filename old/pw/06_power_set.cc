#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    int max = 1 << n;
    for(int i=0; i<max; i++) {
        cout << "[";
        for(int j=0; j<n; j++) {
            if(i & (1 << j)) {
                cout << a[j] << ",";
            }
        }
        cout << "], ";
    }
    return 0;
}