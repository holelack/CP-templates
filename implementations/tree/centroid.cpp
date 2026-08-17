#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
const int MAXN = 1e5 + 1;
int N, M;
vector<int> G[MAXN];
int sz[MAXN], par[MAXN];
bool done[MAXN];
 
int getsz(int u, int p) {
	sz[u] = 1;
	for (int v : G[u]) {
		if (v == p || done[v]) continue;
		sz[u] += getsz(v,u);
	}
	return sz[u];
}
 
int cent(int u, int p, int n) {
	for (int v : G[u]) {
		if (v != p && !done[v] && sz[v] > n >> 1) return cent(v, u, n);
	}
	return u;
}
 
void decomp(int u, int p) {
	int c = cent(u, 0, getsz(u,0));
	par[c] = p;
	done[c] = true;
	for (int v : G[c]) {
		if (!done[v]) decomp(v, c);
	}
}
