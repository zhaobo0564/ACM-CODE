#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

vector<int>g[N];
int dp[N];

int dfs(int u){
    if(dp[u]) return dp[u];
    if(g[u].size() == 0)return 0;
    for(int to: g[u]){
        int ans = dfs(to);
        dp[u] = max(dp[u], (ans + 1));
    }
    return dp[u];
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
    }
    for(int i = 1; i <= n; i++){
        if(dp[i] == 0){
            dfs(i);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);

    
}