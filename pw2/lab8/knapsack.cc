#include <bits/stdc++.h>
using namespace std;

int n, b;
int l[100], c[100];
int ans[100];
int maxSum = 0;

struct Node {
    int level, benefit, credit;
    double bound;
    int x[100];
};

bool cmpRatio(int i, int j) {
    return (double)l[i]/c[i] > (double)l[j]/c[j];
}

double getBound(int level, int benefit, int credit, vector<int>& order) {
    double bound = benefit;
    int rem = b - credit;
    for (int i = level; i < n && rem > 0; i++) {
        int idx = order[i];
        if (c[idx] <= rem) {
            rem -= c[idx];
            bound += l[idx];
        } else {
            bound += (double)l[idx] * rem / c[idx];
            break;
        }
    }
    return bound;
}

void branchAndBound() {
    vector<int> order(n);
    for (int i = 0; i < n; i++) order[i] = i;
    sort(order.begin(), order.end(), cmpRatio);

    queue<Node> q;
    Node root = {0, 0, 0, getBound(0, 0, 0, order)};
    fill(root.x, root.x + n, 0);
    q.push(root);

    while (!q.empty()) {
        Node u = q.front(); q.pop();
        if (u.level == n || u.bound <= maxSum) continue;

        int i = order[u.level];

        // Include course
        if (u.credit + c[i] <= b) {
            Node v = u;
            v.level++;
            v.credit += c[i];
            v.benefit += l[i];
            v.x[i] = 1;
            v.bound = getBound(v.level, v.benefit, v.credit, order);
            if (v.benefit > maxSum) {
                maxSum = v.benefit;
                copy(v.x, v.x + n, ans);
            }
            if (v.bound > maxSum) q.push(v);
        }

        // Exclude course
        Node w = u;
        w.level++;
        w.bound = getBound(w.level, w.benefit, w.credit, order);
        q.push(w);
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    string line;
    int caseNum = 0;
    while (getline(fin, line)) {
        if (line.find("Case") == string::npos) continue;

        caseNum++;
        // Read "n = X"
        getline(fin, line);
        sscanf(line.c_str(), "n = %d", &n);

        // Read "L = [....]"
        getline(fin, line);
        size_t start = line.find('[') + 1;
        size_t end = line.find(']');
        string Lvalues = line.substr(start, end - start);
        stringstream lss(Lvalues);
        for (int i = 0; i < n; i++) lss >> l[i], lss.ignore(1); // skip comma

        // Read "C = [....]"
        getline(fin, line);
        start = line.find('[') + 1;
        end = line.find(']');
        string Cvalues = line.substr(start, end - start);
        stringstream css(Cvalues);
        for (int i = 0; i < n; i++) css >> c[i], css.ignore(1); // skip comma

        // Read "b = X"
        getline(fin, line);
        sscanf(line.c_str(), "b = %d", &b);

        maxSum = 0;
        fill(ans, ans + 100, 0);
        branchAndBound();

        fout << "Case " << caseNum << ":\n";
        fout << "Optimal Course Selection:\n";
        for (int i = 0; i < n; i++)
            if (ans[i]) fout << "x" << i+1 << " = 1\n";
        fout << "Total Learning Benefit: " << maxSum << "\n\n";
    }

    fin.close();
    fout.close();
    return 0;
}

