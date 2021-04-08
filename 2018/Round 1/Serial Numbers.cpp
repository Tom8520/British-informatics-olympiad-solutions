#include <bits/stdc++.h>

using namespace std;
#define ll long long

map<string, vector<string>> g;

void nxt(string c){
    g [c] = {};
    vector<string> cons;

    for ( int i = 1; i < c.size(); i++ ){
        int x = c [i]-'0', y = c [i-1]-'0';
        int z = (i==1?-1:c [i-2]-'0'), w = (i==c.size()-1?-1:c [i+1]-'0');

        //cout << x << " " << y << " " << z << " " << w << '\n';

        if ( x > y )swap(x, y);

        bool ok = false;
        if ( z > x && z < y)ok = true;
        if ( w > x && w < y)ok = true;

        if ( ok ){
            string s = c;
            swap(s [i], s [i-1]);

            cons.push_back(s);
            if ( g.find(s) == g.end() )nxt(s);
        }
    }

    g [c] = cons;
}

int BFSmax(string s){
    map<string, bool> visited;
    map<string, int> dist;
    queue<string> nxt;
    int m = 0;

    dist [s] = 0;
    nxt.push(s);

    while ( !nxt.empty() ){
        if ( visited.find(nxt.front()) == visited.end() ) {
            string n = nxt.front();

            visited[n] = true;

            for (auto i : g[n]) {
                if (visited.find(i) == visited.end()) {
                    dist[i] = dist[n] + 1;
                    m = max(m, dist[i]);
                    nxt.push(i);
                }
            }
        }
        nxt.pop();
    }

    return m;
}

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    nxt(s);

    cout << BFSmax(s) << '\n';
}
