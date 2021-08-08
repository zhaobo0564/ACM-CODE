#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;
vector<pair<int, ll> >g[N];
ll dp[N][3];

void dfs(int u, int fa){
    for(auto it: g[u]){
        ll cost = it.second;
        int to = it.first;
        if(to == fa)continue;
        dfs(to, u);
        if(dp[u][0] < dp[to][0] + cost){ // 更新最大值
            dp[u][1] = dp[u][0];       // 更新次大值
            dp[u][0] = dp[to][0] + cost;
        }else if(dp[u][1] < dp[to][0] + cost){
            dp[u][1] = dp[to][0] + cost; // 更新次大值
        }
    }
}

void dfs1(int u, int fa){
    for(auto it: g[u]){
        int to = it.first;
        ll cost = it.second;
        if(to == fa)continue;
        if(dp[to][0] + cost == dp[u][0]){
            dp[to][2] = max(dp[u][2] + cost, dp[u][1] + cost); // 选次大值
        }else{
            dp[to][2] = max(dp[u][2] + cost, dp[u][0] + cost); // 选最大值
        }
        dfs1(to, u);
    }
    
  
}

int main(){
    int n;
    while(~scanf("%d", &n)){
        for(int i = 0; i <= n; i++)g[i].clear();
        memset(dp, 0, sizeof(dp));
        for(int i = 2; i <= n; i++){
            int u; ll w;
            scanf("%d %lld", &u, &w);
            g[u].push_back({i, w});
            g[i].push_back({u, w});
        }
        dfs(1, 0);
        dfs1(1, 0);
        for(int i = 1; i <= n; i++){
            printf("%lld\n", max(dp[i][2], dp[i][0]));
        }
    }

}