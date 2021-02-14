#include <iostream>
#include <vector>

using namespace std;

string numeral(int n){
	string k = to_string(n);

	string res = "";

	string tens [4] = {"I", "X", "C", "M"};
	string fives [3] = {"V", "L", "D"};

	for ( int i = k.size()-1; i >= 0; i-- ){
		int d = stoi(k.substr(i, 1));

		int j = k.size()-i-1;

		string a = "";

		if ( d == 1 )a += tens [j];
		else if ( d == 2 )a += tens [j] + tens [j];
		else if ( d == 3 )a += tens [j] + tens [j] + tens [j];
		else if ( d == 4 )a += tens [j] + fives [j];
		else if ( d == 5 )a += fives [j];
		else if ( d == 6 )a += fives [j] + tens [i];
		else if ( d == 7 )a += fives [j] + tens [j] + tens [j];
		else if ( d == 8 )a += fives [j] + tens [j] + tens [j] + tens [j];
		else if ( d == 9 )a += tens [j] + tens [j+1];

		res = a + res;
	}

	return res;
}

string lookAndSay(string n){
	vector<pair<char, int>> parts;

	char current = ' ';
	int len = 0;

	for ( int i = 0; i < n.size(); i++ ){
		if ( n [i] == current )len++;
		else{
			if ( len != 0 ){
				parts.push_back({current, len});
			}
			len = 1;
			current = n [i];
		}
	}

	parts.push_back({current, len});

	string res = "";

	for ( auto i : parts ){
		res += numeral(i.second);
		res.push_back(i.first);
	}

	return res;
}

int main(){
	string s;
	int n;

	cin >> s >> n;

	while ( n-- ){
		s = lookAndSay(s);
	}

	int i = 0, v = 0;

	for ( auto j : s ){
		if ( j == 'I' )i++;
		else if ( j == 'V' )v++;
	}

	cout << i << " " << v << endl;
}

