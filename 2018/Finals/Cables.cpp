#include <bits/stdc++.h>

using namespace std;

struct pt{
    int x, y, i;
};

float dist(pt a, pt b){
    return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}

float getAngle(pt A, pt B, pt C){
    float a = dist(B, C);
    float b = dist(A, C);
    float c = dist(A, B);
    return acos((pow(b, 2)+pow(c, 2)-pow(a, 2))/(2*b*c));
}

vector<int> convexHull(vector<pt> p){
    vector<pair<float, int>> points;
    pt temp = {p [0].x, p [0].y-100000};
    for ( int i = 1; i < p.size(); i++ ){
        points.push_back({getAngle(p [0], temp, p [i]), p [i].i});
    }
    points.push_back({200, p [0].i});
    sort(points.begin(), points.end());
    vector<int> ans;
    for ( int i = 0; i < points.size(); i++ ){
        ans.push_back(points [i].second);
    }
    return ans;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int s, l;
    in >> s >> l;

    vector<pt> points;

    for ( int i = 0; i < s*l; i++ ){
        int x, y;
        in >> x >> y;

        points.push_back({x, y, i});
    }

    sort(points.begin(), points.end(), [](pt a, pt b){
        if ( a.x < b.x )return true;
        else if ( a.x > b.x )return false;
        if ( a.y < b.y )return true;
        return false;
    });

    for ( int i = 0; i < l; i++ ){
        vector<pt> a;
        for ( int j = 0; j < s; j++ ){
            a.push_back(points [i*s + j]);
        }
        vector<int> b = convexHull(a);
        for ( auto j : b ){
            out << j+1 << " ";
        }out << '\n';
    }
}