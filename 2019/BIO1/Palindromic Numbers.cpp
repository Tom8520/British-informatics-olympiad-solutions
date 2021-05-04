#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;

    bool nines = true;
    for ( int i = 0; i < s.size(); i++ ){
        if ( s [i] != '9' )nines = false;
    }

    if ( nines ){
        cout << "1";
        for ( int i = 0; i < s.size()-1; i++ ){
            cout << "0";
        }
        cout << "1";
        return 0;
    }

    int n = s.size();

    int fh = -1;
    for ( int i = 0; i < n/2; i++ ){
        int j = n-i-1;
        if ( s [i] > s [j] )fh = i;
        else if ( s [i] < s [j] )fh = -1;
    }

    if ( fh == -1 ){
        for ( int i = (n-1)/2; i >= 0; i-- ){
            if ( s [i] != '9' ){
                s [i] = (char)s [i]+1;
                break;
            } else{
                s [i] = '0';
            }
        }
    }


    for ( int i = 0; i < n/2; i++ ){
        cout << s [i];
    }
    if ( n % 2 == 1 )cout << s [n/2];
    for ( int i = n/2 - 1; i >= 0; i-- ){
        cout << s [i];
    }
}
