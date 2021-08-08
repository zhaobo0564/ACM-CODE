#include<bits/stdc++.h>
using namespace std;

const int N = 302;
typedef long long ll;
ll mp[N][N], n, m, k;
ll cnt[N][N];

ll dp[5507][1007];

int cn[N][N];

void init() {
    int top = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i * j <=  k) {
                cn[i][j] = top++;
            }
        }
    }


}

bool judge(int x, int y) {
    if (x < 0 || y < 0 || x > n || y > m) {
        return false;
    }
    return true;
}

ll dfs(int x, int y, int sum) {
    if (sum - x >= k) {
        return -1e14;
    }
    if (!judge(x, y)) {
        if (sum == k) {
            return 0;
        }
        return -1e14;
    }
    if (cn[x][y] && dp[cn[x][y]][sum] != -1) return dp[cn[x][y]][sum];
    ll ans = -1e14;
    ans = max(ans, dfs(x, y + 1, sum + x) + cnt[x][y + 1]);
    ans = max(ans, dfs(x - 1, y, sum - 1) - mp[x][y]);
    if (sum == k) {
        ans = max(ans, 1ll*0);
    }
    if(cn[x][y]) dp[cn[x][y]][sum] = ans;
    return ans;
    
}

int main() {
    scanf("%lld %lld %lld", &n, &m, &k);
    init();

    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%lld", &mp[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cnt[i][j] = 1ll*mp[i][j] + cnt[i - 1][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(n, 1, n) + cnt[n][1] << endl;

}