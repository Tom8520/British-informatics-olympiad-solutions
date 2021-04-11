#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int k;
int n, m;
int dp [2060][2060];
int csh [2060][2060];
int csv [2060][2060];

int calc(int y1, int y2, int x1, int x2){
    if ( x1 > x2 )return dp [y1][y2] = 0;
    if ( csh [x1][y2] - (y1==0?0:csh [x1][y1-1]) <= k )return dp [y1][y2] = calc(y1, y2, x1+1, x2);
    if ( csh [x2][y2] - (y1==0?0:csh [x2][y1-1]) <= k )return dp [y1][y2] = calc(y1, y2, x1, x2-1);

    dp [y1][y2] = INT_MAX/2;
    if ( csv [x2][y1] - (x1==0?0:csv [x1-1][y1]) <= k ){
        if ( dp [y1+1][y2] == -1 ) dp [y1][y2] = min(dp [y1][y2], 1+calc(y1+1, y2, x1, x2));
        else dp [y1][y2] = min(dp [y1][y2], 1+dp [y1+1][y2]);
    }
    if ( csv [x2][y2] - (x1==0?0:csv [x1-1][y2]) <= k ){
        if ( dp [y1][y2-1] == -1 )dp [y1][y2] = min(dp [y1][y2], 1+calc(y1, y2-1, x1, x2));
        else dp [y1][y2] = min(dp [y1][y2], 1+dp [y1][y2-1]);
    }
    return dp [y1][y2];
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    in >> k;

    in >> n >> m;

    vector<vector<int>> c;
    c.assign(n, {});

    for ( int i = 0; i < n; i++ ){
        c [i].assign(m, 0);
        for ( int j = 0; j < m; j++ ){
            in >> c [i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    for ( int i = 0; i < n; i++ ){
        int sum = 0;
        for ( int j = 0; j < m; j++ ){
            sum += c [i][j];
            csh [i][j] = sum;
        }
    }
    for ( int i = 0; i < m; i++ ){
        int sum = 0;
        for ( int j = 0; j < n; j++ ){
            sum += c [j][i];
            csv [j][i] = sum;
        }
    }

    int ans = n+m-1;

    ans = min(ans, calc(0, m-1, 0, n-1)+n);

    memset(dp, -1, sizeof(dp));

    for ( int i = 0; i < m; i++ ){
        int sum = 0;
        for ( int j = n-1; j >= 0; j-- ){
            sum += c [j][i];
            csh [i][n-j-1] = sum;
        }
    }

    for ( int i = n-1; i >= 0; i-- ){
        int sum = 0;
        for ( int j = 0; j < m; j++ ){
            sum += c [i][j];
            csv [j][n-i-1] = sum;
        }
    }

    ans = min(ans, calc(0, n-1, 0, m-1)+m);

    out << ans << '\n';
}

