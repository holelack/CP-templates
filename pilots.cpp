#include <bits/stdc++.h>
using namespace std;
#define fastio() {ios_base::sync_with_stdio(0); cin.tie(0);}
int t, n;
vector<int> seq;
deque<int> mindq, maxdq;

void input() {
    fastio();
    cin >> t >> n;
    seq.assign(n, 0);
    for (int& i: seq) cin >> i;
}

void solve() {
    input();
    int ans = 0;
    int l = 0, r = 0;
    mindq.push_back(seq[0]);
    maxdq.push_back(seq[0]);
    while (l < n || r < n) {
        if (maxdq.back() - mindq.back() <= t) {
            ans = max(ans, r - l + 1);
            l++; r++;
            if (maxdq.back() < )
        }
    }
}

