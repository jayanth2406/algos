
#include <bits/stdc++.h>
using namespace std;

// TC - O(n*W)
// SC - O(n*W) + O(n) + O(n) = O(n*W)

int f(int ind, int w, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp) {
    if(ind == 0) return (int)(w/wt[0])*val[0];

    int notTake = 0 + f(ind-1, w, val, wt, dp);
    int take = INT_MIN;
    if(wt[ind] <= w) {
        take = val[ind] + f(ind, w-wt[ind], val, wt, dp);
    }
    return max(notTake, take);
}

int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return f(n-1, W, val, wt, dp);
}

int main() {
    vector<int> wt = {2, 4, 6};
    vector<int> val = {5, 11, 13}; 
    int W = 10;
    int n = wt.size();
    
    cout << "The Maximum value of items the thief can steal is " << unboundedKnapsack(n, W, val, wt) << endl;

    return 0;
}

