#include<iostream>
#include<vector>
#include<stdio.h>
#include<math.h>
using namespace std;
typedef long long ll;
const int N = 100007;

vector<int>g[N];

ll a[N];
int n, m, vis[N];

ll sizes[N];

void dfs(int u, int fa){
    sizes[u] = a[u];
 //   vis[u] = 1;
    for(int i = 0; i < g[u].size(); i++){
        int to = g[u][i];
        if(to == fa)continue;
      //  if(vis[to])continue;
        dfs(to, u);
        sizes[u] += sizes[to];
    }
}

ll abs(ll x){
    if(x < 0)return -x;
    return x;
}

int main(){
    int top = 1;
    while(~scanf("%d %d", &n, &m) && n){
        ll sum = 0;
        for(int i = 1; i <= n; i++){
            g[i].clear();
        }
        for(int i = 1; i <= n; i++){
            scanf("%lld", &a[i]);
            sum += a[i];
        }
        int u, v;
        while(m--){
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, 0);
        ll ans = 1e18;
        for(int i = 1; i <= n; i++){
            ans = min(ans, abs(sum - 2 * sizes[i]));
        }
        printf("Case %d: ", top++);
        printf("%lld\n", ans);

    }
}