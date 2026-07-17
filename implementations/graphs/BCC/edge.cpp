#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
const int MAXN = 1e6 + 1;
int N, M;
struct Edge {
	int v, id;
	Edge() {}
	Edge(int v, int id) : v(v), id(id) {}
};
vector<Edge> G[MAXN];
int disc[MAXN], low[MAXN], cut[MAXN], ID[MAXN];
int dfsn = 0;

int dfs(int u, int p = 0) {
	disc[u] = low[u] = ++dfsn;
	for (auto [v,id] : G[u]) {
		if (v == p) continue;
		if (disc[v]) low[u] = min(low[u], disc[v]);
		else {
			low[u] = min(low[u], dfs(v, u));
			if (disc[u] < low[v]) cut[id] = 1;
		}
	}
	return low[u];
}

int bccid = 0;
void dfs2(int u, int p = 0) {
	if (!p) bccid++;
	ID[u] = bccid;
	for (auto [v, id] : G[u]) {
		if (cut[id] || ID[v]) continue;
		dfs2(v, u);
	}
}

void init() {
	fastio();
	cin >> N >> M;
	int u, v;
	for (int i = 1; i <= M; i++) {
		cin >> u >> v;
		G[u].push_back(Edge(v,i));
		G[v].push_back(Edge(u,i));
	}
}

int main() {
	init();

	for (int u = 1; u <= N; u++) if (!disc[u]) dfs(u);
	for (int u = 1; u <= N; u++) if (!ID[u]) dfs2(u);

	return 0;
}
