#include<stdio.h>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<cstring>
const int N = 200;
using namespace std;
int t, n;
typedef long long ll;

vector<ll> f[N], p[N], g;

ll dp[N][2];



ll dfs(int u, ll minn, int ok) {
    if (u > n) {
        if (ok) return 0;
        return 1e11;
    }
    if (dp[u][ok] != -1) return dp[u][ok];
    ll ans = 1e12;
    for (int i = 0; i < p[u].size(); i++) {
        if (f[u][i] < minn) continue;
        ans = min(ans, dfs(u + 1, minn, (f[u][i] == minn) | ok) + p[u][i]);
    }
    return dp[u][ok] = ans;
    
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            f[i].clear();
            p[i].clear();
        }
        g.clear();
        for (int i = 1; i <= n; i++) {
            int x; scanf("%d", &x);
            for (int j = 1; j <= x; j++) {
                ll u, v; scanf("%lld %lld", &u, &v);
                f[i].push_back(u);
                p[i].push_back(v);
                g.push_back(u);
            }
        }
        sort(g.begin(), g.end());
        g.erase(unique(g.begin(), g.end()), g.end());
        double res = 0.0;
        for (int i = 0; i < g.size(); i++) {
            memset(dp, -1, sizeof(dp));
            ll ans = dfs(1, g[i], 0);
            double cnt = (double)g[i] / (double)ans;
            res = max(res, cnt);
          //  printf("res = %lf\n", cnt);
        }
        printf("%.3lf\n", res);

    }
}

