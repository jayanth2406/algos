#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> subarraySum(vector<int> arr, int n, long long s)
    {
        // Your code here
        vector<int> sb;
        for (int i = 0; i < n; i++)
        {
            long long sum = 0;
            int j;
            
            if (sum == s)
            {
                sb.push_back(j + 1);
                sb.push_back(i + 1);
                return sb;
            }
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
    // int arr[n];
    const int mx = 1e9;
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