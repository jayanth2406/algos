#include <bits/stdc++.h>
using namespace std;

struct Node {
    vector<vector<int64_t>> matrix;
    int64_t cost, level, city;
    vector<int64_t> path;
    bool operator>(const Node &n) const { return cost > n.cost; }
};

int64_t hungarian(int64_t n, vector<vector<int64_t>> &mat) {
    int64_t cost = 0;
    for (int64_t i = 0; i < n; i++) {
        int64_t rMin = *min_element(mat[i].begin(), mat[i].end());
        if (rMin != 1e9) cost += rMin;
        for (int64_t j = 0; j < n; j++) if (mat[i][j] != 1e9) mat[i][j] -= rMin;
    }
    for (int64_t j = 0; j < n; j++) {
        int64_t cMin = 1e9;
        for (int64_t i = 0; i < n; i++) cMin = min(cMin, mat[i][j]);
        if (cMin != 1e9) cost += cMin;
        for (int64_t i = 0; i < n; i++) if (mat[i][j] != 1e9) mat[i][j] -= cMin;
    }
    return cost;
}

pair<vector<int64_t>, int64_t> f(int64_t n, vector<vector<int64_t>> mat) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({mat, hungarian(n, mat), 0, 0, {0}});

    int64_t optCost = 1e9;
    vector<int64_t> optPath;

    while (!pq.empty()) {
        Node cur = pq.top(); pq.pop();
        if (cur.cost >= optCost) continue;

        if (cur.level == n - 1) {
            int64_t tc = cur.cost + mat[cur.city][0];
            if (tc < optCost) optCost = tc, optPath = cur.path, optPath.push_back(0);
            continue;
        }

        for (int64_t i = 0; i < n; i++) if (find(cur.path.begin(), cur.path.end(), i) == cur.path.end()) {
            vector<vector<int64_t>> nMat = cur.matrix;
            for (int64_t j = 0; j < n; j++) nMat[cur.city][j] = nMat[j][i] = 1e9;
            nMat[i][0] = 1e9;

            int64_t nCost = cur.cost + mat[cur.city][i] + hungarian(n, nMat);
            vector<int64_t> nPath = cur.path; nPath.push_back(i);

            if (nCost < optCost) pq.push({nMat, nCost, cur.level + 1, i, nPath});
        }
    }
    return {optPath, optCost};
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int64_t n;
    while (cin >> n) {
        clock_t st = clock();
        vector<vector<int64_t>> m(n, vector<int64_t>(n));

        for (int64_t i = 0; i < n; i++)
            for (int64_t j = 0; j < n; j++) {
                cin >> m[i][j];
                if (i == j) m[i][j] = 1e9;
            }

        auto [path, cost] = f(n, m);
        for (int64_t i = 0; i < path.size(); i++)
            cout << path[i] + 1 << (i < path.size() - 1 ? " -> " : "\t");

        cout << "Minimum Cost: " << cost << "\t";

        clock_t et = clock();
        cout << "Execution Time: " << fixed << setprecision(6) 
             << double(et - st) / CLOCKS_PER_SEC << " seconds\n";
    }
}
