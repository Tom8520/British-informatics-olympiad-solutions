#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
int n, s = 1;

int maxBFS(bool p){
    queue<int> nxt;
    vector<bool> visited(n, false);
    vector<int> d(n, 1000000);

    nxt.push(s);
    d [s] = 0;

    while ( !nxt.empty() ){
        int v = nxt.front();
        for ( auto i : g [v] ){
            if ( !visited [i] ){
                d [i] = d [v] + 1;
                nxt.push(i);
            }
        }
        visited [v] = true;
        nxt.pop();
    }

    if ( p ) {
        int m = 0;
        for (int i = 0; i < n; i++) {
            m = max(m, d[i]);
        }
        return m;
    } else{
        int m = 0;
        int mi = -1;
        for ( int i = 0; i < n; i++ ){
            if ( d [i] > m ){
                mi = i;
                m = d [i];
            }
        }
        return mi;
    }
}

int main(){
    cin >> n;
    g.assign(n, {});
    s--;

    if ( n == 1 ){
        cout << 0 << '\n';
        return 0;
    }

    for ( int i = 0; i < n-1; i++ ){
        int x, y;
        cin >> x >> y;

        g [x-1].push_back(y-1);
        g [y-1].push_back(x-1);
    }

    s = maxBFS(false);

    int ans = 6*(n-1);
    ans -= 3*maxBFS(true);

    cout << ans << '\n';
}