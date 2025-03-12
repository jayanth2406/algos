#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ar[n];
    int br[n];
    for(int i=0; i<n; i++) {
        cin >> ar[i];
    }

    int a=0;
    int b=n-1;
    int k=0;
    while(a<=b) {
        br[k] = ar[b];
        b--; k++;
        br[k] = ar[a];
        a++; k++;
    }

    for(auto i : br) {
        cout << i << " ";
    }
    
    return 0;
}