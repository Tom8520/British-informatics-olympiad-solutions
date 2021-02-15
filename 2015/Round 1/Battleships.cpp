#include <bits/stdc++.h>

using namespace std;

int r, a, c, m;

vector<int> ships = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
vector<string> placed;
vector<vector<int>> grid;

void onGrid(int x, int y){
	if ( x < 10 && x >= 0 ){
		if ( y < 10 && y >= 0 ){
			grid [y][x] = 1;
		}
	}
}

void place(){
	r = (a*r+c)%m;
	int x = r%10;
	int y = (r/10)%10;

	r = (a*r+c)%m;

	int valid = 0;

	for ( int i = 0; i < ships [0]; i++ ){
		if ( r % 2 == 0 ){
			if ( x+i >= 10 )valid = 1;
			else valid += grid [y][x+i];
		} else{
			if ( y+i >= 10 )valid = 1;
			else valid += grid [y+i][x];
		}
	}

	if ( valid == 0 ){
		placed.push_back(to_string(x)+" "+to_string(y)+" "+(r%2==0?"H":"V"));
		for ( int i = -1; i < ships [0]+1; i++ ){
			if ( r % 2 == 0 ){
				onGrid(x+i, y);
				onGrid(x+i, y+1);
				onGrid(x+i, y-1);
			} else{
				onGrid(x, y+i);
				onGrid(x+1, y+i);
				onGrid(x-1, y+i);
			}
		}
		ships.erase(ships.begin());
	}
}

int main(){
	r = 0;
	cin >> a >> c >> m;

	grid.assign(10, {});
	for ( int i = 0; i < 10; grid [i].assign(10, 0), i++);

	while ( ships.size() > 0 ){
		place();
	}

	for ( auto i : placed ){
		cout << i << '\n';
	}
}
