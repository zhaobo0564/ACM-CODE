#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

vector<pair<int, int> >g[N];
int t, n, v[N], dp[N][3], father[N];

void dfs(int u, int fa){
    dp[u][0] = v[u];
    father[u] = fa;
    for(auto it: g[u]){
        int to = it.first;
        int cost = it.second;
        if(to == fa)continue;
        dfs(to, u);
        if(dp[u][0] < dp[to][0] + cost + v[u]){
            dp[u][1] = dp[u][0];
            dp[u][0] = dp[to][0] + cost + v[u];
        }
      
    }
}

void dfs1(int u){
    dp[u][1] = dp[father[u]][1];
    if(father[u]){
        int w = 0;
        for(int i = 0; i < g[father[u]].size(); i++){
            int to = g[father[u]][i].first;
            int cost = g[father[u]][i].second;
            if(to == father[father[u]])continue;
            if(to == u){
                w = cost;
            }else{
                dp[u][2] = max(dp[u][2], dp[to][0] + cost + v[father[u]]);
            }
        }
        dp[u][2] += w + v[u];
    }
    for(int i = 0; i < g[u].size(); i++){
        int to = g[u][i].first;
        if(to == father[u])continue;
        dfs1(to);
    }
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &v[i]);
        }
        for(int i = 1; i < n; i++){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            g[u].push_back({v, -w});
            g[v].push_back({u, -w});
        }
        dfs(1, 0);
        // for(int i = 1; i <= n; i++){
        //     cout << dp[i][0] <<" " << dp[i][1] << endl;
        // }

        dfs1(1);
        
        for(int i = 1; i <= n; i++){
            int ans = max(dp[i][0], dp[i][2]);
            if(dp[i][0] != 0){
                ans = max(ans, dp[i][0] + dp[i][1] - v[i]);
            }else{
                ans = max(ans, dp[i][0] + dp[i][1]);
            }
            ans = max(ans, dp[i][2] + dp[i][0] - v[i]);
            printf("%d\n", ans);
           cout << dp[i][0] <<" "<<dp[i][1] <<" "<<dp[i][2]<< endl;
        }

    }
}