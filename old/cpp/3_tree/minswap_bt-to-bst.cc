#include <bits/stdc++.h>
using namespace std;

void leveltoinorder(int in, vector<int> v, vector<int> &n) {
    if(in >= v.size()) return;
    leveltoinorder(2*in+1, v, n);
    n.push_back(v[in]);
    leveltoinorder(2*in+2, v, n);
}

int minSwap(vector<int> v) {
    int sp=0;
    vector<int> n;
    leveltoinorder(0, v, n);
    for(auto i: n) cout << i << " ";
    printf("\n");
    for(int i=0; i<n.size(); i++) {
        int min=i;
        for(int j=i+1; j<n.size(); j++) {
            if(n[min]>n[j]) min = j;
        }
        if(min!=i) {
            swap(n[min], n[i]);
            sp++;
        }
    }
    return sp;
}


int main() {
    vector<int> rt={5,6,7,8,9,10,11};
    cout << "Min swap: " << minSwap(rt) << "\n";
    
    return 0;
}