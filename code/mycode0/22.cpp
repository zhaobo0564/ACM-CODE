#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int a[N], dp[N], n , sum[N], up[N], top[N], f[N];
vector<int> g[N];

void dfs(int u, int fa){
    if(a[u] == 1)dp[u] = 1;
    else dp[u] = -1;
    for(int i: g[u]){
        if(i == fa)continue;
        dfs(i, u);
        dp[u] = max(dp[i] + dp[u], dp[u]);
    }
}

void dfs1(int u, int fa){
    for(int i: g[u]){
        if(i == fa){
            continue;
        }
        if(dp[i] > 0 && dp[u] - dp[i] > 0 ) dp[i] += dp[u] - dp[i];
        else if(dp[i] <= 0 && dp[u] > 0) dp[i] += dp[u];
        dfs1(i, u);
    }

}


int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if(a[i] == 0)a[i] = -1;
    }
    for(int i = 1; i < n; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    dfs1(1, 0);
    for(int i = 1; i <= n; i++){
        printf("%d ", dp[i]);

    }
    puts("");
}