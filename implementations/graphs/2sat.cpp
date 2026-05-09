#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
const int MAXN = 1e6 + 1, MAXM = 1e6 + 1;
int N, M;

vector<int> adj[MAXN<<1];

vector<vector<int>> SCC;
int low[MAXN << 1], disc[MAXN << 1], visited[MAXN << 1], ID[MAXN << 1];
stack<int> stk;
int dfsn = 0, sccid = 0;

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
		sccid++;
		while (!stk.empty()) {
			int v = stk.top(); stk.pop();
			visited[v] = true;
			SCC.back().push_back(v);
			ID[v] = sccid;
			if (u == v) break;
		}
	}
}

void addClause(int u, int v) {
	adj[u ^ 1].push_back(v);
	adj[v ^ 1].push_back(u);
}

bool SAT[MAXN];

bool solveSAT() {
	for (int i = 1; i <= N; i++) {
		if (ID[i<<1] == ID[i<<1|1]) return false;
	}

	for (int i = 1; i <= N; i++) {
		SAT[i] = ID[i<1] < ID[i<<1|1] ? true : false;
	}

	return true;
}

void init() {
	fastio();
	cin >> N >> M;
	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		addClause(u<<1, v<<1);
	}

	memset(low, 0, sizeof(low));
	memset(disc, 0, sizeof(disc));
	memset(visited, 0, sizeof(visited));
}

int main() {
	init();
	for (int u = 2; u <= (N<<1|1); u++) {
		if (!disc[u]) dfs(u);
	}
  solveSAT();

	return 0;
}
