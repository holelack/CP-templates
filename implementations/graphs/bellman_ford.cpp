#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
const ll MAXN = 1e3 + 1, MAXM = 1e3 + 1, INF = 1e18;
int N, M;

struct Edge {
	ll u, v, w;
	Edge() {}
	Edge(ll u, ll v, ll w) : u(u), v(v), w(w) {}
};

ll dist[MAXN];
vector<Edge> E;

void init() {
	fastio();
	cin >> N >> M;
	ll u, v, w;
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;
		E.emplace_back(Edge(u, v, w));
	}
}

bool getDist(int source) {
	fill(dist, dist + N + 1, INF);
	dist[source] = 0;

	for (int i = 1; i <= N; i++) {
		for (auto [u, v, w] : E) {
			if (dist[u] != INF && dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				if (i == N) return true;
			}
		}
	}
	return false;
}

int main() {
	init();


	return 0;
}
