#include <bits/stdc++.h>
using namespace std;
#define fastio() {ios::sync_with_stdio(0); cin.tie(0);}
using ll = long long;

const double EPS = 1e-9;

struct dP;

struct P {
    ll x, y;
    P(ll x=0, ll y=0): x(x), y(y) {}

    bool operator==(const P& o) const { return x==o.x && y==o.y; }
    bool operator<(const P& o) const { return x!=o.x ? x<o.x : y<o.y; }
    bool operator>(const P& o) const { return x!=o.x ? x>o.x : y>o.y; }
    P operator+(const P& o) const { return {x+o.x, y+o.y}; }
    P operator-(const P& o) const { return {x-o.x, y-o.y}; }
    P operator*(ll s) const { return {x*s, y*s}; }
    P sym(const P& a) const { return (*this)*2 - a; }
};
const P O = P(0,0);

struct dP {
    double x,y;
    dP(double x=0,double y=0):x(x),y(y){}
    dP(const P& p):x((double)p.x),y((double)p.y){} 
    operator P() const { return P((ll)round(x),(ll)round(y)); }

    bool operator==(const dP& o) const { return abs(x-o.x)<EPS && abs(y-o.y)<EPS; }
    bool operator<(const dP& o) const { return x!=o.x ? x<o.x : y<o.y; }
    bool operator>(const dP& o) const { return x!=o.x ? x>o.x : y>o.y; }
    dP operator+(const dP& o) const { return {x+o.x,y+o.y}; }
    dP operator-(const dP& o) const { return {x-o.x,y-o.y}; }
    dP operator*(double s) const { return {x*s,y*s}; }
    dP operator/(double s) const { return {x/s,y/s}; }
};

inline ll dot(P a, P b){ return a.x*b.x + a.y*b.y; }
inline double dot(dP a, dP b){ return a.x*b.x + a.y*b.y; }

inline ll cross(P a, P b){ return a.x*b.y - a.y*b.x; }
inline double cross(dP a, dP b){ return a.x*b.y - a.y*b.x; }

inline ll dist2(P a, P b){
    ll dx=a.x-b.x, dy=a.y-b.y;
    return dx*dx + dy*dy;
}
inline double dist2(dP a, dP b){
    double dx=a.x-b.x, dy=a.y-b.y;
    return dx*dx + dy*dy;
}

inline double dist(P a, P b){ return sqrt((double)dist2(a,b)); }
inline double dist(dP a, dP b){ return sqrt(dist2(a,b)); }

inline ll ccw(P a, P b, P c){
    return cross(b-a, c-a);
}
inline double ccw(dP a, dP b, dP c){
    return cross(b-a, c-a);
}

inline dP perp(dP a){
    return dP(-a.y, a.x);
}

inline P perp(P a){
    return P(-a.y, a.x);
}

inline int sgn(ll x) { return (x > 0) - (x < 0); }

struct Line {
    P a,b;
    Line(P a,P b):a(a),b(b){}

    double len() const { return dist(a,b); }
    ll len2() const { return dist2(a,b); }

    bool onSeg(P p) const {
        return ccw(a,b,p)==0 && dot(p-a,p-b)<=0;
    }

    bool intersect(const Line& l) const {
        P c=l.a, d=l.b;
        int ab_c = sgn(ccw(a,b,c)), ab_d = sgn(ccw(a,b,d));
        int cd_a = sgn(ccw(c,d,a)), cd_b = sgn(ccw(c,d,b));

        if(ab_c*ab_d < 0 && cd_a*cd_b < 0) return true;
        return onSeg(c)||onSeg(d)||l.onSeg(a)||l.onSeg(b);
    }

    dP proj(dP p) const {
        dP A=(dP)a, B=(dP)b;
        double d2 = dist2(A,B);
        if(d2 < EPS) return A;
        double t = dot(p-A,B-A)/d2;
        return A + (B-A)*t;
    }

    dP intersection(const Line& l) const {
        dP A=(dP)a, B=(dP)b;
        dP C=(dP)l.a, D=(dP)l.b;
        double det = cross(B-A,D-C);
        if(abs(det) < EPS) return dP(1e18, 1e18);
        double t = cross(C-A,D-C)/det;
        return A + (B-A)*t;
    }
};

struct Poly {
    vector<P> vertex;
    Poly(const vector<P>& v): vertex(v) {}
};
