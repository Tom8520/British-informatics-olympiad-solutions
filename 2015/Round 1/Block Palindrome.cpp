#include <bits/stdc++.h>

using namespace std;

int Next(vector<string> c, string l){
	if ( l.size() == 0 ){
		vector<string> r = c;
		reverse(r.begin(), r.end());

		for ( int i = 0; i < c.size(); i++){
			if ( c [i] != r [i] )return 0;
		}
		return 1;

	} else{
		vector<string> c1 = c;
		c1.push_back(l.substr(0, 1));
		vector<string> c2 = c;
		if ( c.size() != 0 )c2 [c2.size()-1].push_back(l [0]);
		l = l.substr(1, l.size()-1);

		int t = Next(c1, l);
		if ( c.size() != 0 )t += Next(c2, l);

		return t;
	}
}

int main(){
	string s;
	cin >> s;

	cout << Next({}, s)-1 << '\n';
}
