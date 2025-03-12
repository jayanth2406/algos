#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
	void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)	{
		vis[node] = 1;
		for (auto it : adj[node]) {
			if (!vis[it]) {
				dfs(it, vis, adj, st);
			}
		}
		st.push(node);
	}

	void dfs2(int node, vector<int> &vis, vector<int> adjT[]) {
		vis[node] = 1;
		cout << node << " ";
		for (auto it : adjT[node]) {
			if (!vis[it]) {
				dfs2(it, vis, adjT);
			}
		}
	}

public:
	int kosaraju(int V, vector<int> adj[])
	{
		vector<int> vis(V, 0);
		stack<int> st;
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				dfs(i, vis, adj, st);
			}
		}

		vector<int> adjT[V];
		for (int i = 0; i < V; i++)	{
			vis[i] = 0;
			for (auto it : adj[i]) {
				adjT[it].push_back(i);
			}
		}
		
		int scc =0;
		while (!st.empty()) {
			int node = st.top();
			st.pop();
			if (!vis[node])	{
				cout << "SCC: ";
				dfs2(node, vis, adjT);
				cout << endl;
				scc++;
			}
		}
		return scc;		
	}
};

int main() {
	vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	int V = 11;
	Solution obj;
	int ans = obj.kosaraju(V, adj);
	cout << ans << endl;
	return 0;
}