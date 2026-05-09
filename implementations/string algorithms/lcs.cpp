#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
const int MAXN = 5e3 + 1;
int dp[MAXN][MAXN];
string S1, S2, LCS = "";
int L;

void init() {
	fastio();
	cin >> S1;
	cin >> S2;
}

void getLCS() {
	int N = S1.size(), M = S2.size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (S1[i] == S2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	L = dp[N - 1][M - 1];
	int i = N - 1, j = M - 1;
	while (i >= 0 && j >= 0) {
		if (S1[i] == S2[j]) {
			LCS += S1[i];
			i--;
			j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1]) i--;
		else j--;
	}
	reverse(LCS.begin(), LCS.end());
}


int main() {
	init();
	getLCS();

	return 0;
}
