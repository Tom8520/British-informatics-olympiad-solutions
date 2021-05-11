//bit of a strange solution to this one as but this was the only way i could make it work on the new OJ
//this is the decoded problem statement
/*
Help the Masked Lady decode messages sent to her by the double agents, Quick Brown Fox and Lazy Dog.  Each letter has be
en replaced by "masked": the capitalisation of the "m" indicating the capitalisation of the corresponding letter; that o
f the "asked" forming a binary code (with n indicating letter n in the alphabet).  All other characters are unchanged.

Write a program whose input is an encoded message of between 1 and 1000000 characters.  You should output the decoded me
ssage.
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    string line;
    while ( getline(cin, s) ) {
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
}