#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
const int MAXN = 501, INF = 1e9 + 1;
int N;
struct Edge {
	int v, ref;
	ll cap;
	Edge() {}
	Edge(int v, int ref, ll cap) : v(v), ref(ref), cap(cap) {}
};

struct Dinic {
	int S, T;
	vector<Edge> G[MAXN];
	int lev[MAXN], nxt[MAXN];

	void addEdge(int u, int v, ll cap) {
		G[u].emplace_back(v, (int)G[v].size(), cap);
		G[v].emplace_back(u, (int)G[u].size()-1, 0LL);
	}

	bool bfs() {
		memset(lev, 0, sizeof(lev));
		queue<int> q;
		lev[S] = 1;
		q.push(S);

		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (auto [v,cap,_] : G[u]) {
				if (!lev[v] && cap) {
					lev[v] = lev[u] + 1;
					q.push(v);
				}
			}
		}
		return lev[T];
	}

	ll dfs(int u, ll inflow) {
		if (u == T) return inflow;

		for (int& i = nxt[u]; i < G[u].size(); i++) {
			auto& [v, ref, cap] = G[u][i];
			if (lev[u] + 1 == lev[v] && cap) {
				ll flow = dfs(v, min(inflow, cap));
				if (flow) {
					cap -= flow;
					G[v][ref].cap += flow;
					return flow;
				}
			}
		}
		return 0;
	}

	ll getFlow() {
		ll ans = 0;
		while (bfs()) {
			memset(nxt, 0, sizeof(nxt));
			ll flow;
			while (flow = dfs(S, INF)) ans += flow;
		}
		return ans;
	}
} flow;
