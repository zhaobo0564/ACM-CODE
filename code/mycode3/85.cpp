#include<bits/stdc++.h>
using namespace std;
const int N = 1007;
vector<pair<int, int> >g[N];

int n, m, cnt;
int dp[N];

void dfs(int u, int fa, int x){
    if(fa && g[u].size() == 1){
        dp[u] = 1e6;
    }
   for(int i = 0; i < g[u].size(); i++){
       int to = g[u][i].first;
       int cost = g[u][i].second;
       if(to == fa)continue;
       dfs(to, u, x);
       if(cost <= x){
           dp[u] += min(dp[to], cost);
       }else{
           dp[u] += dp[to];
       }
   }
}

bool check(int x){
    memset(dp, 0, sizeof(dp));
    dfs(1, 0, x);
    if(dp[1] <= m){
        return true;
    }
    return false;
}



int main(){
    while(~scanf("%d %d", &n, &m) && n){
        for(int i = 1; i <= n; i++){
            g[i].clear();
        }
        for(int i = 1; i < n; i++){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        //cout << dfs(1, 0, 3) << endl;
        int l = 1, r = m, ans = -1;
        while(l <= r){
            int mid = (l + r) / 2;
           // cout << mid << " " << ans << endl;
            if(check(mid)){
                r = mid - 1;
                ans = mid;
            }else{
                l = mid + 1;
            }
        }
        printf("%d\n", ans);


    }
}