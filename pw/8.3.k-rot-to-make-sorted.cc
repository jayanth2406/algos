#include <bits/stdc++.h>
using namespace std;

int rotationCount(vector<int>& arr, int low, int high) {
    if (arr[low] < arr[high]) return 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int next = (mid + 1) % arr.size();
        int prev = (mid + arr.size() - 1) % arr.size();
        if (arr[mid] <= arr[next] && arr[mid] <= arr[prev]) return mid;
        else if (arr[mid] <= arr[high]) high = mid - 1;
        else if (arr[0] <= arr[mid]) low = mid + 1;
    }
    return -1;
}

int main()
{
    vector<int> a = {15, 18, 2, 3, 6, 12};
    int n = a.size();

    int rotations = rotationCount(a, 0, n - 1);
    cout << "Number of rotations: " << rotations << endl;
    return 0;
}