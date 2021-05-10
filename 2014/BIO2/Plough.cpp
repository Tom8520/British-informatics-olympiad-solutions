#include <bits/stdc++.h>

using namespace std;
#define ll long long

int m[4][4] = {{3, 0, 0, 1}, {2, 1, 1, 0}, {1, 2, 2, 3}, {0, 3, 3, 2}};
float cxt[4][4] = {{0, 0, 0.5, 0.5}, {0.5, 0 ,0, 0.5}, {0.5, 0.5, 0, 0}, {0, 0.5, 0.5, 0}};
float cyt[4][4] = {{0, 0.5, 0.5, 0}, {0.5, 0.5, 0, 0}, {0.5, 0, 0, 0.5}, {0, 0, 0.5, 0.5}};

ll x = 0;
ll y = 0;

void nxt(ll n, int dir, int g){
    ll q1 = pow(2, 2*g-2);
    ll q2 = q1*2;
    ll q3 = q1*3;

    ll q;
    if ( n <= q1 )q = 0;
    else if ( n <= q2 )q = 1;
    else if ( n <= q3 ) q = 2;
    else q = 3;

    int ndir = m [dir][q];
    ll dx = (ll)pow(2, g)*cxt [dir][q];
    ll dy = (ll)pow(2, g)*cyt [dir][q];
    x += dx;
    y += dy;

    ll nn = n%q1;
    if ( nn == 0 )nn = q1;

    if ( g != 1 )nxt(nn, ndir, g-1);
}

int main(){
    int g;
    ll n;
    cin >> g >> n;

    nxt(n, 0, g);

    cout << x << " " << y << '\n';
}