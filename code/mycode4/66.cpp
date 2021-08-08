#include<bits/stdc++.h>
using namespace std;

char mp[200][200];
int n, sx, sy, ex, ey;

int dist[200][200], vis[200][200];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct node{
    int x, y, v, id;
    bool operator < (const node c)const{
        return v > c.v;
    }
};

bool judge(int x, int y){
    if(x < 1 || x > n || y < 1 || y > n)
        return false;
    return true;
}

priority_queue<node> q;

void dij(int x, int y, int id){
    for(int i = 0; i <=110; i++){
        for(int j = 0; j <= 110; j++){
            dist[i][j] = 1e5;
            vis[i][j] = 0;
        }
    }

    if(!judge(x, y) || mp[x][y] == 'x')return;
    q.push({x, y, 0, id});
    dist[x][y] = 0;
    while(q.size()){
       node cd = q.top();
       q.pop();
       if(vis[cd.x][cd.y])continue;
       vis[cd.x][cd.y] = 1;
       for(int i = 0; i < 4; i++){
           int nx = cd.x + dx[i];
           int ny = cd.y + dy[i];
           if(judge(nx, ny) && mp[nx][ny] != 'x'){
               int cost = 0;
               if(cd.id != i){
                   cost = 1;
               }
               if(dist[nx][ny] > dist[cd.x][cd.y] + cost){
                   dist[nx][ny] = dist[cd.x][cd.y] + cost;
                   q.push({nx, ny, dist[nx][ny], i});
               }
           }
       }
   }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf(" %c", &mp[i][j]);
            if(mp[i][j] == 'A'){
                sx = i, sy = j;
            }else if(mp[i][j] == 'B'){
                ex = i, ey = j;
            }
        }
    }
    if(sx == 0 || ex == 0){
        puts("-1");
        return 0;
    }
    int ans = 100000;
    dij(sx + 1, sy, 0);
    while(q.size())q.pop();
    ans = min(ans, dist[ex][ey]);
    dij(sx, sy + 1, 1);
    while(q.size())q.pop();
    ans = min(ans, dist[ex][ey]);
    dij(sx - 1, sy, 2);
    while(q.size())q.pop();
    ans = min(ans, dist[ex][ey]);
    dij(sx, sy - 1, 3);
    while(q.size())q.pop();
    ans = min(ans, dist[ex][ey]);

    if(ans >= 100000){
        puts("-1");
    }else{
        printf("%d\n", ans);
    }

}

