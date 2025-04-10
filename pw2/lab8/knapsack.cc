#include <bits/stdc++.h>
using namespace std;

int n, b;
int l[100], c[100];
double ratio[100];
int ans[100];
int maxSum = 0;

void solve(int i, int sum, int rem, int x[]) {
    if (i == n) {
        if (sum > maxSum) {
            maxSum = sum;
            for (int j = 0; j < n; j++) ans[j] = x[j];
        }
        return;
    }

    if (c[i] <= rem) {
        x[i] = 1;
        solve(i+1, sum + l[i], rem - c[i], x);
        x[i] = 0;
    }
    solve(i+1, sum, rem, x);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> l[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    cin >> b;

    int x[100] = {0};
    solve(0, 0, b, x);

    cout << "Optimal Course Selection:\n";
    for (int i = 0; i < n; i++)
        if (ans[i]) cout << "x" << i+1 << " = 1\n";

    cout << "Total Learning Benefit: " << maxSum << "\n";
    return 0;
}
