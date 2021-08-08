#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3007;

ll mp[N][N], n, m, k, dp[N][N][5];

bool judge(int x, int y) {
    if (x < 1 || y < 1 || x > n || y > m) {
        return true;
    }
    return false;
}

ll dfs(int x, int y, int c) {
    if (judge(x, y)) return 0;
    //cout << x << " " << y << endl;
    ll ans = 0;
    if (dp[x][y][c] != -1) return dp[x][y][c];
    if (mp[x][y]) {
      
        if (c < 3) {
            ans = max(ans, dfs(x + 1, y, 0) + mp[x][y]);
        }
        ans = max(ans, dfs(x + 1, y, 0));
    
    
        if (c < 3) {
            ans = max(ans, dfs(x, y + 1, c + 1) + mp[x][y]);
        }
        ans = max(ans, dfs(x, y + 1, c));
        
    } else {
     
        ans = max(ans, dfs(x + 1, y, c));
    
        ans = max(ans, dfs(x, y + 1, c));
        
    }
    return dp[x][y][c] = ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        mp[x][y] = w;
    }
    memset(dp, -1, sizeof(dp));
    ll ans = dfs(1, 1, 0);

    printf("%lld\n", ans);

}