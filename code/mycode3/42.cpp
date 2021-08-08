#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;

vector<pair<int, int> > g[N];
typedef long long ll;
ll dp[N], ans[N], dp1[N];

void dfs1(int u, int fa){
    for(auto it: g[u]){
        int to = it.first;
        int cost = it.second;
        if(to == fa)continue;
        dp1[to] = dp1[u] + cost;
        dfs1(to, u);

    }
}

void dfs(int u, int fa){
    for(auto it: g[u]){
        int to = it.first;
        int cost = it.second;
        if(to == fa) continue;
        dfs(to, u);
        ans[u] = max(dp[u], dp[to] + cost);
        dp[u] = max(dp[u], dp[to] + cost);
    }
    ans[u] = max(ans[u], dp[u]);
}

int main(){
    int n; scanf("%d", &n);
    for(int i = 2; i <= n; i++){
        int u, w;
        scanf("%d %d", &u, &w);
        g[u].push_back({i, w});
        g[i].push_back({u, w});
    }
    dfs1(1, 0);
    for(int i = 1; i <= n; i++){
        cout <<dp1[i] << " " ;
    }
    cout << endl;
    dfs(1, 0);
    for(int i = 1; i <= n; i++){
        printf("%d ", ans[i]);
    }
    puts("");

}