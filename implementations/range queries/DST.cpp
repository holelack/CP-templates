#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
const int MAXN = 1e9;

struct Node {
	int l = 0, r = 0;
	ll v = 0;
	Node() = default;
	Node(ll v) : v(v) {}
	Node(int l, int r, ll v) : l(l), r(r), v(v) {}
	Node operator+(const Node& o) const {
		return Node(l, r, v + o.v);
	}
};

template <typename Node>
struct DST {
private:
	vector<Node> tree;
	int alloc() {
		tree.push_back(Node());
		return tree.size() - 1;
	}

	int update(int i, Node v, int s = 1, int e = MAXN, int node = 1) {
		if (node == 0) node = alloc();
		tree[node] = tree[node] + v;
		if (s == e) return node;
		int mid = s + e >> 1;
		if (i <= mid) tree[node].l = update(i, v, s, mid, tree[node].l);
		else tree[node].r = update(i, v, mid + 1, e, tree[node].r);
		return node;
	}

	Node query(int l, int r, int s = 1, int e = MAXN, int node = 1) {
		if (node == 0 || r < s || e < l) return Node();
		if (l <= s && e <= r) return tree[node];
		int mid = s + e >> 1;
		return query(l, r, s, mid, tree[node].l) + query(l, r, mid + 1, e, tree[node].r);
	}
public:
	DST() {
		tree.clear();
		tree.push_back(Node());
		tree.push_back(Node());
	}
	void upd(int i, Node v) { update(i, v); };
	Node qry(int l, int r) { return query(l, r); }
};

int main() {
	DST<Node> dst = DST<Node>();

	return 0;
}
