#include<bits/stdc++.h>
using namespace std;
char mp[20][20];

int w, h, k;
vector<pair<int, int> >g;
int ok = 0;

bool judge(int x, int y){
    if(mp[x][y] == 'R' || mp[x][y] == 'X')return false;
    if(x < 1 || y < 1 || x > h || y > w)return false;
    return true;
}

void prin(){
    // cout << "*************\n";
    // for(int i = 1; i <= h; i++){
    //     for(int j = 1; j <= w; j++){
    //         cout << mp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

void dfs(int t, int lastx, int lasty, int nowx, int nowy){
    mp[lastx][lasty] = '.';
    mp[nowx][nowy] = 'R';
    if(t == k)return;
    for(int i = 0; i < g.size(); i++){
       // right
       int x = g[i].first;
       int y = g[i].second;
       int lx = x;
       int ly = y;
       while(1){
           y--;
           if(!judge(x, y)){
               break;
           }
       } 
       y++;
       if(mp[x][y] == 'D'){
           ok = 1;
           prin();
           return;
       }
       g[i].first = x;
       g[i].second = y;
       dfs(t + 1, lx, ly, x, y);
       g[i].first = lx;
       g[i].second = ly;
        mp[x][y] = '.';
        mp[lx][ly] = 'R';

        // left
        x = lx;
        y = ly;
        while(1){
            y++;
            if(!judge(x, y)){
                break;
            }
        }
        y--;
        if(mp[x][y] == 'D'){
            ok = 1;
            prin();
            return;
        }
        g[i].first = x;
        g[i].second = y;
        dfs(t + 1, lx, ly, x, y);
        g[i].first = lx;
        g[i].second = ly;
        mp[x][y] = '.';
        mp[lx][ly] = 'R';

        // up
        x = lx;
        y = ly;
        while(1){
            x--;
            if(!judge(x, y)){
                break;
            }
        }
        x++;
        if(mp[x][y] == 'D'){
            ok = 1;
            prin();
            return;
        }
        g[i].first = x;
        g[i].second = y;
        dfs(t + 1, lx, ly, x, y);
        mp[x][y] = '.';
        mp[lx][ly] = 'R';
        g[i].first = lx;
        g[i].second = ly;

        // down
        x = lx;
        y = ly;
        while(1){
            x++;
            if(!judge(x, y)){
                break;
            }
        }
        x--;
        if(mp[x][y] == 'D'){
            ok = 1;
            prin();
            return;
        }
        g[i].first = x;
        g[i].second = y;
        dfs(t + 1, lx, ly, x, y);
        mp[x][y] = '.';
        mp[lx][ly] = 'R';
        g[i].first = lx;
        g[i].second = ly;

    }
}

int main(){
    scanf("%d %d %d", &w, &h, &k);
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            scanf(" %c", &mp[i][j]);
            if(mp[i][j] == 'R'){
                g.push_back({i, j});
            }
        }
    }
    for(int i = 0; i < g.size(); i++){
            int x = g[i].first;
            int y = g[i].second;
            int lx = x;
            int ly = y;
            while(1){
                y--;
                if(!judge(x, y)){
                    break;
                }
            } 
            y++;
            if(mp[x][y] == 'D'){
                ok = 1;
                break;
            }
            g[i].first = x;
            g[i].second = y;
            dfs(1, lx, ly, x, y);
            mp[x][y] = '.';
            mp[lx][ly] = 'R';
            g[i].first = lx;
            g[i].second = ly;

            // left
            x = lx;
            y = ly;
            while(1){
                y++;
                if(!judge(x, y)){
                    break;
                }
            }
            y--;
            if(mp[x][y] == 'D'){
                ok = 1;
                break;
            }
            g[i].first = x;
            g[i].second = y;
            dfs( 1, lx, ly, x, y);
            mp[x][y] = '.';
            mp[lx][ly] = 'R';
            g[i].first = lx;
            g[i].second = ly;

            // up
            x = lx;
            y = ly;
            while(1){
                x--;
                if(!judge(x, y)){
                    break;
                }
            }
            x++;
            if(mp[x][y] == 'D'){
                ok = 1;
                break;
            }
            g[i].first = x;
            g[i].second = y;
            dfs( 1, lx, ly, x, y);
            mp[x][y] = '.';
            mp[lx][ly] = 'R';
            g[i].first = lx;
            g[i].second = ly;

            // down
            x = lx;
            y = ly;
            while(1){
                x++;
                if(!judge(x, y)){
                    break;
                }
            }
            x--;
            if(mp[x][y] == 'D'){
                ok = 1;
                break;
            }
            g[i].first = x;
            g[i].second = y;
            dfs(1, lx, ly, x, y);
            mp[x][y] = '.';
            mp[lx][ly] = 'R';
            g[i].first = lx;
            g[i].second = ly;
    }
    if(ok)puts("YES");
    else puts("NO");

}

/*
6 5 2
R....R
...X..
......
.D....
.R...R
*/