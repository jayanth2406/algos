#include<bits/stdc++.h>
using namespace std;

// TC - O(n*W)
// SC - O(n*W) + O(n) + O(n) = O(n*W)

int f(int ind, int W, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp) {
    if(ind == 0) {
        if(weight[ind] == 0) return value[0];
        return 0;
    }

    if(dp[ind][W] != -1) return dp[ind][W];

    int notTake = 0 + f(ind - 1, W, weight, value, dp);
    int take  = INT_MIN;
    if(weight[ind] <= W) {
        take = value[ind] + f(ind - 1, W - weight[ind], weight, value, dp);
    }
    return dp[ind][W] = max(notTake, take);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return f(n - 1, maxWeight, weight, value, dp);
}

int main() {
    vector<int> weight = {2, 4, 6};
    vector<int> value = {5, 11, 13};
    int n = weight.size();
    int maxWeight = 10;
    cout << knapsack(weight, value, n, maxWeight) << endl;
    return 0;
}