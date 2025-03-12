#include <bits/stdc++.h>
using namespace std;

int calculateHeight(vector<int> input, int k)
{
    sort(input.begin(), input.end());
    int n = input.size();
    int low = 1;
    int high = input[n - 1];
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int wood_collected = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (input[i] - mid <= 0)
                break;
            wood_collected += (input[i] - mid);
        }
        if (wood_collected == k)
        {
            return mid;
        }
        else if (wood_collected > k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> input{7, 4, 9, 2, 1, 8};
    int k = 3;
    cout << "The height at which one should cut the trees is " << calculateHeight(input, k) << endl;
    return 0;
}