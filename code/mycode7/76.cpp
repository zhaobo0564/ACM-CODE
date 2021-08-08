#include<bits/stdc++.h>
using namespace std;

const int N = 1007;

char mp[N][N];
int n, m, vis[N][N], dp[N][N];

bool judge(int x, int y) {
    if (x < 1 || y < 1 || x > n || y > m) {
        return false;
    }
    return true;
}

int dfs(int x, int y) {
    if (dp[x][y]) return dp[x][y];
    if (vis[x][y]) return 1;
    if (!judge(x, y)) {
        return 2;  
    } 
    vis[x][y] = 1;
    if (mp[x][y] == 'W') {
        dp[x][y] = max(dp[x][y], dfs(x - 1, y));
    } else if (mp[x][y] == 'A') {
        dp[x][y] = max(dp[x][y], dfs(x, y - 1));
    } else if (mp[x][y] == 'S') {
        dp[x][y] = max(dp[x][y], dfs(x + 1, y));
    } else {
        dp[x][y] = max(dp[x][y], dfs(x, y + 1));
    }

    return dp[x][y];

}


int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dfs(i, j) == 2) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}