#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
const int MAXN = 1e6 + 1;
int N;

int parent[MAXN], sz[MAXN];

void build() {
	iota(parent, parent + N + 1, 0);
	fill(sz, sz + N + 1, 1);
}

void init() {
	fastio();
	cin >> N;
}

int find(int x) {
	while (x != parent[x]) x = parent[x];
	return x;
}

void unite(int a, int b) {
	int ra = find(a), rb = find(b);
	if (ra == rb) return;
	if (sz[ra] < sz[rb]) swap(ra, rb);
	parent[rb] = ra;
	sz[ra] += sz[rb];
}

int main() {
	init();
	build();

	return 0;
}
