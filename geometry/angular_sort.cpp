#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
#define cross(a,b) ((a).x*(b).y-(a).y*(b).x)
#define sgn(x) (((x)>0)-((x)<0))
#define ccw(a,b,c) sgn(cross((b)-(a), (c)-(a)))
#define norm2(a) ((a).x*(a).x+(a).y*(a).y)

struct P {
    ll x, y;
    P() x(0), y(0) {}
    P(ll x, ll y): x(x), y(y) {}
    auto operator<=>(const P&) const = default;
    P operator-(const P& o) const {
        return P(x-o.x,y-o.y);
    }
};

P O = P(0,0);

bool cmp(const P& A, const P& B) {
    if ((A < O) ^ (B < O)) return A > B;
    if (ccw(O,A,B)) return ccw(O,A,B) > 0;
    return norm2(A-O) < norm2(B-O);
}
