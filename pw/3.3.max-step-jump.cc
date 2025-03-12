#include<bits/stdc++.h>
using namespace std;

int main() {
    
        vector<int> a = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
        int n=a.size();
        int jumps = 0, current_end = 0, farthest = 0;
        for (int i = 0; i < n - 1; ++i) {
            farthest = max(farthest, i + a[i]);
            if (i == current_end) {
                ++jumps;
                current_end = farthest;
            }
        }
        cout << jumps;

    return 0;
}