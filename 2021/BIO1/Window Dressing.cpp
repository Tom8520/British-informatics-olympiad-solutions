#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define ll long long

vector<int> used(87654322, 99999);

vector<char> alpha = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

int minMoves(string s, int cm){
	if ( s.size() == 0 )return 0;
	//cout << s << endl;

	string num = "";

	for ( int i = 0; i < s.size(); i++ ){
		num += to_string((int)s [i] - 64);
	}

	if ( cm > used [stoll(num)] )return 99999;
	used [stoll(num)] = cm;

	if ( s [s.size()-1] == alpha [s.size()-1] ){
		return 1 + minMoves(s.substr(0, s.size()-1), cm+1);
	}

	int ro = minMoves(s.substr(s.size()-1, 1) + s.substr(0, s.size()-1), cm+1);
	int sw = minMoves(s.substr(1, 1) + s.substr(0, 1) + s.substr(2, s.size()-2), cm+1);

	return 1 + min(ro, sw);
}

int main() {
	cout << "Nathan Grange" << endl;
	cout << "Greenhead College" << endl;

	string s;
	cin >> s;

	cout << minMoves(s, 0) << endl;
}
