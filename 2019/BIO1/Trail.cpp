#include <bits/stdc++.h>

using namespace std;

int t, m;
string s;

struct node{
    int x, y;
    node* nxt;
    int depth;

    bool valid(int nx, int ny){
        return (nxt==nullptr?true:nxt->valid(nx, ny))&&(!(x==nx&&y==ny));
    }

    void update(int nx, int ny){
        if ( nxt != nullptr )nxt->update(x, y);
        else if ( depth != t ){
            nxt = new node();
            nxt->x = x;
            nxt->y = y;
            nxt->nxt = nullptr;
            nxt->depth = depth+1;
        }
        x = nx, y = ny;
    }
};

int main(){
    cin >> t >> s >> m;

    int dx = 0, dy = 1;

    node* pos = new node();
    pos->x = 0, pos->y = 0, pos->depth = 1, pos->nxt = nullptr;

    for ( int i = 0; i < m; i++ ){
        if ( s [i%s.size()] == 'R' ){
            swap(dx, dy);
            dy = -dy;
        } else if ( s [i%s.size()] == 'L' ){
            swap(dx, dy);
            dx = -dx;
        }

        int cnt = 0;
        while ( !pos->valid(pos->x + dx, pos->y + dy) && cnt < 4){
            swap(dx, dy);
            dy = -dy;
            cnt++;
        }
        if ( cnt == 4 )break;
        pos->update(pos->x + dx, pos->y + dy);
    }

    cout << "(" << pos->x << ", " << pos->y << ")" << '\n';
}
