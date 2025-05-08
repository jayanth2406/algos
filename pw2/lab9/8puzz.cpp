#include <bits/stdc++.h>
using namespace std;


const vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const vector<string> dname = {"up", "down", "left", "right"};
ofstream fout("output.txt");

struct node {
    vector<vector<int>> curr;
    vector<string> p;
    int c = 0;
    int pr = 0;
};

string mat_to_str(const vector<vector<int>> &m) {
    string r;
    for (auto &row : m)
        for (int v : row) r += to_string(v);
    return r;
}

pair<int, int> find0(const vector<vector<int>> &m) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (m[i][j] == 0) return {i, j};
    return {-1, -1};
}

vector<vector<int>> move(vector<vector<int>> m, int d) {
    auto [x, y] = find0(m);
    int nx = x + dir[d].first, ny = y + dir[d].second;
    if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) return {};
    swap(m[x][y], m[nx][ny]);
    return m;
}

int mh(const vector<vector<int>> &m) {
    int t = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            int v = m[i][j];
            if (v == 0) continue;
            int gx = (v - 1) / 3, gy = (v - 1) % 3;
            t += abs(i - gx) + abs(j - gy);
        }
    return t;
}

void pr(string algo, vector<string> path, int exp) {
    fout << "algorithm: " << algo << '\n';
    fout << "path to goal: [";
    for (int i = 0; i < path.size(); i++) {
        fout << "'" << path[i] << "'";
        if (i != path.size() - 1) fout << ", ";
    }
    fout << "]\n";
    fout << "number of moves: " << path.size() << '\n';
    fout << "nodes expanded: " << exp << "\n\n";
    fout.flush();
}

void nosol(string algo) {
    fout << "algorithm: " << algo << '\n';
    fout << "no solution\n\n";
    fout.flush();
}

void bfs(vector<vector<int>> st, vector<vector<int>> g) {
    queue<node> q;
    set<string> vis;
    q.push({st, {}, 0});
    int ex = 0;

    while (!q.empty()) {
        auto u = q.front(); q.pop();
        string key = mat_to_str(u.curr);
        if (vis.count(key)) continue;
        vis.insert(key);
        ex++;
        if (u.curr == g) {
            pr("bfs", u.p, ex);
            return;
        }
        for (int i = 0; i < 4; i++) {
            vector<vector<int>> nxt = move(u.curr, i);
            if (!nxt.empty()) {
                auto np = u.p;
                np.push_back(dname[i]);
                q.push({nxt, np, u.c + 1});
            }
        }
    }
    nosol("bfs");
}

void dfs(vector<vector<int>> st, vector<vector<int>> g, int lim) {
    stack<node> stk;
    set<string> vis;
    stk.push({st, {}, 0});
    int ex = 0;

    while (!stk.empty()) {
        auto u = stk.top(); stk.pop();
        string key = mat_to_str(u.curr);
        if (vis.count(key)) continue;
        vis.insert(key);
        ex++;
        if (u.curr == g) {
            pr("dfs", u.p, ex);
            return;
        }
        if (u.c >= lim) continue;
        for (int i = 3; i >= 0; i--) {
            vector<vector<int>> nxt = move(u.curr, i);
            if (!nxt.empty()) {
                auto np = u.p;
                np.push_back(dname[i]);
                stk.push({nxt, np, u.c + 1});
            }
        }
    }
    nosol("dfs");
}

void astar(vector<vector<int>> st, vector<vector<int>> g) {
    auto cmp = [](const node &a, const node &b) { return a.pr > b.pr; };
    priority_queue<node, vector<node>, decltype(cmp)> pq(cmp);
    set<string> vis;
    pq.push({st, {}, 0, mh(st)});
    int ex = 0;

    while (!pq.empty()) {
        auto u = pq.top(); pq.pop();
        string key = mat_to_str(u.curr);
        if (vis.count(key)) continue;
        vis.insert(key);
        ex++;
        if (u.curr == g) {
            pr("astar", u.p, ex);
            return;
        }
        for (int i = 0; i < 4; i++) {
            vector<vector<int>> nxt = move(u.curr, i);
            if (!nxt.empty()) {
                int g1 = u.c + 1;
                int h = mh(nxt);
                auto np = u.p;
                np.push_back(dname[i]);
                pq.push({nxt, np, g1, g1 + h});
            }
        }
    }
    nosol("astar");
}

void ucs(vector<vector<int>> st, vector<vector<int>> g) {
    auto cmp = [](const node &a, const node &b) { return a.c > b.c; };
    priority_queue<node, vector<node>, decltype(cmp)> pq(cmp);
    set<string> vis;
    pq.push({st, {}, 0});
    int ex = 0;

    while (!pq.empty()) {
        auto u = pq.top(); pq.pop();
        string key = mat_to_str(u.curr);
        if (vis.count(key)) continue;
        vis.insert(key);
        ex++;
        if (u.curr == g) {
            pr("ucs", u.p, ex);
            return;
        }
        for (int i = 0; i < 4; i++) {
            vector<vector<int>> nxt = move(u.curr, i);
            if (!nxt.empty()) {
                auto np = u.p;
                np.push_back(dname[i]);
                pq.push({nxt, np, u.c + 1});
            }
        }
    }
    nosol("ucs");
}

bool rd(ifstream &fin, vector<vector<int>> &m) {
    string l;
    for (int i = 0; i < 3; i++) {
        if (!getline(fin, l)) return false;
        istringstream in(l);
        for (int j = 0; j < 3; j++)
            if (!(in >> m[i][j])) return false;
    }
    return true;
}

int main() {
    ifstream fin("input.txt");
    if (!fin.is_open()) {
        cerr << "input.txt not found.\n";
        return 1;
    }

    string l;
    while (getline(fin, l)) {
        if (l.empty()) continue;
        if (l[0] == '#') fout << l << "\n";

        getline(fin, l);
        vector<vector<int>> ini(3, vector<int>(3));
        if (!rd(fin, ini)) continue;

        getline(fin, l);
        vector<vector<int>> g(3, vector<int>(3));
        if (!rd(fin, g)) continue;

        getline(fin, l);

        bfs(ini, g);
        dfs(ini, g, 15);
        astar(ini, g);
        ucs(ini, g);
    }

    fout.close();
    return 0;
}
