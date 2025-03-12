#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a={1, 2};
    int n=a.size();
    
    int mx = 1 << n; ///////////
    for(int i=0; i<mx; i++) {
        cout << "[ ";
        for(int j=0; j<n; j++) {
            if(i & (1 << j)) { ////////////
                cout << a[j] << " ";
            }
        }
        cout << "]" << endl;
    }
    return 0;
}