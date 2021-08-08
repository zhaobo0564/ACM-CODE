#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 7;

typedef long long ll;

ll dp_max[N], dp[N], sum[N];

vector<int> g[N];


void dfs(int u, int deep) {
    if (g[u].size() == 0) {
        dp_max[u] = 0;
        sum[u] = 0;
        dp[u] = deep;
        return;
    }
    for (int to: g[u]) {
        dfs(to, deep + 1);
        dp_max[u] = max(dp_max[to] + 1, dp_max[u]);
        sum[u] += sum[to] + 1;
        dp[u] += dp[to];
    }
    ll cat = sum[u] * 2 + deep - dp_max[u];
    dp[u] = min(dp[u], cat);
    
}

int main() {
    int t; scanf("%d", &t);
    int o = 1;
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i <= n + 1; i++) {
            dp[i] = 0;
            dp_max[i] = 0;
            sum[i] = 0;
            g[i].clear();
        }
        for (int i = 2; i <= n; i++) {
            int u; scanf("%d", &u);
            g[u].push_back(i);
        }
        dfs(1, 0);
        printf("Case #%d: ", o++);
        printf("%lld\n", dp[1]);

    }
}