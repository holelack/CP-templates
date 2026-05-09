#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
const int MAXN = 1e6 + 2;
int N;

ll BIT[MAXN];

void update(int i, ll v) {
	for (int bit = i; bit <= N; bit += bit & -bit) {
		BIT[bit] += v;
	}
}

ll query(int i) {
	ll res = 0;
	for (int bit = i; bit > 0; bit -= bit & -bit) {
		res += BIT[bit];
	}
	return res;
}

void init() {
	fastio();
	cin >> N;
}

int main() {
	init();

	return 0;
}
