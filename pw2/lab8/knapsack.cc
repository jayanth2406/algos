#include <bits/stdc++.h>
using namespace std;

int n, b;
int l[100], c[100];
int ans[100];
int mx = 0;

struct Node {
    int lvl, ben, cred;
    double bnd;
    int x[100];
};

bool cmp(int i, int j) {
    return (double)l[i]/c[i] > (double)l[j]/c[j];
}

double bnb(int lvl, int ben, int cred, vector<int>& ord) {
    double bnd = ben;
    int rem = b - cred;
    for (int i = lvl; i < n && rem > 0; i++) {
        int idx = ord[i];
        if (c[idx] <= rem) {
            rem -= c[idx];
            bnd += l[idx];
        } else {
            bnd += (double)l[idx] * rem / c[idx];
            break;
        }
    }
    return bnd;
}

void solve() {
    vector<int> ord(n);
    for (int i = 0; i < n; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), cmp);

    queue<Node> q;
    Node r = {0, 0, 0, bnb(0, 0, 0, ord)};
    fill(r.x, r.x + n, 0);
    q.push(r);

    while (!q.empty()) {
        Node u = q.front(); q.pop();
        if (u.lvl == n || u.bnd <= mx) continue;

        int i = ord[u.lvl];

        if (u.cred + c[i] <= b) {
            Node v = u;
            v.lvl++;
            v.cred += c[i];
            v.ben += l[i];
            v.x[i] = 1;
            v.bnd = bnb(v.lvl, v.ben, v.cred, ord);
            if (v.ben > mx) {
                mx = v.ben;
                copy(v.x, v.x + n, ans);
            }
            if (v.bnd > mx) q.push(v);
        }

        Node w = u;
        w.lvl++;
        w.bnd = bnb(w.lvl, w.ben, w.cred, ord);
        q.push(w);
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    string s;
    int cs = 0;
    while (getline(fin, s)) {
        if (s.find("Case") == string::npos) continue;

        cs++;
        getline(fin, s);
        sscanf(s.c_str(), "n = %d", &n);

        getline(fin, s);
        size_t st = s.find('[') + 1, en = s.find(']');
        stringstream sl(s.substr(st, en - st));
        for (int i = 0; i < n; i++) sl >> l[i], sl.ignore(1);

        getline(fin, s);
        st = s.find('[') + 1, en = s.find(']');
        stringstream sc(s.substr(st, en - st));
        for (int i = 0; i < n; i++) sc >> c[i], sc.ignore(1);

        getline(fin, s);
        sscanf(s.c_str(), "b = %d", &b);

        mx = 0;
        fill(ans, ans + 100, 0);
        solve();

        fout << "Case " << cs << ":\n";
        fout << "Optimal Course Selection:\n";
        for (int i = 0; i < n; i++)
            if (ans[i]) fout << "x" << i+1 << " = 1\n";
        fout << "Total Learning Benefit: " << mx << "\n\n";
    }

    fin.close();
    fout.close();
    return 0;
}
