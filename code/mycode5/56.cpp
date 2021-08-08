#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e4 + 7;

typedef long long ll;

ll dp[2021], fn[2021];
int n;

vector<pair<int, int> >g[N];
ll ans = 0;

void dfs(int u, int fa) {
    for (auto it : g[u]) {
        int to = it.first;
        int cost = it.second;
        if (to == fa) continue;
        
        for (int i = 0; i < 2019; i++) {
            fn[i] = 0;
        }
        for (int i = 0; i < 2019; i++) {
            if(dp[i]) {
                fn[(i + cost) % 2019] += dp[i];
            }
        }
        fn[cost]++;
        ans += fn[0];
        for (int i = 0; i < 2019; i++) {
            dp[i] = fn[i];
        }
        dfs(to, u);

    }
}

int main() {
    while (~scanf("%d", &n)) {
        ans = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        dfs(1, 0);
        printf("%lld\n", ans);
    }
}