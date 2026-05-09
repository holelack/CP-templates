#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
const ll MAXN = 1e6 + 1, INF = 1e18;
int N, M;

struct Edge {
	ll v, w;
	Edge() {}
	Edge(ll v, ll w) : v(v), w(w) {}
	bool operator<(const Edge& other) const {
		return (w != other.w) ? w > other.w : v > other.v;
	}
};

vector<Edge> adj[MAXN];
priority_queue<Edge> pq;
ll dist[MAXN];

void init() {
	fastio();
	cin >> N >> M;
	int u, v, w;
	while (M--) {
		cin >> u >> v >> w;
		adj[u].emplace_back(Edge(v, w));
		adj[v].emplace_back(Edge(u, w));
	}
}

void getDist(int source) {
	fill(dist, dist + N + 1, INF);
	dist[source] = 0;
	pq.push(Edge(source, 0));
	while (!pq.empty()) {
		auto [u, d] = pq.top(); pq.pop();
		if (d > dist[u]) continue;

		for (Edge e : adj[u]) {
			auto [v, w] = e;
			
			if (d + w >= dist[v]) continue;
			dist[v] = d + w;
			pq.push(Edge(v, d + w));
		}
	}
}


int main() {
	init();
	getDist();

	return 0;
}
