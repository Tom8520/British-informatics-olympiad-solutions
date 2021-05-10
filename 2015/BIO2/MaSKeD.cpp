#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    getline(cin, s);

    int n = s.size();

    string res = "";

    int i = 0;
    while ( i < n ){
        char j = s [i];
        if ( j == 'm' || j == 'M' ){
            int p = 1;
            int sum = -1;
            for ( int k = i+5; k > i; k-- ){
                if ( 'A' <= s [k] && s [k] <= 'Z' )sum += p;
                p *= 2;
            }
            if ( j == 'm' )res.push_back('a'+sum);
            else res.push_back('A'+sum);
            i += 6;
        } else{
            res.push_back(j);
            i++;
        }
    }

    cout << res << '\n';
}