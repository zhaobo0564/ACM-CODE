#include<bits/stdc++.h>
using namespace std;

const int N = 1000;

int dp[N][N], n, v;

vector<pair<int, int> >g[N];

int dfs(int p, int vl) {
    if (p > n) return 0;
    if (dp[p][vl] != -1) return dp[p][vl];
    int ans = 0;
    for (int i = 1; i < g[p].size(); i++) {
        if (vl - g[p][i].first >= 0) {
            ans = max(ans, dfs(p + 1, vl - g[p][i].first)+ g[p][i].second);
            ans = max(ans, dfs(p + 1, vl));
        } else {
            ans = max(ans, dfs(p + 1, vl));
        }
    }
    return dp[p][vl] = ans;
}

int main() {
    cin >> n >> v;
    for (int i = 1; i <= n; i++) {
        g[i].push_back({0, 0});
        int s; cin >> s;
        for (int j = 1; j <= s; j++) {
            int x, y;
            cin >> x >> y;
            g[i].push_back({x, y});
            
        }
        
    }
    memset(dp, -1, sizeof(dp));
    int ans = dfs(1, v);
    printf("%d\n", ans);
    
    
    
}