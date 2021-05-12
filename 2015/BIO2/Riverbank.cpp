#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll dp [1025][1025][4];

int main(){
    int n, c;
    cin >> n >> c;

    vector<pair<ll, ll>> a(n);

    for ( int i = 0; i < n; i++ ){
        ll x, y;
        cin >> x >> y;

        a [i] = {x, y};
    }

    for ( int i = 0; i <= n; i++ ){
        dp [i][0][0] = 0;
        dp [i][0][1] = 0;
        dp [i][0][2] = 0;
        dp [i][0][3] = 0;

        if ( i <= c ){
            dp [0][i][0] = 0;
            dp [0][i][1] = 0;
            dp [0][i][2] = 0;
            dp [0][i][3] = 0;
        }
    }

    for ( int j = 1; j <= c; j++ ){
        for ( int i = 1; i <= n; i++ ){
            //both sides free
            dp [i][j][0] = dp [i][j-1][0];
            dp [i][j][0] = max(dp [i][j][0], max(max(dp [i-1][j][0], dp [i-1][j][1]), max(dp [i-1][j][2], dp [i-1][j][3])));
            //both sides taken
            dp [i][j][1] = max(max(dp [i-1][j-1][0], dp [i-1][j-1][1]), max(dp [i-1][j-1][2], dp [i-1][j-1][3])) + a [i-1].first + a [i-1].second;
            if ( i != 1 && j != 1)dp [i][j][1] = max(dp [i][j][1], dp [i-1][j-2][0] + a [i-1].second + a [i-2].second + a [i-1].first + a [i-2].first);
            //only first taken
            dp [i][j][2] = 0;
            if ( i != 1 )dp [i][j][2] = max(dp [i-1][j-1][3], dp [i-1][j-1][0]) + a [i-1].first + a [i-2].first;
            //only second taken
            dp [i][j][3] = 0;
            if ( i != 1 )dp [i][j][3] = max(dp [i-1][j-1][2], dp [i-1][j-1][0]) + a [i-1].second + a [i-2].second;
        }
    }

    ll ans = max(max(dp [n][c][0], dp [n][c][1]), max(dp [n][c][2], dp [n][c][3]));

    cout << ans << '\n';
}