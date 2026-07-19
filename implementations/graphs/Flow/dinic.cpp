struct Edge {
	int v, ref;
	ll cap;
	Edge() {}
	Edge(int v, int ref, ll cap) : v(v), ref(ref), cap(cap) {}
};

struct Dinic {
	vector<Edge> G[MAXN];
	int S=0, T=0;
	int lev[MAXN], nxt[MAXN];

	void build(int V, int s, int t) {
		for (int i = 0; i < V; i++) G[i].clear();
		S = s; T = t;
	}

	void addEdge(int u, int v, ll cap) {
		G[u].emplace_back(v, G[v].size(), cap);
		G[v].emplace_back(u, G[u].size()-1, 0);
	}

	bool bfs() {
		memset(lev, 0, sizeof(lev));
		lev[S] = 1;
		queue<int> q;
		q.push(S);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (auto [v, _, cap] : G[u]) {
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
		return 0LL;
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
