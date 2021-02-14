#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	int t, w;
	cin >> t >> w;

	vector<int> s(t);
	vector<ll> sCum(t);

	for ( int i = 0; i < t; i++ ){
		cin >> s [i];
		if ( i == 0 )sCum [i] = s [i];
		else sCum [i] = sCum [i-1] + s [i];
	}

	vector<int> u(w);

	int mu = 0;

	for ( int i = 0; i < w; i++ ){
		cin >> u [i];
		mu = max(mu, u [i]);
	}

	vector<ll> dp [mu+1];

	dp [0] = {0, -1};

	for ( int i = 1; i < mu+1; i++ ){
		vector<ll> n = {};

		vector<ll> c = {};

		if ( i <= t ){
			c = {sCum [i-1], i-1};
		}

		if ( c.size() > 0 ){
			n = c;
		}

		for ( int j = 1; j < dp [i-1].size(); j++){

			vector<ll> d1 = {};

			if ( dp [i-1][j] > 0){
				d1 = {dp [i-1][0] + s [dp [i-1][j]-1], dp [i-1][j]-1};
			}

			vector<ll> d2 = {};

			if ( dp [i-1][j] != t-1 && dp [i-1][j] != -1 ){
				d2 = {dp [i-1][0] + s [dp [i-1][j]+1], dp [i-1][j]+1};
			}

			if ( d1.size() > 0 ){
				if ( n.size() == 0 ){
					n = d1;
				} else{
					if ( d1 [0] > n [0] ){
						n = d1;
					} else if ( d1 [0] == n [0] ){
						n.push_back(d1 [1]);
					}
				}
			}
			if ( d2.size() > 0 ){
				if ( n.size() == 0 ){
					n = d2;
				} else{
					if ( d2 [0] > n [0] ){
						n = d2;
					} else if ( d2 [0] == n [0] ){
						n.push_back(d2 [1]);
					}
				}
			}
		}

		dp [i] = n;
	}

	ll sum = 0;

	for ( int i = 0; i < w; i++ ){
		sum += dp [u [i]][0];
	}

	cout << (ll) sum << endl;
}

