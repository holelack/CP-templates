#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
const int MAXN = 1e6 + 1;
int N;
int A[MAXN], P[MAXN], L[MAXN], R[MAXN];

void build() {
	for (int i = 1; i <= N; i++) P[i] = L[i] = R[i] = 0;

	stack<int> stk;
	for (int i = 1; i <= N; i++) {
		int last = 0;
		while (!stk.empty() && A[stk.top()] < A[i]) {
			last = stk.top(); stk.pop();
		}
		if (!stk.empty()) {
			R[stk.top()] = i;
			P[i] = stk.top();
		}
		if (last) {
			L[i] = last;
			P[last] = i;
		}
		stk.push(i);
	}
}

void init() {
	fastio();
	cin >> N;

	for (int i = 1; i <= N; i++) cin >> A[i];
	build();
}

int main() {
	init();

	return 0;
}
