#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const ll MAX = LONG_LONG_MAX;

struct segmentTree{
    vector<ll> tree;
    set<pair<ll, int>> bs;
    int k;

    void init(int n){
        n = pow(2, ceil((float)log2(n))+1);
        k = n/2;
        tree.assign(n, MAX);
    }

    void insert(ll x, ll y, int p){
        bs.insert({y, p});
        tree [k + p] = x+y;
        update((k + p)/2);
    }

    void update(int s){
        tree [s] = min(tree [2*s], tree [2*s+1]);
        if ( s != 0 )update(s/2);
    }

    ll MIN(ll y){
        auto pos = bs.upper_bound({y, 0});
        if ( pos == bs.end() )return -1;
        int p = (*pos).second;
        return rangemin(p, k);
    }

    ll rangemin(int l, int r){
        ll res = MAX;

        for ( l+=k, r+=k; l<r ; l >>= 1, r >>= 1){
            if ( l&1 )res = min(res, tree [l++]);
            if ( r&1 )res = min(res, tree [--r]);
        }

        return res==MAX?-1:res;
    }
};

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    in >> n;

    vector<pair<ll, ll>> points;
    vector<pair<ll, ll>> pointsY;

    for ( int i = 0; i < n; i++ ){
        ll x, y;
        in >> x >> y;

        points.push_back({x, y});
        pointsY.push_back({y, x});
    }

    sort(pointsY.begin(), pointsY.end());
    sort(points.begin(), points.end());
    reverse(points.begin(), points.end());

    map<pair<ll, ll>, int> m;

    for ( int i = 0; i < n; i++ ){
        m [pointsY [i]] = i;
    }

    segmentTree tree;
    tree.init(n);

    ll total = 0;

    for ( int i = 0; i < n; i++ ){
        ll d = points [i].first + points [i].second;
        ll dist = tree.MIN(points [i].second);
        if ( dist != -1 )total += dist-d;

        tree.insert(points [i].first, points [i].second, m [{points [i].second, points [i].first}]);
        //cout << total << '\n';
    }

    out << total << '\n';
}

