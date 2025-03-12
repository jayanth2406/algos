#include<bits/stdc++.h>
using namespace std;

bool checkPal(string s) {
    int l=0;
    int h=s.size()-1;
    while(l<=h) {
        if(s[l] != s[h]) return false;
        l++;
        h--;
    }
    return true;
}

int main() {
    string s="aaaabbaa";
    int n=s.size();
    for(int i=n-1; i>=0; i--) {
        for(int j=0; j<=n-i; j++) {
            if(checkPal(s.substr(j, i))){
                cout << "Longest Substring: " << s.substr(j, i) << endl;
                return 0;
            };
        }
    }
    return 0;
}