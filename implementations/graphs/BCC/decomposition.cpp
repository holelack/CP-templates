#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
const int MAXN = 1e6 + 1;
int N, M;
vector<int> G[MAXN];

int disc[MAXN], low[MAXN], cut[MAXN];
vector<vector<pii>> BCC;
stack<pii> stk;
int dfsn = 0;
int dfs(int u, int p = 0) {
	disc[u] = low[u] = ++dfsn;
	for (int v : G[u]) {
		if (v == p) continue;
		if (!disc[v]) { // tree edge
			stk.push(pii(u, v));
			low[u] = min(low[u], dfs(v, u));
			if (disc[u] <= low[v]) {
				BCC.emplace_back();
				pii e;
				do {
					e = stk.top(); stk.pop();
					BCC.back().emplace_back(e);
				} while (e != pii(u, v));
			}
		}
		else if (disc[v] < disc[u]) { // back edge -> 한 방향으로만(v<-u)
			stk.push(pii(u, v));
			low[u] = min(low[u], disc[v]);
		}
	}
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

	return 0;
}
