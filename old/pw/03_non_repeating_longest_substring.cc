#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int len=s.length();
    int freq=0;
    for(int i=0; i<len; i++) {
        int cnt=1, j=0;
        do
        {
            cnt++;
            j++;
        } while ((s[i] != s[i+j]) || (s[i+j]!='\0'));
        if(cnt > freq) freq = cnt;
    }
    cout << freq;
    return 0;
}