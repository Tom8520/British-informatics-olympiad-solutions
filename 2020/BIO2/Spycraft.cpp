#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll total = 0;

struct point{
    ll x, y;
    void init(ll a, ll b){
        x = a;
        y = b;
    }
};

point makePoint(ll x, ll y){
    point p;
    p.init(x, y);
    return p;
}

struct rect{
    point a, b, c, d;

    void init(ll x, ll y, ll z, ll w){
        //if ( x > 1000000 || y > 1000000 || z > 1000000 || w > 1000000 || x < -1000000 || y < -1000000 || z < -1000000 || w < -1000000 )cout << "X" << '\n';
        if ( x <= z && y >= w ){
            a = makePoint(x, y);
            b = makePoint(z, y);
            c = makePoint(x, w);
            d = makePoint(z, w);
        } else if ( z < x && w > y ){
            a = makePoint(z, w);
            b = makePoint(x, w);
            c = makePoint(z, y);
            d = makePoint(x, y);
        } else if ( x <= z ){
            a = makePoint(x, w);
            b = makePoint(z, w);
            c = makePoint(x, y);
            d = makePoint(z, y);
        } else{
            a = makePoint(z, y);
            b = makePoint(x, y);
            c = makePoint(z, w);
            d = makePoint(x, w);
        }
    }

    bool inside(point p){
        return p.x >= a.x && p.x <= b.x && p.y <= a.y && p.y >= c.y;
    }

    bool cross(rect r){
        if ( a.x > r.a.x && b.x < r.b.x && a.y > r.a.y && c.y < r.c.y )return true;
        if ( r.a.x > a.x && r.b.x < b.x && r.a.y > a.y && r.c.y < c.y )return true;
        return false;
    }

    rect dist(rect other){
        if ( inside(other.a) || inside (other.b) || inside(other.c) || inside(other.d) || other.inside(a) || other.inside(b) || other.inside(c) || other.inside(d) || cross(other)){
            rect n;
            n.init(max(a.x, other.a.x), min(a.y, other.a.y), min(b.x, other.b.x), max(c.y, other.c.y));
            return n;
        }

        if ( a.y <= other.a.y && a.y >= other.c.y && c.y <= other.a.y && c.y >= other.c.y){
            rect n;
            if ( a.x > other.d.x ){
                n.init(a.x, a.y, c.x, c.y);
                total += a.x-other.d.x;
            } else{
                n.init(b.x, b.y, d.x, d.y);
                total += other.a.x-d.x;
            }
            return n;
        }

        if ( a.x >= other.a.x && a.x <= other.b.x && b.x >= other.a.x && b.x <= other.b.x ){
            rect n;
            if ( c.y > other.a.y ){
                n.init(c.x, c.y, d.x, d.y);
                total += c.y-other.a.y;
            } else{
                n.init(a.x, a.y, b.x, b.y);
                total += other.c.y-a.y;
            }
            return n;
        }

        rect n;
        ll m = 1e18;

        if ( a.x >= other.b.x ){
            if ( a.x-other.b.x >= c.y-other.b.y && a.x-other.b.x >= other.d.y-a.y ){
                n.init(a.x, min(a.y, other.a.y+a.x-other.b.x), a.x, max(c.y, other.d.y-a.x+other.b.x));
                m = a.x-other.b.x;
            }
        }

        if ( b.x <= other.a.x ){
            if ( other.a.x-b.x >= c.y-other.b.y && other.a.x-b.x >= other.d.y-a.y ){
                if ( other.a.x-b.x < m ){
                    n.init(b.x, min(a.y, other.a.y+other.a.x-b.x), b.x, max(c.y, other.d.y-other.a.x+b.x));
                    m = other.a.x-b.x;
                }
            }
        }

        if ( c.y >= other.a.y ){
            if ( c.y-other.a.y >= other.a.x-d.x && c.y-other.a.y >= c.x-other.d.x ){
                if ( c.y - other.a.y < m ){
                    n.init(max(a.x, other.a.x -c.y+other.a.y), d.y, min(d.x, other.d.x+c.y-other.a.y), d.y);
                    m = c.y-other.a.y;
                }
            }
        }

        if ( a.y <= other.c.y ){
            if ( other.c.y-a.y >= a.x-other.d.x && other.c.y-a.y >= other.c.x-d.x ){
                if ( other.c.y - a.y < m ){
                    n.init(max(a.x, other.a.x -other.c.y+a.y), a.y, min(d.x, other.d.x+other.c.y-a.y), a.y);
                    m = other.c.y-a.y;
                }
            }
        }

        if ( m == 1e18 ){
            cout << "(" << a.x << ", " << a.y << ") ";
            cout << "(" << b.x << ", " << b.y << ") ";
            cout << "(" << c.x << ", " << c.y << ") ";
            cout << "(" << d.x << ", " << d.y << ") " << '\n';
            cout << "(" << other.a.x << ", " << other.a.y << ") ";
            cout << "(" << other.b.x << ", " << other.b.y << ") ";
            cout << "(" << other.c.x << ", " << other.c.y << ") ";
            cout << "(" << other.d.x << ", " << other.d.y << ") " << '\n';
        }

        total += m;
        return n;
    }
};

vector<rect> r;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    in >> n;

    for ( int i = 0; i < n; i++ ){
        ll x, y, z, w;
        in >> x >> y >> z >> w;

        rect t;
        t.init(x, y, z, w);

        r.push_back(t);
    }

    rect current = r [0];

    for ( int i = 1; i < n; i++ ){
        current = r [i].dist(current);
    }

    out << total << '\n';
}
