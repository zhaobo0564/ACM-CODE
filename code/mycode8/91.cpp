#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int dp[N], ans;
char s[N];

vector<int> g[N];

void dfs(int u, int fa) {
    for (int to: g[u]) {
        if (to == fa) continue;
        dfs(to, u);
        if (s[u] != s[to]) {
            ans = max(ans, dp[u] + dp[to] + 1);
            dp[u] = max(dp[u], dp[to] + 1);
        }

        
    }
}

int main() {
    int n; scanf("%d", &n);
    scanf("%s", s + 1);

    for (int i = 1; i < n; i++) {
        int u, v; 
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    printf("%d\n", ans);
}