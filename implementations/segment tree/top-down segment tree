#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
const int MAXN = 1e6 + 1;
int N;

ll A[MAXN];
ll tree[MAXN << 2];

void build(int s = 1, int e = N, int node = 1) {
	if (s == e) {
		tree[node] = A[MAXN];
		return;
	}
	int mid = (s + e) >> 1;
	build(s, mid, node << 1);
	build(mid+1,e,node<<1|1);
	tree[node] = tree[node << 1] + tree[node << 1 | 1];
}

void update(int idx, int val, int s = 1, int e = N, int node = 1) {
	if (idx < s || e < idx) return;
	if (s == e) {
		tree[node] += val;
		return;
	}
	int mid = (s + e) >> 1;
	update(idx, val, s, mid, node << 1);
	update(idx, val, mid + 1, e, node << 1 | 1);
	tree[node] = tree[node << 1] + tree[node << 1 | 1];
}

ll query(int l, int r, int s = 1, int e = N, int node = 1) {
	if (e < l || r < s) return 0;
	if (l <= s && e <= r) return tree[node];
	int mid = (s + e) >> 1;
	return query(l, r, s, mid, node << 1) + query(l, r, mid + 1, e, node << 1 | 1);
}

void init() {
	fastio();
	cin >> N;

	memset(tree, 0, sizeof(tree));
}

int main() {
	init();

	return 0;
}
