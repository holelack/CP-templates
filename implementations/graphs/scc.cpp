#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
const int MAXN = 1e6 + 1, MAXM = 1e6 + 1;
int N, M;

vector<int> adj[MAXN];

vector<vector<int>> SCC;
int low[MAXN], disc[MAXN], visited[MAXN];
stack<int> stk;
int dfsn = 0;

void dfs(int u) {
	visited[u] = 1;
	stk.push(u);
	disc[u] = low[u] = ++dfsn;

	for (int v : adj[u]) {
		if (!disc[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else if (visited[v]) low[u] = min(low[u], disc[v]);
	}

	if (low[u] == disc[u]) {
		SCC.emplace_back();
		while (!stk.empty()) {
			int v = stk.top(); stk.pop();
			visited[v] = true;
			SCC.back().push_back(v);
			if (u == v) break;
		}
	}
}

void init() {
	fastio();
	cin >> N >> M;
	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
	}
}

int main() {
	init();

	return 0;
}
