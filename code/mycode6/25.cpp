#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 207;

int n, m, t, vis[N][N];

ll mp[N][N];

char s[N][N];

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

struct node{
    int x, y, d;
};

bool judge(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m) {
        return false;
    }
    return true;
}

ll bfs(int x, int y, int xend, int yend) {
    queue<node> q;
    q.push({x, y, 0});
    memset(vis, 0, sizeof(vis));
    while (q.size()) {
        auto cd = q.front();
        q.pop();
        if (cd.x == xend && cd.y == yend) {
            
            return cd.d;
        }
        for (int i = 0; i < 4; i++) {
            int nx = cd.x + dx[i];
            int ny = cd.y + dy[i];
            if (vis[nx][ny] == 0 && s[nx][ny] != '#' && judge(nx, ny)) {
                q.push({nx, ny, cd.d + 1});
                vis[nx][ny] = 1;
            } 
        }
        
    }    

    return 1e12;
}

vector<pair<int, int> >v;
int cnt;
ll dp[20][1000000];

ll dfs(int p, int sum) {
    if (p == 0) {
        if (sum == (1 << cnt) - 1) {
            return 0;
        }
        return 1e11;
    }
    if (dp[p][sum] != -1) return dp[p][sum];
    ll ans = 1e11;
    for (int i = 0; i < cnt; i++) {
        if (sum & (1 << i)) continue;
        ans = min(ans, dfs(i, sum | (1 << i)) + mp[p][i]);
    }
    return  dp[p][sum] = ans;
}

int main() {
    scanf("%d %d %d", &n, &m, &t);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %c", &s[i][j]);
            if (s[i][j] == 'S')  {
                v.push_back({i, j});
            }
        } 
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == 'T') {
                v.push_back({i, j});
            }
        }
    }
    cnt = v.size();
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            mp[i][j] = bfs(v[i].first, v[i].second, v[j].first, v[j].second);
        }
    }
  

      
    
    
    
    ll ans = 1e17;
    memset(dp, -1, sizeof(dp));
  
    for (int i = 0; i < cnt; i++) {
       ans = min(ans, dfs(i,  (1 << i)) + mp[0][i]); 
    }
    if (ans > 1000000) {
        cout << "-1\n";
    }else 
    cout << ans + t * (cnt - 1)<< endl;
    
    
    
    
    
    
}