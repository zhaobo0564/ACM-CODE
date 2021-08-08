#include<bits/stdc++.h>
using namespace std;

const int N = 40;

int w, h;
char mp[N][N];

int vis[N][N];

int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};

int bfs(int x, int y) {
    int ans = 0;
    queue<pair<int, int> >q;
    q.push({x, y});
    while (q.size()) {
        auto cd = q.front();
        q.pop();
        if (vis[cd.first][cd.second]) continue;
        vis[cd.first][cd.second] = 1;
      //  cout << cd.first << " " << cd.second << endl;
        ans++;
        for (int i = 0; i < 4; i++) {
            int nx = cd.first + dx[i];
            int ny = cd.second + dy[i];
            if (nx >= 1 && ny >= 1 &&nx <= w && ny <= h && mp[nx][ny] == '.') {
                q.push({nx, ny});
            }
        }
    }
    return ans;
    
}

int main() {
    while (cin >> w >> h){
        swap(w, h);
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= w; i++) {
            for (int j = 1; j <= h; j++) {
                cin >> mp[i][j]; 
            }
        }
       // cout << mp[6][2] << endl;
        for (int i = 1; i <= w; i++) {
            for (int j = 1; j <= h; j++) {
                if (mp[i][j] == '@') {
                    cout << bfs(i, j) << endl;
                    break;
                }
            }
    }
    }
    
}