#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}

struct Line {
    ll a, b;
    Line() {}
    Line(ll a, ll b): a(a), b(b) {}
    ll eval(ll x) { return a*x+b; }
};

// O(NlogN)
struct CHT {
    vector<Line> hull;
    void build() {
        hull.clear();
    }

    bool bad(const Line& L1, const Line& L2, const Line& L3) { 
        // min : <=
        // max : >=
        return (__int128)(L1.a-L2.a)(L2.b-L3.b) <= (__int128)(L1.b-L2.b)*(L2.a-L3.a);
    }
    void insert(const Line& L) {
        while (hull.size()>=2 && bad(hull.end()[-2], hull.back(), L)) {
            hull.pop_back();
        }
        hull.emplace_back(L);
    }
    ll query(ll x) {
        int l = 0, r = hull.size()-1;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            // min : >=
            // max : <=
            if (hull[mid].eval(x) >= hull[mid+1].eval(x)) l = mid;
            else r = mid;
        }
        return min(hull[l].eval(x), hull[r].eval(x));
    }
};
