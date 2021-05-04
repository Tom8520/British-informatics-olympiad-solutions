#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPat(string s){
	//cout << s << endl;
	if ( s.size() == 1 )return true;
	bool pat = false;

	for ( int i = 1; i < s.size(); i++ ){
		string left = "";
		string right = "";
		int minLeft = 200;
		int maxRight = 0;

		for ( int j = s.size()-1; j >= 0; j-- ){
			if ( j < i ){
				left += s.substr(j, 1);
				minLeft = min((int) s [j], minLeft);
			} else{
				right += s.substr(j, 1);
				maxRight = max((int)s [j], maxRight);
			}
		}

		if ( minLeft <= maxRight )continue;

		if ( isPat(left) && isPat(right) ){
			pat = true;
			break;
		}
	}

	return pat;
}

int main() {
	cout << "Nathan Grange" << endl;
	cout << "Greenhead College" << endl;

	string a, b;
	cin >> a >> b;

	if ( isPat(a) ) cout << "YES" << endl;
	else cout << "NO" << endl;
	if ( isPat(b) ) cout << "YES" << endl;
	else cout << "NO" << endl;
	if ( isPat(a+b) ) cout << "YES" << endl;
	else cout << "NO" << endl;
}
