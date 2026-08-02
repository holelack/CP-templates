#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
const int MAXN = 1e9;
int N;

struct Node {
	int l = 0, r = 0, val = 0;
	Node() {}
};

vector<Node> tree = { Node() };
struct DST {
  int root = 0;
	int alloc() {
		tree.push_back(Node());
		return tree.size() - 1;
	}

	int update(int node, int i, int v, int s = 1, int e = N) {
		if (node == 0) node = alloc();
		tree[node].val += v;
		if (s == e) return node;
		int mid = s + e >> 1;
		if (i <= mid) tree[node].l = update(tree[node].l, i, v, s, mid);
		else tree[node].r = update(tree[node].r, i, v, mid + 1, e);
		return node;
	}

	int query(int node, int l, int r, int s = 1, int e = N) {
		if (node == 0 || r < s || e < l) return 0;
		if (l <= s && e <= r) return tree[node].val;
		int mid = s + e >> 1;
		return query(tree[node].l, l, r, s, mid) + query(tree[node].r, l, r, mid + 1, e);
	}
};
DST dst;

void init() {
  root = update(0,1,1);
}

int main() {
  init();
  return 0;
}
