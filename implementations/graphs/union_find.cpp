#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
const int MAXN = 1e6 + 1;
int N;

int parent[MAXN], sz[MAXN];

void build() {
	iota(parent, parent + N + 1, 0);
	memset(sz, 0, sizeof(sz));
}

void init() {
	fastio();
	cin >> N;
}

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
	int ra = find(a), rb = find(b);
	if (ra == rb) return;
	if (ra > rb) swap(ra, rb);
	sz[ra] += sz[rb];
	parent[rb] = ra;
}

int main() {
	init();
	build();

	return 0;
}
