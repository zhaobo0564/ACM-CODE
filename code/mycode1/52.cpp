#include<bits/stdc++.h>
using namespace std;
const int N = 107;

char mp[N][N][N];

int n, vis[N][N][N];

int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 0, 1, -1};
int dz[] = {1, -1, 0, 0, 0, 0};

struct node{
    int x, y, z;
    int step;
};

bool judge(int x, int y, int z){
    if(x < 1 || y < 1 || z < 1)
        return false;
    if(x > n || y > n || z > n)
        return false;
    return true;
}

void bfs(){
    queue<node>q;
    q.push({1, 1, 1, 1});
    while(q.size()){
        node cd = q.front();
        q.pop();
     //   cout << cd.x << " " << cd.y << ' ' << cd.z << endl;
        if(cd.x == n && cd.y == n && cd.z == n){
            printf("%d\n", cd.step);
            return;
        }
        for(int i = 0; i < 6; i++){
            int nx = cd.x + dx[i];
            int ny = cd.y + dy[i];
            int nz = cd.z + dz[i];

            if(vis[nx][ny][nz] == 0 && mp[nx][ny][nz] !='*' && judge(nx, ny, nz)){
                vis[nx][ny][nz] = 1;
                q.push({nx, ny, nz, cd.step + 1});
            }


        }

    }
    printf("-1\n");

}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                scanf(" %c", &mp[i][j][k]);
            }
        }
    }
    bfs();
}