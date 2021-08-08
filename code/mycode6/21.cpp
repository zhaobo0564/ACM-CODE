#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
vector<pair<int, int> > g[N];
int n, d;
long long dp[N];
void dfs(int u, int fa, int limit) {
    if (fa && g[u].size() == 1) {
        dp[u] = 1e6;
    } 
    for (auto it: g[u]) {
        int to = it.first;
        int cost = it.second;
        if (to == fa) continue;
        dfs(to, u, limit);
        if (cost <= limit) {
            dp[u] =dp[u] + min(dp[to], 1ll*cost);
        } else {
            dp[u] += dp[to];
        }
    }
}

int main() {
    scanf("%d %d", &n, &d);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for (int i = 1; i <= 1e3; i++) {
        dfs(1, 0, i);
      //  cout << dp[1] << endl;
        if (dp[1] <= d) {
            printf("%d\n", i);
            return 0;
        }
        for (int j = 1; j <= n; j++) {
            dp[j] = 0;
        }
    }
    cout << "-1\n";
}