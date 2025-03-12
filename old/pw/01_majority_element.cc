#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    for (auto x : freq)
    {
        if (x.second > n / 2)
        {
            cout << x.first << "\n";
            return 0;
        }
    }
    cout << "No majority element";
    return 0;
}