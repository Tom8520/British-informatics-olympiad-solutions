#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll INF = LONG_LONG_MAX;

int ub = 4096;

int n;
vector<pair<int, ll>> g[4096];
vector<ll> sp;

void dijkstrasMod() {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> next;
    vector<bool> visited(n, false);
    vector<ll> d(n, INF);

    next.push({0, 0});
    d [0] = 0;

    while ( !next.empty() ){
        int v = next.top().second;
        next.pop();

        if ( !visited [v] ){
            visited [v] = true;
            for ( auto i : g [v] ){
                ll len = i.second;
                ll to = i.first;

                if ( !visited [to] && d [v] + len < d [to] ){
                    d [to] = d [v] + len;
                    next.push({d [to], to});
                }
            }
        }
    }
    sp = d;
}

ll dijkstras() {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> next;
    vector<bool> visited(n, false);
    vector<ll> d = sp;

    next.push({0, 0});
    d [0] = 0;

    while ( !next.empty() ){
        int v = next.top().second;
        next.pop();

        if ( !visited [v] ){
            visited [v] = true;
            for ( auto i : g [v] ){
                ll len = i.second;
                ll to = i.first;

                if ( !visited [to] && (d [v] + len < d [to] || sp [v] + (len/2) < d [to] )){
                    if ( sp [v] + (len/2) <= d [v] + len )d [to] = sp [v] + (len/2);
                    else d [to] = d [v] + len;
                    next.push({d [to], to});
                }
            }
        }
    }
    return d [n-1];
}

int main(){
    ifstream in = ifstream("input.txt");
    ofstream out = ofstream("output.txt");

    in >> n;

    int a, b;
    ll c;
    in >> a >> b >> c;

    while ( a > 0 ){
        g [a-1].push_back({b-1, c});
        g [b-1].push_back({a-1, c});
        in >> a >> b >> c;
    }

    dijkstrasMod();

    out << (ll) dijkstras() << '\n';
}