#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;
int a[N], n, dp[N][2];
vector<int>g[N];

void dfs(int u, int fa){
    dp[u][1] = a[u];
    for(int to: g[u]){
        if(to == fa)continue;
        dfs(to, u);
        dp[u][0] += max(0, max(dp[to][1], dp[to][0])); // 要是 当前节点没选， 那么我可以选儿子节点或不选儿子节点
        dp[u][1] += max(0, dp[to][0]); // 如果选当前节点那么儿子节点一定不选
    }
}

int main(){
    while(~scanf("%d", &n)){
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            g[i].clear();
        }
        memset(dp, 0, sizeof(dp));
        int u, v;
        while(~scanf("%d %d", &u, &v) && u && v){
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, 0);
        printf("%d\n", max(dp[1][0], dp[1][1]));
    }
}