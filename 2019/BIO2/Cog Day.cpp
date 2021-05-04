#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

struct pt{
    ll x, y;
};

int n, m;
vector<pt> p;
vector<pt> t;

ll doubleArea(pt a, pt b, pt c){
    return abs(a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}

bool valid(pt a, pt b, pt c){
    ll area = doubleArea(a, b, c);
    //if ( area == 0 )return true;

    for ( auto p : t ){
        ll a1 = doubleArea(p, b, c);
        ll a2 = doubleArea(a, p, c);
        ll a3 = doubleArea(a, b, p);

        if ( area == a1+a2+a3 )return false;
    }

    return true;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    in >> n >> m;

    for ( int i = 0; i < n; i++ ){
        ll x, y;
        in >> x >> y;

        p.push_back({x, y});
    }

    for ( int i = 0; i < m; i++ ){
        ll x, y;
        in >> x >> y;

        t.push_back({x, y});
    }

    int a = 1;
    int b = 0;
    int cnt = 1;
    ll currentArea = 0;
    ll maxArea = 0;

    while ( b < n && cnt < n){
        if ( valid(p [a], p [b], p [(a+1)%n]) ){
            currentArea += doubleArea(p [a], p [b], p [(a+1)%n]);
            a++;
            a %= n;
            //if ( currentArea > maxArea )cout << a << " " << b << '\n';
            maxArea = max(maxArea, currentArea);
            cnt++;
        } else{
            currentArea -= doubleArea(p [b], p [(b+1)%n], p [a]);
            b++;
            cnt--;
        }
    }

    out << (ll)floor((ld)maxArea/2) << '\n';
}