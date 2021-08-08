#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 107;

int n, m, mp[N][N];

bool judge(int x, int y) {
    if (x < 0 || y < 0 || x > n || y > m) {
        return false;
    }
    return true;
}

int vis[N * N];

int dp[N][N];

int dfs(int x, int y) {
    if (!judge(x, y)) {
        return 1e5;
    }
    if (x == n && y == m) {
        return 0;
    }
    if (dp[x][y] != -1) return dp[x][y];
    int ans = 1e5;
    ans = min(ans, dfs(x + 1, y) + y);
    ans = min(ans, dfs(x, y + 1) + x);
    return dp[x][y] = ans;
}

int dfs1(int x, int y) {
    if (!judge(x, y)) {
        return -1e5;
    }
    if (x == n && y == m) {
        return 0;
    }
    if (dp[x][y] != -1) return dp[x][y];
    int ans = -1e5;
    ans = max(ans, dfs1(x + 1, y) + y);
    ans = max(ans, dfs1(x, y + 1) + x);
    return dp[x][y] = ans;
}



int main() {
    int t; cin >> t;
    while (t--) {
        int k;
        cin >> n >> m >> k;
    
        memset(dp, -1, sizeof(dp));
        int minn = dfs(1, 1);
        memset(dp, -1, sizeof(dp));
        int maxn = dfs1(1, 1);
        //cout << minn << " " << maxn << endl;
        if (minn <= k && maxn >= k) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }
}