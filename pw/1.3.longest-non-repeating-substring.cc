#include<bits/stdc++.h>
using namespace std;

void longestNoRepeatingSubstring(string &s) {
    int n=s.size();
    unordered_map<char, int> charFreq;
    for(char a : s) {
        charFreq[a]++;
    }
    int m=0;
    for(int i=0; i<n; i++) {
        if(charFreq[s[i]] > 1) {
            charFreq[s[i]]--;
            i++;
        }
        if(charFreq[s[i]] == 1) {
            for(int j=i+1; j<n; j++) {
                if(charFreq[s[i]] == 1) {
                    m = max(m, j-i+1);
                }
            }
        }
    }
    cout << m;
}

int main() {
    string a="ABCDEFGABEF";
    longestNoRepeatingSubstring(a);
    return 0;
}