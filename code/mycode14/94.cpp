#include<bits/stdc++.h>
using namespace std;
const int N = 507;

int a[N][N], b[N][N], c[N][N], n, m;

void work(int x, int y) {
    for (int i = x + 1; i <= n; i++) {
        if (b[i][y] == 0) {
            b[i][y] = 1;
            a[i][y] = 0;
        }
    }
}

int vis[N][N];
queue<pair<int, int> > q;

int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};

void bfs(int x, int y) {
    q.push({x, y});
    while (q.size()) {
        auto cd = q.front();
        q.pop();
        if (vis[cd.first][cd.second]) continue;
        vis[cd.first][cd.second] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = cd.first + dx[i];
            int ny = cd.second + dy[i];
            if (a[nx][ny])
                q.push({nx, ny});
        }
    }
}

void bfs1(int x, int y) {
    q.push({x, y});
    while (q.size()) {
        auto cd = q.front();
        q.pop();
        if (vis[cd.first][cd.second]) continue;
        vis[cd.first][cd.second] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = cd.first + dx[i];
            int ny = cd.second + dy[i];
            if (b[nx][ny])
                q.push({nx, ny});
        }
    }
}



int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &c[i][j]);

            a[i][j] = 1;
            b[i][j] = c[i][j];
        }
    }
    for (int j = 1; j <= m; j++) {
        a[n][j] = 0;
        b[n][j] =1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (b[i][j]) {
                work(i, j);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] && vis[i][j] == 0) {
                bfs(i, j);
                ans++;
            }
        }
    }
  //  cout <<"ans " << ans << endl;
   // if (ans > 1) while (1);
    ans = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (b[i][j] && vis[i][j] == 0) {
                bfs1(i, j);
                ans++;
            }
        }
    }
    //if (ans > 1) while(1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout <<a[i][j] ;
        }
        cout << endl;
    }
    cout << "******\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout <<b[i][j] ;
        }
        cout << endl;
    }


}

