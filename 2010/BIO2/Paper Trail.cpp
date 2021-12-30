#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll h, s;
ll t = 0;
vector<vector<ll>> a;

vector<vector<vector<pair<ll, ll>>>> dp;

void nxt(ll l, ll r, ll d){
    if ( d ){
        if ( dp [l][r-1][0].first == 1e9 )nxt(l, r-1, 0);
        if ( dp [l][r-1][1].first == 1e9 )nxt(l, r-1, 1);

        ll m = min(dp [l][r-1][0].first + dp [l][r-1][0].second * (a [r][0]-a [l][0]), dp [l][r-1][1].first+ dp [l][r-1][0].second * (a [r][0]-a [r-1][0]));
        ll k = dp [l][r-1][0].second - a [r][1];

        dp [l][r][d] = {m, k};
    } else{
        if ( dp [l+1][r][0].first == 1e9)nxt(l+1, r, 0);
        if ( dp [l+1][r][1].first == 1e9)nxt(l+1, r, 1);

        ll m = min(dp [l+1][r][0].first + dp [l+1][r][0].second * (a [l+1][0]-a [l][0]), dp [l+1][r][1].first+ dp [l+1][r][0].second * (a [r][0]-a [l][0]));
        ll k = dp [l+1][r][0].second - a [l][1];

        dp [l][r][d] = {m, k};
    }
}

int main(){
    cin >> h >> s;

    a.assign(h+1, {});

    for ( int i = 0; i < h; i++ ){
        ll p, n;
        cin >> p >> n;
        a [i] = {p, n};
        t += n;
    }

    a [h] = {s, 0};

    sort(a.begin(), a.end());

    dp.assign(h+1, {});
    for ( int i = 0; i < h+1; i++ )
        dp [i].assign(h+1, {});
    for ( int i = 0; i < h+1; i++ )
        for ( int j = 0; j < h+1; j++ )
            dp [i][j].assign(2, {1e9, t});

    for ( int i = 1; i < h+1; i++ ){
        if ( a [i][0] == s ){
            dp [i-1][i][0] = {(s - a [i-1][0]) * t, t - a [i-1][1]};
            dp [i-1][i][1] = {1e9-1, 1e9-1};
        } else if ( a [i-1][0] == s ){
            dp [i-1][i][0] = {1e9-1, 1e9-1};
            dp [i-1][i][1] = {(a [i][0] - s) * t, t - a [i][1]};
        } else{
            dp [i-1][i][0] = {1e9-1, 1e9-1};
            dp [i-1][i][1] = {1e9-1, 1e9-1};
        }
    }

    nxt(0, h, 0);
    nxt(0, h, 1);

    /*for ( int k = 0; k < 2; k++ ) {
        for (int i = 0; i < h + 1; i++) {
            for (int j = 0; j < h + 1; j++) {
                cout << dp[i][j][k].first << " ";
            }
            cout << '\n';
        }
        cout << '\n' << '\n';
    }*/

    cout << min(dp [0][h][0].first, dp [0][h][1].first) << '\n';
}
