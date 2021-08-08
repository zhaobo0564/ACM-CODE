#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int d[N];
vector<int> g[N];
int dp[N][2], sz[N];

void dfs(int u) {
    dp[u][0] = dp[u][1] = u;
    sz[u] = 1;
    for (int to: g[u]) {
        dfs(to);
        dp[u][0] = max(dp[u][0], dp[to][0]);
        dp[u][1] = min(dp[u][1], dp[to][1]);
        sz[u] += sz[to];

    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        d[v]++;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) {
            dfs(i);
            break;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (sz[i] == (dp[i][0] - dp[i][1] + 1)) {
            ans++;
        }
    }
    cout << ans << endl;
    
}