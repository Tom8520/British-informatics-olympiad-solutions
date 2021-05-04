#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> m;
vector<int> visited;

char getRoom(int p, int n){
    visited.assign(n+2, 0);
    int room = 0;
    int moves = 0;

    while ( moves < p ){
        visited [room]++;

        if ( visited [room] % 2 == 1 ){
            m [room][0].second++;
            room = m [room][0].first;
        } else{
            for ( int i = 0; i < m [room].size(); i++){
                if ( m [room][i].second % 2 == 1 ){
                    if ( i == m [room].size()-1 ){
                        m [room][i].second++;
                        room = m [room][i].first;
                    } else{
                        m [room][i+1].second++;
                        room = m [room][i+1].first;
                    }
                    break;
                }
            }
        }
        moves++;
    }
    for ( int i = 0; i < n+2; i++ ){
        for ( int j = 0; j < m [i].size(); j++ ){
            m [i][j].second = 0;
        }
    }

    return (char)'A'+room;
}

int main(){
    string s;
    cin >> s;

    int p, q;
    cin >> p >> q;

    int n = s.size();

    m.assign(n+2, {});
    vector<bool> chosen(n+2, false);

    for ( int i = 0; i < n; i++ ){
        int c = s [i]-'A';
        int r = -1;
        for ( int j = 0; j < n+2; j++ ) {
            if (chosen[j])continue;
            bool ok = true;
            for (int k = i; k < n; k++) {
                if (s[k] - 'A' == j) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                r = j;
                break;
            }
        }
        chosen [r] = true;
        m [s [i]-'A'].push_back({r, 0});
        m [r].push_back({s [i]-'A', 0});
    }

    int a = -1, b = -1;
    for ( int i = 0; i < n+2; i++ ){
        if ( !chosen [i] ){
            if ( a == -1 )a = i;
            else b = i;
        }
    }

    m [a].push_back({b, 0});
    m [b].push_back({a, 0});

    for ( int i = 0; i < n+2; i++ ){
        sort(m [i].begin(), m [i].end());
        for ( auto j : m [i] ){
            cout << (char)('A'+j.first);
        }
        cout << '\n';
    }

    cout << getRoom(p, n) << getRoom(q, n) << '\n';
}
