#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> sar;
    for(int i=0; i<n; i++) {
        int s;
        cin >> s;
        sar.push_back(s);
    }

    int steps=0;
    for(int i=0; i<n; i++) {
        cout << sar[i] << "->";
        steps++;
        if(i+sar[i] > n) {
            cout << sar[n-1];
           break;
        }
    }
    cout << "\nTotal jump: " << steps << endl;
    
    return 0;
}
// 10 1 3 5 8 9 2 6 7 6 8 9