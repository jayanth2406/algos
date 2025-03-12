#include <bits/stdc++.h>
using namespace std;

// Memoization
// TC - O(n^3)
// SC - O(n^2) + O(n^2) = O(n^2)

int f(int i, int j, vector<int>& arr, vector<vector<int>>& dp){
    // base condition
    if(i == j) return 0;        
    int mini = 1e9;    
    // memoization
    if(dp[i][j] != -1) return dp[i][j];
    // partioning loop
    for(int k = i; k < j; k++){
        int steps = arr[i-1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k+1, j, arr, dp);
        if(steps < mini) mini = steps; 
    }
    return dp[i][j] = mini;
}


int matrixMultiplication(vector<int>& arr, int N){
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return f(1, N-1, arr, dp);    
}

int main() {
	vector<int> arr = {10, 20, 30, 40, 50};
	int n = arr.size();
	cout<<"The minimum number of operations is "<<matrixMultiplication(arr,n);
	return 0;
}