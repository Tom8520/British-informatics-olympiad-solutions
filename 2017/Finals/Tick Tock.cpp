#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    in >> n;

    vector<pair<ll, int>> a;
    vector<pair<ll, ll>> ranges;

    ll start = -1;
    int open = 0;

    for ( int i = 0; i < n; i++ ){
        ll s, e;
        in >> s >> e;
        a.push_back({s, -1});
        a.push_back({e, 1});
    }

    ll t = 0;

    sort(a.begin(), a.end());

    for ( int i = 0; i < 2*n; i++ ){
        open -= a [i].second;
        if ( open == 1 && a [i].second == -1)start = a [i].first;
        else if ( open == 0 ){
            t += a [i].first - start + 1;
            ranges.push_back({start, a [i].first});
        }
    }

    ll tick = 0;

    for ( auto i : ranges ){
        ll start = i.first;
        ll end = i.second;

        while ( start% 10 != 0 ){
            int sum = 0;
            for ( auto k : to_string(start) ){
                sum += k-'0';
            }
            //cout << start << " " << sum << '\n';
            if ( sum % 2 == 0 )tick++;
            start++;
            if ( start > end )break;
        }
        if ( start > end )continue;

        ll diff = end-start+1;
        tick += 5*(diff/10);
        start += 10*(ll)(diff/10);
        //cout << start << '\n';

        for ( ll j = start; j <= end; j++ ){
            int sum = 0;
            for ( auto k : to_string(j) ){
                sum += k-'0';
            }
            //cout << j << " " << sum << '\n';
            if ( sum % 2 == 0 )tick++;
        }
    }
    out << t << " " << tick << '\n';
}