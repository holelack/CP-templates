#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
const int MAXN = 1e6 + 1;
int N;

ll A[MAXN];
ll tree[MAXN << 2], lazy[MAXN << 2];

void prop(int s, int e, int node) {
	if (!lazy[node]) return;

	tree[node] += lazy[node] * (e - s + 1);
	if (s != e) {
		lazy[node << 1] += lazy[node];
		lazy[node<<1|1] += lazy[node];
	}
	lazy[node] = 0;
}

void update(int l, int r, int val, int s = 1, int e = N, int node = 1) {
	prop(s, e, node);
	if (e < l || r < s) {
		lazy[node] += val;
		prop(s, e, node);
		return;
	}
	int mid = (s + e) >> 1;
	update(l,r,val,s,mid,node<<1);
	update(l,r,val,mid+1,e,node<<1|1);

	tree[node] = tree[node<<1] + tree[node<<1|1];
}

ll query(int l, int r, int s = 1, int e = N, int node = 1) {
	prop(s, e, node);
	if (e < l || r < s) return 0;
	if (l <= s && e <= r) return tree[node];
	int mid = (s + e) >> 1;
	return query(l,r,s,mid,node<<1) + query(l,r,mid+1,e,node<<1|1);
}

void init() {
	fastio();
	cin >> N;

	memset(tree, 0, sizeof(tree));
	memset(lazy, 0, sizeof(lazy));
}

int main() {
	init();

	return 0;
}
