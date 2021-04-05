#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

vector<vector<int>> g;
vector<int> ans;
vector<bool> visited;

void BFS(int s){
    queue<pair<int, bool>> nxt;
    nxt.push({s, true});
    visited [s] = true;

    while ( !nxt.empty() ){
        int c = nxt.front().first;
        bool p = nxt.front().second;
        ans [c] = p;
        nxt.pop();
        for ( auto i : g [c] ){
            if ( !visited [i] ){
                visited [i] = true;
                nxt.push({i, !p});
            }
        }
    }
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    in >> n;

    g.assign(n, {});
    ans.assign(n, 0);
    visited.assign(n, false);

    for ( int i = 0; i < n/2; i++ ){
        int a, b;
        in >> a >> b;

        g [a].push_back(b);
        g [b].push_back(a);
    }

    for ( int i = 1; i < n; i += 2 ){
        g [i].push_back((i+1)%n);
        g [(i+1)%n].push_back(i);
    }

    for ( int i = 0; i < n; i++ ){
        if ( !visited [i] )BFS(i);
    }

    for ( int i = 0; i < n; i++ ){
        out << (ans [i]==1?'A':'B');
    }out << '\n';
}

