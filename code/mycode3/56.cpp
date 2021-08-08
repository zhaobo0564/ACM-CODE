#include<bits/stdc++.h>
using namespace std;

int mp[1000][1000];


int m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct node{
    int step;
    int x, y;
    node(){};
    node(int x, int y, int step){
        this->x = x;
        this->y = y;
        this->step = step;
    }
};

bool judge(int x, int y){
    if(x < 0 || y < 0) return false;
    return true;
}

int vis[1000][1000];

int bfs(){
    queue<node>q;
    q.push(node(0, 0, 0));
    while(q.size()){
        node cd = q.front();
      //  cout << cd.x << " " << cd.y << " " << cd.step << endl;
        q.pop();
        if(mp[cd.x][cd.y] > 1000000){
            return cd.step;
        }
        for(int i = 0; i < 4; i++){
            int nx = cd.x + dx[i];
            int ny = cd.y + dy[i];
            
            if(vis[nx][ny] == 0 && mp[nx][ny] > cd.step + 1 && judge(nx, ny)){  
                vis[nx][ny] = 1;
                q.push(node(nx, ny, cd.step + 1));
            }
        }
    }
    return -1;
}

int main(){
    for(int i = 0; i <= 400; i++){
        for(int j = 0; j <= 400; j++){
            mp[i][j] = INT_MAX;
        }
    }
    scanf("%d", &m);
    for(int i = 1; i <= m; i++){
        int x, y, t;
        scanf("%d %d %d", &x, &y, &t);
        mp[x][y] = min(mp[x][y], t);
        mp[x + 1][y] = min(mp[x + 1][y], t);
        if(x - 1 >= 0)mp[x - 1][y] = min(mp[x - 1][y], t);
        mp[x][y + 1] = min(mp[x][y + 1], t);
        if(y - 1 >= 0) mp[x][y - 1] = min(mp[x][y - 1], t);
    }

    printf("%d\n", bfs());
    

}