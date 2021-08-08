#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int> >g;

int n, sx, sy;

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

int main(){
    scanf("%d %d %d", &n, &sx, &sy);
    for(int i = 1; i <= n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        g.push_back({x, y});
    }
    int posx, posy;
    int manx = 0;
    int ans = 0;
    for(auto it: g){
        if(it.first < sx){
            ans++;
        }
    }
    manx = ans;
    posx = sx - 1, posy = sy;
    ans = 0;
    for(auto it: g){
        if(it.first > sx){
            ans++;
        }
    }
    if(ans >   manx){
        manx = ans;
        posx = sx + 1;
        posy = sy;
    }
    ans = 0;
    for(auto it : g){
        if(it.second < sy){
            ans++;
        }
    }
    if(ans >   manx){
          manx = ans;
        posy = sy - 1;
        posx = sx;
    }
    ans = 0;
    for(auto it: g){
        if(it.second > sy){
            ans++;
        }
    }
    if(ans >   manx){
          manx = ans;
        posx = sx;
        posy = sy + 1;
    }
    cout <<   manx << endl;
    cout << posx <<  " " << posy << endl;
}