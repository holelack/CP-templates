#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
const int MAXN = 3e5 + 1;
int N, Q;
vector<int> adj[MAXN];
int P[MAXN], sz[MAXN], dep[MAXN], top[MAXN], S[MAXN], E[MAXN];

struct Seg {
	ll tree[MAXN << 2], lazy[MAXN << 2];

	void build() {
		fill(tree, tree + ((N + 1) << 2), 0);
		fill(lazy, lazy + ((N + 1) << 2), 0);
	}

	void prop(int s, int e, int node) {
		if (!lazy[node]) return;
		tree[node] += (e - s + 1) * lazy[node];
		if (s != e) {
			lazy[node << 1] += lazy[node];
			lazy[node<<1|1] += lazy[node];
		}
		lazy[node] = 0;
	}

	void update(int l, int r, int v, int s = 1, int e = N, int node = 1) {
		prop(s, e, node);
		if (r < s || e < l) return;
		if (l <= s && e <= r) {
			lazy[node] += v;
			prop(s, e, node);
			return;
		}
		int mid = (s + e) >> 1;
		update(l, r, v, s, mid, node << 1);
		update(l, r, v, mid + 1, e, node << 1 | 1);
		tree[node] = tree[node << 1] + tree[node << 1 | 1];
	}

	ll query(int l, int r, int s = 1, int e = N, int node = 1) {
		prop(s, e, node);
		if (r < s || e < l) return 0;
		if (l <= s && e <= r) return tree[node];
		int mid = (s + e) >> 1;
		return query(l, r, s, mid, node << 1) + query(l, r, mid + 1, e, node << 1 | 1);
	}
} seg;

void dfs1(int u, int p) {
	sz[u] = 1;
	P[u] = p;
	for (int& v : adj[u]) {
		if (v == p) continue;
		dep[v] = dep[u] + 1;
		dfs1(v, u);
		sz[u] += sz[v];
		if (sz[v] > sz[adj[u][0]]) swap(v, adj[u][0]);
	}
}

int dfsn = 0;
void dfs2(int u, int p) {
	S[u] = ++dfsn;
	for (int v : adj[u]) {
		if (v == p) continue;
		top[v] = (v == adj[u][0] ? top[u] : v);
		dfs2(v, u);
	}
	E[u] = dfsn;
}

ll query(int a, int b) {
	int ret = 0;
	while (top[a] != top[b]) {
		if (dep[top[a]] > dep[top[b]]) swap(a, b);
		int c = top[b];
		ret += seg.query(S[c], S[b]);
		b = P[c];
	}
	if (dep[a] > dep[b]) swap(a, b);
	ret += seg.query(S[a], S[b]);
	return ret;
}

void init() {
	fastio();
	cin >> N >> Q;
	int u, v;
	for (int i = 1; i < N; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1(1, 0);
	dfs2(1, 0);
}

int main() {
	init();
	while (Q--) {

	}

	return 0;
}
