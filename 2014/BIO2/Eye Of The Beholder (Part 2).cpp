#include <bits/stdc++.h>

using namespace std;

vector<int> a;
int n;

int dp[1024][1024];

int nxt(int l, int r){
    if ( dp [l][r] != -1 )return dp [l][r];
    if ( l >= r ){
        dp [l][r] = 0;
        return 0;
    }

    if ( a [l] == a [r] ){
        dp [l][r] = nxt(l+1, r-1);
    } else {
        dp [l][r] = 1+min(nxt(l+1, r), nxt(l, r-1));
    }
    return dp [l][r];
}

int main(){
    string s;
    cin >> s;

    n = s.size();
    for ( int i = 0; i < n; i++ ){
        a.push_back(s [i]-'A');
    }

    memset(dp, -1, sizeof(dp));

    int res = nxt(0, n-1);

    cout << res << '\n';
}