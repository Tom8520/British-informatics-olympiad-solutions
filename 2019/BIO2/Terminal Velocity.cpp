#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;

int main(){
	int n;
	cin >> n;

	adj.assign(n+1, {});
	for ( int i = 0; i < n+1; adj [i].assign(n, 0), i++);

	while ( true ){
		int a, b;
		cin >> a >> b;

		if ( a < 0 )break;
		adj [max(a, b)-1][min(a, b)-1] = 1;
	}

	vector<int> order;

	for ( int i = 0; i < n; i++ ){
		for ( int j = 0; j < n; j++ ){
			int cnt = 0;
			for ( int k = 0; k < n+1; k++ ){
				cnt += adj [k][j];
			}
			if ( cnt > 0 )continue;
			order.push_back(j);
			for ( int k = 0; k < n; k++ ){
				adj [j][k] = 0;
				adj [k][j] = 0;
			}
			adj [n][j] = 1;
			break;
		}
	}
	for ( auto i : order ){
		cout << i+1 << " ";
	}
	cout << '\n';
}
