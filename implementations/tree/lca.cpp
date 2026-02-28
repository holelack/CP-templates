#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
const int MAXN = 1e5 + 1, MAXD = 19;
int n, m;
int parent[MAXN][MAXD], dep[MAXN];
vector<int> adj[MAXN];

void dfs(int u, int p) {
	parent[u][0] = p;
	for (int v : adj[u]) {
		if (v == p) continue;
		dep[v] = dep[u] + 1;
		dfs(v, u);
	}
}

void getTable() {
	for (int depth = 1; depth < MAXD; depth++) {
		for (int u = 1; u <= n; u++) {
			parent[u][depth] = parent[parent[u][depth - 1]][depth - 1];
		}
	}
}

void init() {
	fastio();
	cin >> n;
	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	memset(dep, 0, sizeof(dep));
	dfs(1, 0);
	getTable();
}


int lca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);

	for (int depth = MAXD - 1; depth >= 0; depth--) {
		if (!parent[a][depth]) continue;
		if (dep[a] - (1 << depth) >= dep[b]) {
			a = parent[a][depth];
		}
	}

	if (a == b) return a;

	for (int depth = MAXD - 1; depth >= 0; depth--) {
		if (!parent[a][depth]) continue;
		if (parent[a][depth] != parent[b][depth]) {
			a = parent[a][depth];
			b = parent[b][depth];
		}
	}

	return parent[a][0];
}

void query() {
	cin >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}
}

int main() {
	init();
	query();

	return 0;
}
