#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int c, t;

struct point{
	ll x, y;
public:
	point();
	point(ll a, ll b);

};

point::point(ll a, ll b){
	x = a;
	y = b;
}
point::point(){};

ld getLength(point a, point b){
	return sqrt(pow(a.x-b.x, 2)+pow(a.y-b.y, 2));
}

ld getAngle(point a, point b, point c){
	ld d = getLength(a, b);
	ld e = getLength(a, c);
	ld f = getLength(b, c);
	if ( d*e == 0 )return 0;
	return acos((pow(d, 2)+pow(e, 2)-pow(f, 2))/(2*d*e));
}

ld getArea(point a, point b, point c){
	return 0.5*getLength(a, b)*getLength(a, c)*sin(getAngle(a, b, c));
}

vector<point> v, w;

bool isValid(point a, point b){
	ld m = a.x-b.x == 0 ? 0 : (a.y-b.y)/(a.x-b.x);
	for ( auto p : w ){
		if ( a.x-b.x == 0 ){
			if ( a.y > b.y ){
				if ( p.x <= a.x )return false;
			} else{
				if ( p.x >= a.x ) return false;
			}
			continue;
		}
		if ( a.y >= b.y ){
			if ( m <= 0 ){
				if ( p.y-a.y <= m*(p.x-a.x) )return false;
			} else{
				if ( p.y-a.y >= m*(p.x-a.x) )return false;
			}
		} else{
			if ( m < 0 ){
				if ( p.y-a.y >= m*(p.x-a.x) )return false;
			} else{
				if ( p.y-a.y <= m*(p.x-a.x) )return false;
			}
		}
	}
	return true;
}


int main(){
	cin >> c >> t;

	v.assign(c, point());
	w.assign(t, point());

	for ( int i = 0; i < c; i++ ){
		ll x, y;
		cin >> x >> y;
		v [i] = point(x, y);
	}

	for ( int i = 0; i < t; i++ ){
		ll x, y;
		cin >> x >> y;
		w [i] = point(x, y);
	}

	ld area = 0;
	ld currentArea = 0;

	int a = 0;
	int b = 1;
	int pa = 0;
	int pb = 0;

	while ( b != a ){
		currentArea += getArea(v [a],v [b], v [pb]);

		if ( isValid(v [a], v [b]) ){
			pb = b;
			if ( b != 0 )b++;
			b %= c;
			area = max(area, currentArea);
		} else{
			pa = a;
			a++;
			currentArea -= getArea(v [a], v [b], v [pa]);
		}
		//cout << a << " " << b << " - " << currentArea << '\n';
	}

	cout << floor(area) << '\n';

}
