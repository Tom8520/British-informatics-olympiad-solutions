#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll NINF = LONG_LONG_MIN;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    int t, w;
    in >> t >> w;

    vector<ll> s(t);
    vector<ll> sum(t+1);
    sum [0] = 0;
    for ( int i = 0; i < t; i++ ){
        in >> s [i];
        sum [i+1] = sum [i] + s [i];
    }

    ll m = NINF;
    vector<ll> u(w);
    for ( int i = 0; i < w; i++ ){
        in >> u [i];
        m = max(m, u [i]);
    }

    ll dp[m+1];
    dp [0] = 0;
    dp [1] = s [0];

    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> nxt;

    for ( int i = 2; i <= m; i++ ){
        vector<ll> c = {-1, -1};
        if ( i <= t )c = {0, sum [i], s [i-2], s [i-1], i};
        while ( !nxt.empty() && nxt.top() [0] <= i ){
            vector<ll> a = nxt.top();
            nxt.pop();
            a [1] += (i-a [4]-(i-a [4])%2)/2*(a [2]+a [3]);
            if ( (i-a [4])%2 == 1 ){
                a [1] += a [2];
                swap(a [2], a [3]);
            }
            a [4] = i;

            if ( c [0] == -1 ){
                c = a;
                continue;
            }

            if ( a [1] > c [1] ){
                swap(a, c);
            }
            if ( a [2]+a [3]-c [2]-c [3] <= 0 )continue;
            int n = ceil((long double)(c [1]-a [1])/(a [2]+a [3]-c [2]-c [3]));
            a [0] = max(i+1, i+(2*n));
            if ( a [1] + n*(a [2]+a [3])-a [3] >= c [1] + n*(c [2]+c [3])-c [3] ) {
                a[0] = max(i + 1, (int) a[0] - 1);
            }
            nxt.push(a);
        }
        dp [i] = c [1];
        c [0] = i+1;
        nxt.push(c);
    }

    //for ( int i = 0; i <= m; i++ ){
        //cout << dp [i] << " ";
    //}cout << '\n';

    ll ans = 0;
    for ( auto i : u ){
        ans += dp [i];
    }

    out << ans << '\n';
}