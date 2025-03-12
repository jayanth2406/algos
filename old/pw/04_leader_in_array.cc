#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for(int j=i; j<n; j++) {
            if(a[i] < a[j]) {
                goto x;
            }
        }
        cout << a[i] << " ";
        x:
            cout << "";
    }
    
    return 0;
}