#include<bits/stdc++.h>
using namespace std;

char mp[100][100];
int n, m;

void work(int x, int y){
    if(mp[x][y] != '*') mp[x][y] = '1';
}
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct node{
    int x, y, step;

};

queue<node>q;
int vis[100][100];

bool judge(int x, int y){
    if(x < 1 || y < 1 || x > n || y > m)
        return false;
    return true;
}

void bfs(int sx, int sy){
    q.push({sx, sy, 0});
    while(q.size()){
        node cd = q.front();
        q.pop();
        if(mp[cd.x][cd.y] == 'E'){
            printf("%d\n", cd.step);
            return;
        }
        for(int i = 0; i < 4; i++){
            int nx = cd.x + dx[i];
            int ny = cd.y + dy[i];
            if(mp[nx][ny] != '1' && vis[nx][ny] == 0 && judge(nx, ny)){
                vis[nx][ny] = 1;
                q.push({nx, ny, cd.step + 1});
            }

        }
    }
    printf("Impossible");
    return;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf(" %c", &mp[i][j]);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(mp[i][j] == '*'){
                mp[i][j] = '1';
                work(i + 1, j);
                work(i - 1, j);
                work(i, j + 1);
                work(i, j - 1);
                work(i + 1, j + 1);
                work(i + 1, j - 1);
                work(i - 1, j + 1);
                work(i - 1, j - 1);
            }
        }
    }
    int f = 0;
    int sx, sy;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(mp[i][j] == 'S'){
                f++;
                sx = i;
                sy = j;
            }else if(mp[i][j] == 'E'){
                f++;
            }
        }
    }
    if(f != 2){
        puts("Impossible");
    }else{
        bfs(sx, sy);
    }

}