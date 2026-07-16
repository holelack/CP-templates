#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
const int MAXN = 1e5 + 1;

struct Line {
	ll a, b;
	Line() {}
	Line(ll a, ll b) : a(a), b(b) {}
	ll eval(ll x) { return a * x + b; }
};
vector<Line> hull;

struct CHT {
	vector<Line> hull;
	int ptr = 0;
	void build() {
		hull.clear();
		ptr = 0;
	}

	bool bad(const Line& l1, const Line& l2, const Line& l3) const {
		// min: <=
		// max: >=
		return (__int128)(l1.a - l2.a) * (l2.b - l3.b) <= (__int128)(l1.b - l2.b) * (l2.a - l3.a);
	}

	void update(const Line& L) {
		while (hull.size() >= 2 && bad(hull.end()[-2], hull.back(), L)) {
			hull.pop_back();
		}
		hull.emplace_back(L);
		if (ptr >= hull.size()) ptr = hull.size() - 1;
	}

	ll query(ll x) {
		// min: >=
		// max: <=
		while (ptr < hull.size() - 1 && hull[ptr].eval(x) >= hull[ptr + 1].eval(x)) ptr++;
		return hull[ptr].eval(x);
	}
};
