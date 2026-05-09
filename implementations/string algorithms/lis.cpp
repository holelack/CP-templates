#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
const int MAXN = 1e6 + 1;
int N, M;
int A[MAXN], pos[MAXN];
vector<int> L, LIS;

void getLIS() {
	for (int i = 0; i < N; i++) {
		if (L.empty() || A[i] > L.back()) {
			pos[i] = L.size();
			L.push_back(A[i]);
		}
		else {
			auto it = lower_bound(L.begin(), L.end(), A[i]);
			*it = A[i];
			pos[i] = it - L.begin();
		}
	}

	M = L.size();
	int p = M - 1;
	for (int i = N - 1; i >= 0; i--) {
		if (pos[i] == p) {
			LIS.push_back(A[i]);
			p--;
		}
	}
	reverse(LIS.begin(), LIS.end());
}

void init() {
	fastio();
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
}


int main() {
	init();
	getLIS();

	return 0;
}
