#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
#define cross(a, b) ((a).x * (b).y - (a).y * (b).x)
#define ccw(a,b) cross(b-a, c-a)
const int MAXN = 1e6 + 1;
int N;

struct P {
	ll x, y;
	P() {}
	P(int x, int y) : x(x), y(y) {}
	P operator-(const P& o) const {
		return P(x - o.x, y - o.y);
	}
	bool operator<=(const P & o) const {
		return x != o.x ? x < o.x : y <= o.y;
	}
};

int getccw(P a, P b, P c) {
	if (ccw(a, b, c) < 0) return -1;
	if (ccw(a, b, c) > 0) return 1;
	return 0;
}

bool intersect(P a, P b, P c, P d) {
	int ab = getccw(a, b, c) * getccw(a, b, d);
	int cd = getccw(c, d, a) * getccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (b <= a) swap(a, b);
		if (d <= c) swap(c, d);
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}

P points[MAXN];

void init() {
	fastio();
	cin >> N;
	ll x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		points[i] = P(x, y);
	}
}

int main() {
	init();

	return 0;
}
