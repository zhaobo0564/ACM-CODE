#include<bits/stdc++.h>
using namespace std;
char mp[1000][1000];
int n, m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int sx, sy, ex, ey;

bool judge(int x, int y){
    if(x < 1 || y < 1 || x > n || y > m)
        return false;
    return true;
}




queue<pair<int, int> >q;
int vis[1000][1000];
void bfs(){
    q.push({sx, sy});
    vis[sx][sy] = 1;
    while(q.size()){
        auto cd = q.front();
        q.pop();
        if(cd.first == ex && cd.second == ey){
            puts("Yes");
            return;
        }
        for(int i = 0; i < 4; i++){
            int nx = cd.first + dx[i];
            int ny = cd.second + dy[i];
            if(vis[nx][ny] == 0 && mp[nx][ny] != '#' && judge(nx, ny)){
                q.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
    }
    puts("No");
}

int main(){
   
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf(" %c", &mp[i][j]);
            if(mp[i][j] == 's'){
                sx = i;
                sy = j;
            }else if(mp[i][j] == 'g'){
                ex = i;
                ey = j;
            }
        }
    }
    bfs();
    
}