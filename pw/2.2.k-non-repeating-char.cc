#include<bits/stdc++.h>
using namespace std;

int main() {
    string a="Mahindra";
    int k=3;
    int n=a.size();
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }
    for(int i=0; i<n; i++) {
        if(freq[a[i]] = 1) k--;
        if(k==-1) {
            cout << a[i];
            return 0;
        }
    }
    cout << " Less than k non-repeating characters in input" << endl;
    return 0;
}