#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    cin >> k;
    int ar[n];
    for(int i=0; i<n; i++) {
        cin >> ar[i];
    }

    int freq[n-k+1];
    for(int i=0; i<n-k+1; i++) {
        freq[i]=999;
        cout << "Min of ";
        for(int j=0; j<k; j++) {
            if(ar[i+j] <= freq[i]) freq[i] = ar[i+j];
            cout << ar[i+j] << " ";
        }
        cout << " is " << freq[i] << ".\n";
    }
    int max=-9999;
    for(int i=0; i<n-k+1; i++) {
        if(freq[i] > max) max = freq[i];
    }
    cout << "Maxm of all: " << max << "\n";
    return 0;
}