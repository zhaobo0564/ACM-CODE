#include<bits/stdc++.h>
using namespace std;
const int N = 2e4 + 7;
typedef long long ll;
vector<pair<int, int> > g[N];

int n;
ll dp[N][2021], ans = 0;

void dfs(int u, int fa) {
    for (auto it: g[u]) {
        int to = it.first;
        int cost = it.second;
        if (to == fa) continue;
        dfs(to, u);
        ll cn = 0;
        for (int i = 0; i < 2019; i++) {
            if (dp[to][i]) {
                ll cat = dp[to][i];
                cn += dp[u][(2019 - (i + cost) % 2019 + 2019) % 2019] * cat;  
            }
        }
        cn += dp[u][(2019 - cost) % 2019];
        ans += cn;
        for (int i = 0; i < 2019; i++) {
            if (dp[to][i]) {
                int cnt = dp[to][i];
                dp[u][(i + cost) % 2019] += cnt; 
            }
        }
        dp[u][cost]++;
    }
}

int main() {
    while (~scanf("%d", &n)) {
        ans = 0;
        for (int i = 0; i <= n; i++) {
            g[i].clear();
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 2019; j++) {
                dp[i][j] = 0;
            }
        }
        for (int i = 1; i < n; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        dfs(1, 0);
        for (int i = 1; i <= n; i++) {
            ans += dp[i][0];
        }
        printf("%lld\n", ans);
    }
}
