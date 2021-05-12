#include <bits/stdc++.h>

using namespace std;

int main(){
    int v, s;
    cin >> v >> s;
    s--;
    vector<vector<int>> g(v);
    int cons[v];
    memset(cons, 0, sizeof(cons));

    for ( int i = 0; i < v-1; i++ ){
        int x, y;
        cin >> x >> y;

        g [x-1].push_back(y-1);
        g [y-1].push_back(x-1);
        cons [x-1]++;
        cons [y-1]++;
    }

    int t = 0;
    vector<int> toRemove;
    int removed = 0;
    for ( int i = 0; i < v; i++ ){
        if ( i != s && g [i].size() == 1 )toRemove.push_back(i);
    }
    while ( removed != v-1 ){
        vector<int> nxt;
        for ( auto i : toRemove ){
            if ( g [i].size() > 0 ) {
                int o = g[i][0];
                for (int j = 0; j < g[o].size(); j++) {
                    if (g[o][j] == i) {
                        g[o].erase(g[o].begin() + j);
                        break;
                    }
                }
                if (g[o].size() == 1 && o != s)nxt.push_back(o);
            }
            t += 6;
            removed++;
        }
        toRemove = nxt;
        t-=3;
    }

    cout << t << '\n';
}