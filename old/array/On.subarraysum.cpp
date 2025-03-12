#include <iostream>
#include <vector>
using namespace std;

/// https://www.geeksforgeeks.org/find-subarray-with-given-sum/
/// @problem: Given an unsorted array A of size N that contains only non negative integers, 
/// find a continuous sub-array that adds to a given number S and return the left and right 
/// index(1-based indexing) of that subarray. In case of multiple subarrays, return the subarray 
/// indexes which come first on moving from left to right.Note:- You have to return an ArrayList 
/// consisting of two elements left and right. In case no such subarray exists return an array 
/// consisting of element -1.
/// @example 1:
/// Input:
/// N = 5, S = 12
/// A[] = {1,2,3,7,5}
/// Output: 2 4
/// Explanation: The sum of elements from 2nd position to 4th position is 12.
///
/// @expected: Time Complexity: O(N)
/// @expected: Auxiliary Space: O(1)

class Solution
{
public:
    vector<int> subarraySum(vector<int> arr, int n, long long s)
    {
        vector<int> sb;
        int f=0, e=0;
        long long sum=0;
        while(e<n){
            sum+=arr[e];
            while(sum>s && e>f){
                sum-=arr[f];
                f++;
            }
            if(s==sum){
                sb.push_back(f+1);
                sb.push_back(e+1);
                return sb;
            }
            e++;
        }
        sb.push_back(-1);
        return sb;
    }
};

int main()
{
    int n;
    long long s;
    cin >> n >> s;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution ob;
    vector<int> res;
    res = ob.subarraySum(arr, n, s);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}
/*
    explanation:
    The active selection is a C++ program that finds a subarray of a given array whose sum is 
    equal to a specified value. The program uses a sliding window approach to solve this problem.

    Inside the subarraySum method, a vector sb is declared to store the result. Two integer 
    variables f(first) and e(last) are initialized to 0 to represent the start and end of the 
    sliding window, respectively. A long long integer sum is initialized to 0 to keep track of the 
    current sum of the elements in the sliding window.

    The method then enters a while loop that continues until e is less than n. Inside this loop, 
    the element at index e of arr is added to sum. Then, a nested while loop is entered if sum is 
    greater than s and e is greater than f. This loop subtracts the element at index f of arr from 
    sum and increments f, effectively sliding the window to the right.

    If sum is equal to s, the method pushes f+1 and e+1 into sb and returns sb. The indices are 
    incremented by 1 because the problem assumes 1-based indexing. If no such subarray is found 
    after the loop, the method pushes -1 into sb and returns sb to indicate that no such subarray 
    exists.

*/