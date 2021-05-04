#include <bits/stdc++.h>

using namespace std;

vector<int> g[1024];
int n;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> n;

    int m = (pow(n-1, 2)+n-1)/2;

    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < n; j++ ){
            g [i].push_back(0);
        }
    }

    while ( m-- ){
        int a, b;
        in >> a >> b;
        g [b-1][a-1] = 1;
    }

    vector<int> order = {0};

    queue<int> nxt;

    for ( int i = 1; i < n; i++ ){
        nxt.push(i);
    }

    while ( !nxt.empty() ){
        int v = nxt.front();
        nxt.pop();
        if ( g [v][order [0]] )order.insert(order.begin(), v);
        else if ( g [order [order.size()-1]][v] )order.push_back(v);
        else{
            bool found = false;

            for ( int i = 0; i < order.size()-1; i++ ){
                if ( g [order [i]][v] && g [v][order [i+1]] ){
                    order.insert(order.begin()+i+1, v);
                    found = true;
                    break;
                }
            }

            if ( !found )nxt.push(v);
        }
    }

    for ( auto i : order ){
        out << i+1 << " ";
    }out << '\n';
}