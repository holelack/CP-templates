#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
struct Node {
	int l = 0, r = 0, val = 0;
	Node() {}
};

vector<Node> tree = { Node() };
class seg2D {
private:
	int root[MAXN];
	struct DST {
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

	void update(int x, int y, int v) {
		for (int i = x; i <= N; i += i & -i) {
			root[i] = dst.update(root[i], y, v);
		}
	}

	int query(int x, int y1, int y2) {
		int res = 0;
		for (int i = x; i > 0; i -= i & -i) {
			res += dst.query(root[i], y1, y2);
		}
		return res;
	}

public:
	void build() {
		tree.clear();
		tree.push_back(Node());
		memset(root, 0, sizeof(root));
	}
	void PsumU(int x, int y, int v) { update(x, y, v); }
	int RsumQ(int x1, int x2, int y1, int y2) { return query(x2, y1, y2) - query(x1-1, y1, y2); }
};

void init() {
  seg2D.build();
}

int main() {
  init();

  return 0;
}
