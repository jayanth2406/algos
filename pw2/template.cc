#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    clock_t st = clock();
    // start
    int a, b;
    cin >> a >> b;
    cout << "Sum: " << a + b << endl;
    // end
    clock_t et = clock();
    double duration = double(et - st) / CLOCKS_PER_SEC;
    cout << "\nExecution Time: " << duration << " seconds\n";
}