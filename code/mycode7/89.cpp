#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

int dp[N][5], n, m, vis[N];
vector<int> g[N];

void dfs(int u, int fa) {
    if (vis[u]) {
        dp[u][0] = 0;
        dp[u][1] = 0;
    }
    for (int to: g[u]) {
        if (to == fa) {
            continue;
        }
        dfs(to, u);
        
        if (dp[to][0] + 1 >= dp[u][0]) {
            dp[u][2] = max(dp[u][2], dp[u][0]);
            dp[u][0] = dp[to][0] + 1;
        } else if (dp[to][0] + 1 > dp[u][2]) {
            dp[u][2] = max(dp[u][2], dp[to][0] + 1);
        }
        if (dp[to][1] + 1 <= dp[u][1]) {
            dp[u][4] = min(dp[u][4], dp[u][1]);
            dp[u][1] = dp[to][1] + 1;
        } else if (dp[u][4] > dp[to][1] + 1) {
            dp[u][4] = min(dp[to][1] + 1, dp[u][4]);
        }
    }
}

int ans = 0, fn[N][2];

void dfs1(int u, int fa, int maxn, int minn)  {
    if (maxn == minn) {
       
        ans = u;
    }

    for (int to: g[u]) {
        if (to == fa) {
            continue;
        }
        if (dp[u][0] == dp[to][0] + 1) {
            fn[to][0] = dp[u][2] + 1;
        } else {
            fn[to][0] = dp[u][0] + 1;
        }
        fn[to][0] = max(fn[to][0], fn[u][0] + 1);
        if (dp[u][1] == dp[to][1] + 1) {
            fn[to][1] = dp[u][4] + 1;
        } else {
            fn[to][1] = dp[u][1] + 1;
        }
        fn[to][1] = min(fn[to][1], fn[u][1] + 1);
        dfs1(to, u, max(fn[to][0], dp[to][0]), min(fn[to][1], dp[to][1]));
        
        
    }

   
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        fn[i][0] = -1e9;
        fn[i][1] = 1e9;
    }
    for (int i = 1; i <= n; i++) {
        dp[i][1] = 1e9;
        dp[i][0] = -1e9;
        dp[i][2] = -1e9;
        dp[i][4] = 1e9;
    }
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= m; i++) {
        int x; scanf("%d", &x);
        vis[x] = 1;
    }
    dfs(1, 0);
   // cout << dp[1][0] << " " << dp[1][1] << endl;
    dfs1(1, 0, dp[1][0], dp[1][1]);
    if (ans) {
        puts("YES");
        printf("%d\n", ans);
    } else {
        puts("NO");
    }
}

