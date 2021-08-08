// 记忆化搜索
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
const ll mod = 1e9 + 7;
const int N = 1e5 + 7;
ll dp[12][N];

vector<int> g[N];

void init() {
    for (int i = 2; i < N; i++) {
        for (int j = 1; j <= sqrt(i); j++) {
            if (i % j == 0) {
                g[i].push_back(j);
                if (j > 1 && i / j != j) {
                    g[i].push_back(i / j);
                }
                
            }
        }
    }
}

int main() {
    init();
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++) dp[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        ll sum = 0;
        for (int j = 1; j <= k; j++) {
            sum += dp[i - 1][j];
            sum %= mod;
        }
        for (int j = 1; j <= k; j++) {
            dp[i][j] = sum;
        }
        for (int j = 1; j <= k; j++) {
            for (int z = 0; z < g[j].size(); z++) {
                dp[i][g[j][z]] -= dp[i - 1][j];
                dp[i][g[j][z]] = (dp[i][g[j][z]] + mod) % mod;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= k; i++) {
        ans += dp[n][i];
        ans = ans % mod;
    }
    printf("%lld\n", ans);
    
}