#include<bits/stdc++.h>
using namespace std;

const int N = 200;
int dp[N][N], n, a[N];

vector<int>g[N];

int ans = 0;

int temp[N];

void dfs(int u, int fa){
    dp[u][a[u]] = 1;
    ans = max(ans, a[u]);
    for(int to: g[u]){
        if(to == fa)continue;
        dfs(to, u);
        for(int i = 0; i <= 130; i++){
            temp[i] = dp[u][i];
        }
        for(int i = 0; i <= 130; i++){
            for(int j = 0; j <= 130; j++){
                if(temp[i] && dp[to][j]){
                    dp[u][i ^ j] = 1;
                    ans = max(ans, i ^ j);
                }
            }
        }
        
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i < n; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    printf("%d\n", ans);
}