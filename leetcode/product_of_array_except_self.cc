#include <bits/stdc++.h>
using namespace std;

/**
 ** 238. Product of Array Except Self
 ** Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

 ** The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

 ** You must write an algorithm that runs in O(n) time and without using the division operation.

 ** Example 1:
    Input: nums = [1,2,3,4]
    Output: [24,12,8,6]
    Example 2:
    Input: nums = [-1,1,0,-3,3]
    Output: [0,0,9,0,0]

 ** Constraints:
    2 <= nums.length <= 105
    -30 <= nums[i] <= 30
    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 
 ** Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
 
 */

// Good Solution: O(n) time & O(1) Space
vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
        output[0] = 1;
        for(int i=1; i<n; i++){
            output[i] = output[i-1] * nums[i-1];
        }
        int right = 1;
        for(int i=n-1; i>=0; i--){
            output[i] *= right;
            right *= nums[i];
        }
        return output;
    }

// My Solution: O(n) time & O(n) space
int main() {
    vector<int> nums = {-1,1,0,-3,3};
    int n=nums.size();
    vector<int> p(n, 1);
    vector<int> q(n, 1);
    vector<int> r(n, 1);
    for(int i=0; i<n; i++) {
        p[i] = nums[i]*((i<1) ? 1 : p[i-1]);
    }
    for(int i=0; i<n; i++) {
        q[n-i-1] = nums[n-i-1]*((i<1) ? 1 : q[n-i]);
    }
    for(int i=0; i<n; i++) {
        r[i] = ((i<1) ? 1 : p[i-1])*((i>n-2) ? 1 : q[i+1]);
        cout << r[i] << endl;
    }
    return 0;
}