#include<bits/stdc++.h>
using namespace std;

void maxofkmin(vector<int> &a, int k) {
    int n=a.size();
    int mx=0;
    for(int i=0; i<a.size()-2; i+=k-2) {
        int mn=a[i];
        cout << "Minimum of ";
        for(int j=i; j<k+i; j++) {
            if(mn>a[j]) mn=a[j];
            cout << a[j];
            if(j!=k+i-1) cout << ", ";
        }
        cout << " is "<< mn << endl;
        if(mn>mx) mx=mn;
    }
    cout << "Maximum of all above is " << mx << endl;
}

int main() {
    vector<int> a={1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k=3;
    maxofkmin(a, k);
    return 0;
}