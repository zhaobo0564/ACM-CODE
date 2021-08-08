#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;
int dp[N][2], n, a[N], fa[N];
vector<int>g[N];

void dfs(int u){
    //cout << u << endl;
    dp[u][1] = a[u];
    for(int to: g[u]){
        if(to == fa[u])continue;
        dfs(to);
        dp[u][0] += max(0, max(dp[to][1], dp[to][0]));
        dp[u][1] += max(0, dp[to][0]);
    }

}

int main(){
    while(~scanf("%d", &n)){
        memset(dp, 0, sizeof(dp));
        memset(fa, 0, sizeof(fa));
        for(int i = 1; i <= n; i++){
            g[i].clear();
        }
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        
        int u, v;
        while(~scanf("%d %d", &u, &v)&& u && v){
            fa[u] = v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        int rt;
        for(int i = 1; i <= n; i++){
            if(fa[i] == 0){
                rt = i;
                break;
            }
        }
        dfs(rt);
        printf("%d\n", max(dp[rt][1], dp[rt][0]));
    }


}

