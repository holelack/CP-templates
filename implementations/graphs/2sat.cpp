#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
const int MAXN = 1e6 + 1;
int N, M;
vector<int> G[MAXN << 1];

int low[MAXN << 1], disc[MAXN << 1], visited[MAXN << 1], ID[MAXN<<1];
stack<int> stk;
int dfsn = 0, sccid = 0;

int dfs(int u) {
	disc[u] = low[u] = ++dfsn;
	visited[u] = 1;
	stk.push(u);
	for (int v : G[u]) {
		if (!disc[v]) low[u] = min(low[u], dfs(v));
		else if (visited[v]) low[u] = min(low[u], disc[v]);
	}
	if (low[u] == disc[u]) {
		sccid++;
		int v;
		do {
			v = stk.top(); stk.pop();
			visited[v] = 0;
			ID[v] = sccid;
		} while (u != v);
	}
	return low[u];
}

void addEdge(int u, int v) {
	G[u ^ 1].push_back(v);
	G[v ^ 1].push_back(u);
}

void init() {
	fastio();
	cin >> N >> M;
	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v; u--; v--;
		addEdge(u << 1, v << 1);
	}

	for (int i = 0; i < (N << 1); i++) {
		if (!disc[i]) dfs(i);
	}
}

bool sat[MAXN];
int main() {
	init();
	
	for (int i = 0; i < N; i++) {
		sat[i] = ID[i << 1] < ID[i << 1 | 1];
	}

	return 0;
}
