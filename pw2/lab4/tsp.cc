#include <bits/stdc++.h>
using namespace std;

struct N {
    vector<vector<int>> m;
    int c, l, ct;
    vector<int> p;
    set<int> v;
    bool operator>(const N &o) const { return c > o.c; }
};

int h(int n, vector<vector<int>> &mat) {
    int c = 0;
    for (int i = 0; i < n; i++) {
        int rMin = *min_element(mat[i].begin(), mat[i].end());
        if (rMin < 1e9) {
            c += rMin;
            for (int j = 0; j < n; j++) if (mat[i][j] < 1e9) mat[i][j] -= rMin;
        }
    }
    for (int j = 0; j < n; j++) {
        int cMin = 1e9;
        for (int i = 0; i < n; i++) cMin = min(cMin, mat[i][j]);
        if (cMin < 1e9) {
            c += cMin;
            for (int i = 0; i < n; i++) if (mat[i][j] < 1e9) mat[i][j] -= cMin;
        }
    }
    return c;
}

pair<vector<int>, int> tsp(int n, vector<vector<int>> mat) {
    priority_queue<N, vector<N>, greater<N>> pq;
    pq.push({mat, h(n, mat), 0, 0, {0}, {0}});

    int optC = 1e9;
    vector<int> optP;

    while (!pq.empty()) {
        N cur = pq.top(); pq.pop();
        if (cur.c >= optC) continue;

        if (cur.l == n - 1) {
            int tC = cur.c + cur.m[cur.ct][0];
            if (tC < optC) {
                optC = tC;
                optP = cur.p;
                optP.push_back(0);
            }
            continue;
        }

        for (int i = 0; i < n; i++) if (!cur.v.count(i)) {
            vector<vector<int>> newM = cur.m;
            for (int j = 0; j < n; j++) newM[cur.ct][j] = 1e9;
            for (int j = 0; j < n; j++) newM[j][i] = 1e9;
            newM[i][cur.ct] = 1e9;

            int eC = cur.m[cur.ct][i];
            if (eC < 1e9) {
                int newC = cur.c - h(n, cur.m) + eC + h(n, newM);
                vector<int> newP = cur.p; newP.push_back(i);
                set<int> newV = cur.v; newV.insert(i);

                if (newC < optC) pq.push({newM, newC, cur.l + 1, i, newP, newV});
            }
        }
    }
    return {optP, optC};
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    while (cin >> n) {
        clock_t st = clock();
        vector<vector<int>> m(n, vector<int>(n));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
                if (i == j) m[i][j] = 1e9;
            }

        auto [p, c] = tsp(n, m);
        cout << "OptimalTour: ";
        for (size_t i = 0; i < p.size(); i++)
            cout << p[i] + 1 << (i < p.size() - 1 ? " -> " : "");

        cout << "\nMinimumCost: " << c << "\n";

        clock_t et = clock();
        cout << "Execution Time: " << fixed << setprecision(6) 
             << double(et - st) / CLOCKS_PER_SEC << " seconds\n";
    }
}
