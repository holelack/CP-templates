#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
const ll MAXN = 2e5 + 1, LOG = 20;
int N;
struct Edge {
    ll v, w;
    Edge() {}
    Edge(ll v, ll w) : v(v), w(w) {}
};
vector<Edge> G[MAXN];

ll lev[MAXN];
ll P[MAXN][LOG], W[MAXN][LOG];

void dfs(int u, int p) {
    P[u][0] = p;
    for (auto [v, w] : G[u]) {
        if (v == p) continue;
        W[v][0] = w;
        lev[v] = lev[u] + 1;
        dfs(v, u);
    }
}

void build_lca() {
    memset(W[0], 0, sizeof(W[0]));
    memset(W[1], 0, sizeof(W[1]));
    memset(P[0], 0, sizeof(P[0]));
    memset(P[1], 0, sizeof(P[1]));
    lev[0] = 0; lev[1] = 1;
    dfs(1, 0);

    for (int dep = 1; dep < LOG; dep++) {
        for (int u = 1; u <= N; u++) {
            P[u][dep] = P[P[u][dep - 1]][dep - 1];
            W[u][dep] = W[u][dep - 1] + W[P[u][dep - 1]][dep - 1];
        }
    }
}

pll dist(int a, int b) { // return pll(dist, LCA);
    if (lev[a] > lev[b]) swap(a, b);

    ll D = 0;
    for (int dep = LOG - 1; dep >= 0; dep--) {
        if (lev[b] - lev[a] >= (1 << dep)) {
            D += W[b][dep];
            b = P[b][dep];
        }
    }

    if (a == b) {
        return pll(D, a);
    }

    for (int dep = LOG - 1; dep >= 0; dep--) {
        if (P[a][dep] != P[b][dep]) {
            D += W[a][dep] + W[b][dep];
            a = P[a][dep];
            b = P[b][dep];
        }
    }

    D += W[a][0] + W[b][0];
    a = P[a][0];
    return pll(D, a);
}
