#include <bits/stdc++.h>

using namespace std;

#define ll long long
vector<ll> fact;

void generateFact(int n){
	fact.assign(n, 1);
	for ( int i = 1; i < n; i++ ){
		fact [i] = fact [i-1]*i;
	}
}

int a, b, c, d;
ll n;

ll ammount(int a, int b, int c, int d){
	if ( a < 0 || b < 0 || c < 0 || d < 0 )return 0;
	return fact [a+b+c+d]/(fact [a]*fact [b]*fact [c]*fact [d]);
}

string Next(string s, ll m){
	if ( a+b+c+d == 0 )return s;
	ll aa = ammount(a-1, b, c, d);
	if ( m <= aa ){
		a--;
		return Next(s+"A", m);
	}
	m -= aa;

	ll bb = ammount(a, b-1, c, d);
	if ( m <= bb ){
		b--;
		return Next(s+"B", m);
	}
	m -= bb;

	ll cc = ammount(a, b, c-1, d);
	if ( m <= cc ){
		c--;
		return Next(s+"C", m);
	}
	m -= cc;

	ll dd = ammount(a, b, c, d-1);
	if ( m <= dd ){
		d--;
		return Next(s+"D", m);
	}
	m -= dd;
}

int main(){
	generateFact(20);

	cin >> a >> b >> c >> d >> n;

	cout << Next("", n) << '\n';
}
