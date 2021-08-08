#include<bits/stdc++.h>
using namespace std;
const int N = 1007;

int mp[N][N], n, m, k, d;

bool judge(int x, int y) {
    if (x < 1 || y < 1 || x > n || y > n) {
        return false;
    }
    return true;
}

queue<pair<int, pair<int, int> > >q;

int vis[N][N], dist[N][N];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void bfs() {
    
    while (q.size()) {
        auto it = q.front();
        q.pop();
        if (vis[it.first][it.second.first]) continue;
        vis[it.first][it.second.first] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = it.first + dx[i];
            int ny = it.second.first + dy[i];
            if (judge(nx, ny) && mp[nx][ny] != -2) {
                if (dist[nx][ny] > it.second.second + 1) {
                    dist[nx][ny] = it.second.second + 1;
                    q.push({nx, {ny, dist[nx][ny]}});
                }
            }
        }
    }   
}


int main() {
    scanf("%d %d %d %d", &n, &m, &k, &d);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mp[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = 1e8;
            vis[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d %d", &x, &y);
        mp[x][y] = -1;
        q.push({x, {y, 0}});
        dist[x][y] = 0;
    }
    for (int i = 1; i <= k; i++) {
        int x, y, c; scanf("%d %d %d", &x, &y, &c);
        mp[x][y] += c;
    }
    for (int i = 1; i <= d; i++) {
        int x, y; scanf("%d %d", &x, &y);
        mp[x][y] = -2;
    }

    long long ans = 0;
    bfs();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mp[i][j] >= 0) {
              //  cout << "dist " << dist[i][j] << endl;
                ans = ans + (long long)dist[i][j] * (long long)mp[i][j];
            }
        }
    }
    cout << ans << endl;
}