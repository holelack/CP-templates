#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
const int MAXN = 1e6 + 1;
int N, M;
vector<int> G[MAXN];

int disc[MAXN], low[MAXN], cut[MAXN];
int dfsn = 0;
int dfs(int u, int p = 0) {
	disc[u] = low[u] = ++dfsn;
	int child = 0;
	for (int v : G[u]) {
		if (disc[v]) low[u] = min(low[u], disc[v]); // back edge
		else {
			low[u] = min(low[u], dfs(v,u)); // tree edge
			// point: <=, edge: <
			if (disc[u] <= low[v] && p) cut[u] = 1; // 단절점 조건
			child++;
		}
	}
	if (p == 0 && child >= 2) cut[u] = 1; // root exception
	return low[u];
}

void init() {
	fastio();
	cin >> N >> M;
	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
}

int main() {
	init();
	for (int u = 1; u <= N; u++) if (!disc[u]) dfs(u);
	for (int u = 1; u <= N; u++) if (cut[u]) cout << u << " ";

	return 0;
}
