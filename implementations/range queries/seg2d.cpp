
struct Node {
	int l = 0, r = 0;
	int v = 0;
	Node() {}
	Node(int v) : v(v) {}
	Node(int l, int r, int v) : l(l), r(r), v(v) {}
	Node operator+(const Node& o) const {
		return Node(l, r, v + o.v);
	}
};

template <typename Node>
class DST {
private:
	vector<Node> tree;
	int alloc() {
		tree.push_back(Node());
		return tree.size() - 1;
	}
public:
	DST() {
		tree.clear();
		tree.push_back(Node());
		tree.push_back(Node());
	}
	int upd(int i, Node v, int s = 1, int e = MAXN, int node = 1) {
		if (node == 0) node = alloc();
		tree[node] = tree[node] + v;
		if (s == e) return node;
		int mid = s + e >> 1;
		if (i <= mid) tree[node].l = upd(i, v, s, mid, tree[node].l);
		else tree[node].r = upd(i, v, mid + 1, e, tree[node].r);
		return node;
	}

	Node qry(int l, int r, int s = 1, int e = MAXN, int node = 1) {
		if (node == 0 || r < s || e < l) return Node();
		if (l <= s && e <= r) return tree[node];
		int mid = s + e >> 1;
		return qry(l, r, s, mid, tree[node].l) + qry(l, r, mid + 1, e, tree[node].r);
	}
};

class seg2D {
private:
	DST<Node> BIT[MAXN];
public:
	void upd(int x, int y, int v) {
		for (int i = x; i < MAXN; i += i & -i) {
			BIT[i].upd(y, Node(v));
		}
	}

	int qry(int x1, int x2, int y1, int y2) {
		int res = 0;
		for (int i = x2; i > 0; i -= i & -i) {
			res = res + BIT[i].qry(y1, y2).v;
		}
		for (int i = x1-1; i > 0; i -= i & -i) {
			res = res - BIT[i].qry(y1, y2).v;
		}
		return res;
	}
};
