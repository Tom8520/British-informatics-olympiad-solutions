#include <bits/stdc++.h>

using namespace std;

int n;

vector<vector<int>> g;
vector<bool> visited;

int BFS(int s){
	queue<int> q;
	vector<int> d(n, -1);

	q.push(s);
	d [s] = 0;

	while ( !q.empty() ){
		int v = q.front();
		q.pop();

		if ( !visited [v] ){
			visited [v] = true;

			for ( auto i : g [v] ){
				if ( !visited [i] && (d [i] == -1 || d [i] > d [v]+1 )){
					q.push(i);
					d [i] = d [v]+1;
				}
			}
		}
	}

	int even = 0, odd = 0;

	for ( int i = 0; i < n; i++ ){
		if ( d [i] >= 0 ){
			if ( d [i] % 2 == 0 )even++;
			else odd++;
		}
	}

	return max(odd, even);
}

int main(){
	cin >> n;

	g.assign(n, {});

	int a, b;
	cin >> a >> b;

	while ( a > 0 && b > 0 ){
		g [a-1].push_back(b-1);
		g [b-1].push_back(a-1);

		cin >> a >> b;
	}

	visited.assign(n, false);

	int t = 0;

	for ( int i = 0; i < n; i++ ){
		if ( !visited [i] )t += BFS(i);
	}

	cout << t << '\n';
}
