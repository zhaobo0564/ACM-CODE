#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int k[N], n;
vector<int>g[N];
int f[N];
int ans = 0;

void dfs(int u, int fa){
    int flag = 0;
    for(int to: g[u]){
        if(to == fa)continue;
        dfs(to, u);
        f[u] = max(f[u], f[to] - 1);
        k[u] = max(k[u], k[to] - 1);
    }
    if(f[u] < 1){
        ans++;
        f[u] = k[u];
    }

}

int main(){
    scanf("%d", &n);
    for(int i = 2; i <= n; i++){
        int x; scanf("%d", &x);
        g[i].push_back(x);
        g[x].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        scanf("%d", &k[i]);
    }
    dfs(1, 0);
   // cout << dp[2][1] << " " << dp[3][1] << endl;
    printf("%d\n", ans);

}