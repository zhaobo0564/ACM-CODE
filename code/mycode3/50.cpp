#include<bits/stdc++.h>
using namespace std;
const int N = 20000;
typedef long long ll;
ll dp[N][2];

vector<pair<int, ll> >g[N];

int n, m;

void dfs(int u, int fa){
    for(auto it: g[u]){
        int to = it.first;
        ll cost = it.second;
        if(to == fa)continue;
        dfs(to, u);
        if(dp[u][1] < dp[to][1] + cost){
            dp[u][0] = max(dp[u][0], dp[u][1]);
            dp[u][1] = dp[to][1] + cost;
        }else if(dp[u][0] < dp[to][1] + cost){
            dp[u][0] = dp[to][1] + cost;
        }
    }
}

ll ans[N], deep[N];
void dfs1(int u, int fa){

    for(auto it: g[u]){
        int to = it.first;
        ll cost = it.second;
        if(to == fa) continue;
        if(dp[u][1] == dp[to][1] + cost){
            deep[to] = max(deep[to], dp[u][0] + cost);
            deep[to] = max(deep[to], deep[u] + cost);
        }else{
            deep[to] = max(deep[to], dp[u][1] + cost);
            deep[to] = max(deep[to], deep[u] + cost);
        }
        dfs1(to, u);
    }
}

void dfs2(int u, int fa){
    ans[u] = max(ans[u], dp[u][1]);
    ans[u] = max(ans[u], deep[u]);

    for(auto it: g[u]){
        int to = it.first;
        ll cost = it.second;
        if(to == fa)continue;
        if(dp[to][1] + cost == dp[u][1]){
            ans[to] = max(ans[to], dp[u][0] + cost);
        }else{
            ans[to] = max(ans[to], dp[u][1] + cost);
        }
        dfs2(to, u);
    }
}

int main(){
    while(~scanf("%d", &n)){
        for(int i = 1; i <= n; i++){
            g[i].clear();
            dp[i][0] = 0;
            dp[i][1] = 0;
            deep[i] = 0;
            ans[i] = 0;
        }
        for(int i = 2; i <= n; i++){
            int u, w;
            scanf("%d %d", &u, &w);
            g[u].push_back({i, w});
            g[i].push_back({u, w});
        }
        dfs(1, 0);
        dfs1(1, 0);
        dfs2(1, 0);
        for(int i = 1; i <= n; i++){
            printf("%lld\n", ans[i]);
        }

       
    }
}