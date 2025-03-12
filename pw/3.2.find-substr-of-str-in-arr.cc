#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<string> a={"mass", "as", "hero", "superhero"};
    int n=a.size();
    vector<string> rs;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(a[i]!=a[j] && a[i].find(a[j]) != string::npos) {
                rs.push_back(a[j]);
            }
        }
    }
    for (auto i : rs)
    {
        cout << i << ", ";
    }
    return 0;
}