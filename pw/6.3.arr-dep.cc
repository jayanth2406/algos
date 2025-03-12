#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    int p=0;
    int n=arr.size();
    for(int i=1; i<n; i++) {
        if(arr[i] < dep[i-1]) p++;
    }
    cout << p;
    return 0;
}