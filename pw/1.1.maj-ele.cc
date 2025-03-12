#include<bits/stdc++.h>
using namespace std;

void majorityElement(vector<int> &a) {
    unordered_map<int, int> freq;
    for (int i = 0; i < a.size(); i++)
    {
        freq[a[i]]++;
    }
    int mx=0;
    int v=0;
    for(auto x : freq) {
        if(mx < x.second) {
            mx=x.second;
            v=x.first;
        }
    }
    if(mx>a.size()/2) {
        cout << v << endl;
    } else {
        cout << "No Majority Element" << endl;
    }
}

int main() {
    vector<int> a={3,4,2,4,2,4,4};
    majorityElement(a);
    return 0;
}