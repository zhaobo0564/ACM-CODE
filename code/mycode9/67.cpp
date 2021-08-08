#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
bool vis[3*N][3*N][3][4];
struct node {
    int x, y, step, id;
};
queue<node>q;

int n, ans = 0;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool mp[3 * N][3 * N];

void bfs() {
    q.push({0, 0, 0, 0});
    q.push({0, 0, 0, 1});
    while (q.size()) {
        node cd = q.front();
        q.pop();
       // cout << cd.x << " " << cd.y << endl;
        
        if (cd.step % 4  == n % 4 && mp[cd.x + 2000][cd.y + 2000] == 0) {
        // cout << cd.x << " " << cd.y << endl;
            mp[cd.x + 2000][cd.y + 2000] = 1;
            ans++;
           // continue;
        }  
        if (cd.step  == n){
            continue;
        }
        if (vis[cd.x + 2000][cd.y + 2000][cd.id][cd.step % 4]) continue;
        vis[cd.x + 2000][cd.y + 2000][cd.id][cd.step%4] = 1;
        if (cd.id == 0) {
            for (int i = 2; i < 4; i++) {
                int nx = dx[i] + cd.x;
                int ny = dy[i] + cd.y;
                if (vis[nx + 2000][ny + 2000][1][(cd.step + 1) % 4] == 0) {
                    q.push({nx, ny, cd.step + 1,1});
                }
            }
        } else {
            for (int i = 0; i < 2; i++) {
                int nx = dx[i] + cd.x;
                int ny = dy[i] + cd.y;
                if (vis[nx +2000][ny + 2000][0][(cd.step + 1) % 4] == 0) {
                    q.push({nx, ny, cd.step + 1, 0});
                }
            }
        }

    }
    cout << ans << endl;
}

int main() {
    cin >> n;
    bfs();
}