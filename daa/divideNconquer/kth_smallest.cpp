#include<bits/stdc++.h>
using namespace std;

/***
 * @problem: Find the kth smallest element in an array in O(n) time
 * @pseudo_code:
 * 1. Divide the array into groups of 5 elements each
 * 2. Find the median of each group
 * 3. Recursively find the median of all medians
 * 4. Partition the array around the median of medians
 * 5. Recursively find the kth smallest element in the left or right partition
 * 6. Return the kth smallest element
 * 
 * @time_complexity: O(n)
 * @space_complexity: O(1)
 */

int findMedian(vector<int> &arr, int n) {
    sort(arr.begin(), arr.end());
    return arr[n/2];
}

int partition(vector<int> &arr, int l, int r, int x) {
    int i;
    for(i=l; i<r; i++) {
        if(arr[i] == x) break;
    }
    swap(arr[i], arr[r]);
    i = l;
    for(int j=l; j<=r-1; j++) {
        if(arr[j] <= x) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int kthSmallest(vector<int> &arr, int l, int r, int k) {
    if(k > 0 && k <= r-l+1) {
        int n = r-l+1;
        vector<int> median((n+4)/5);
        int i;
        for(i=0; i<n/5; i++) {
            median[i] = findMedian(vector<int>(arr.begin()+l+i*5, arr.begin()+l+i*5+5), 5);
        }
        if(i*5 < n) {
            median[i] = findMedian(vector<int>(arr.begin()+l+i*5, arr.begin()+l+i*5+n%5), n%5);
            i++;
        }
        int medOfMed = (i == 1) ? median[i-1] : kthSmallest(median, 0, i-1, i/2);
        int pos = partition(arr, l, r, medOfMed);
        if(pos-l == k-1) return arr[pos];
        if(pos-l > k-1) return kthSmallest(arr, l, pos-1, k);
        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }
    return INT_MAX;
}

int main() {
    vector<int> arr = {12, 3, 5, 7, 4, 19, 26};
    int n = arr.size();
    int k = 3;
    cout << kthSmallest(arr, 0, n-1, k) << endl;
    return 0;
}