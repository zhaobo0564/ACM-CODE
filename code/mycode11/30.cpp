#include <bits/stdc++.h>
using namespace std;

const int N = 2007;

vector<int> g[N];
typedef long long ll;

const ll mod = 998244353;
ll dp[N][N];

ll n, k, sz[N], temp[N][2], sum[N];

void dfs(int u, int fa) {
    sz[u] = 1;
    dp[u][1] = 1;
    for (int to: g[u]) {
        if (to == fa) continue;
        dfs(to, u);
        memset(temp, 0, sizeof(temp));
      

        for (int i = 1; i <= sz[u]; i++) {
            for (int j = 1; j <= sz[to]; j++) {
                if (i <= k && j <= k) {
                    temp[i][0] += dp[to][j] * dp[u][i] % mod;
                    temp[i][0] %= mod;
                }
                if (i + j <= k) {
                    temp[i + j][1] += dp[to][j] * dp[u][i] % mod;
                    temp[i + j][1] %= mod;
                }
            }
        }
        sz[u] += sz[to];
        for (int i = 1; i <= min(sz[u], k); i++) {
            dp[u][i] = (temp[i][0] + temp[i][1]) % mod;
           // printf("dp[%d][%d] = %d\n", u, i, dp[u][i]);
        }
    }
  
    
}
  
int main() {
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        ans += dp[1][i];
        ans = ans % mod;
      //  cout << dp[1][i] << endl;
    }
    cout << ans << endl;
}