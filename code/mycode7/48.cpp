#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[80][80][70][80];

int mp[100][100], k, n, m;

bool judge(int x, int y) {
    if (x < 1 || y < 1 || x > n || y > m) {
        return false;
    }
    return true;
}

int dfs(int x, int y, int cnt, int sum) {
    if (!judge(x, y)) {
        if (sum == 0) {
            //cout << "**\n";
            return 0;
        }
        return -1e8;
    }
    if (dp[x][y][cnt][sum] != -1) return dp[x][y][cnt][sum];

    int ans = -1e8;
    ans = max(ans, dfs(x, y + 1, cnt, sum));
    ans = max(ans, dfs(x + 1, 1, 0, sum));
    if (cnt < m / 2) {
        ans = max(ans, dfs(x, y + 1, cnt + 1, (sum + mp[x][y]) % k ) + mp[x][y]);
    }
    if (cnt < m / 2) {
        ans = max(ans, dfs(x + 1, 1, 0, (sum + mp[x][y]) % k ) + mp[x][y]);
    }
    return dp[x][y][cnt][sum] = ans;
}



int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(1, 1, 0, 0) << endl;
}