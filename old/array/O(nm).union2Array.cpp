#include <iostream>
#include <map>
#include <set>
using namespace std;

/// https://www.geeksforgeeks.org/union-and-intersection-of-two-sorted-arrays-2/
/// @brief: Using  "Balanced Binary Search Tree" (often a "Red-Black Tree").
/// @brief: The time complexity of this solution is O(n+m) and the space complexity is O(n+m).
/// Used in map or set in C++ from std library.

class Solution
{
public:
    int doUnion(int a[], int n, int b[], int m)
    {
        /// Using map to store the values of both the arrays.
        map<int, int> val;
        for (int i = 0; i < n; i++)
        {
            val.insert({a[i], i});
        }
        for (int i = 0; i < m; i++)
        {
            val.insert({b[i], i});
        }
        return val.size();
        /// Using set to store the values of both the arrays.
        // set<int> val;
        // for (int i = 0; i < n; i++)
        // {
        //     val.insert({a[i], i});
        // }
        // for (int i = 0; i < m; i++)
        // {
        //     val.insert({b[i], i});
        // }
        // return val.size();
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    int* a = new int[n];
    int* b = new int[m];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];
    Solution ob;
    cout << ob.doUnion(a, n, b, m) << endl;
    delete[] a;
    delete[] b;
    return 0;
}