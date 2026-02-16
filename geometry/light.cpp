#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct P {
    ll x, y;
    P operator-(const P& o) const { return {x - o.x, y - o.y}; }
    bool operator<=(const P& o) const { return x != o.x ? x < o.x : y <= o.y; }
};

// 1: 반시계, 0: 일직선, -1: 시계
int ccw(P a, P b, P c) {
    ll res = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    return (res > 0) - (res < 0);
}

// 두 점 a, b를 잇는 선분 위에 점 p가 있는지 확인
bool onSeg(P a, P b, P p) {
    return ccw(a, b, p) == 0 && 
           min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}

// 선분 ab와 선분 cd의 교차 여부
bool intersect(P a, P b, P c, P d) {
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);
    if (ab == 0 && cd == 0) { // 네 점이 일직선상에 있는 경우
        if (b <= a) swap(a, b);
        if (d <= c) swap(c, d);
        return !(b < c || d < a);
    }
    return ab <= 0 && cd <= 0;
}

ll dist2(P a, P b) {
    ll dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    return 0;
}
