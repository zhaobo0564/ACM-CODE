#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int t, a[N], head[N], top = 1, n;
int dp[N][3], id[N], ans[N];

struct edge{
    int to, nxt, cost;
}e[2 * N];

void add_edge(int u, int v, int w){
    e[top].to = v;
    e[top].cost = w;
    e[top].nxt = head[u];
    head[u] = top++;
}

void dfs(int u, int fa){
    dp[u][0] = dp[u][1] = dp[u][2] = a[u];
    for(int i = head[u]; i; i = e[i].nxt){
        int to = e[i].to;
        int cost = e[i].cost;
        if(to == fa)continue;
        dfs(to, u);
        if(2 * cost + dp[to][2] > 0){
            dp[u][2] += 2 * cost + dp[to][2];
        }
    }
    id[u] = u;
    for(int i = head[u]; i; i = e[i].nxt){
        int to = e[i].to;
        int cost = e[i].cost;
        if(to == fa)continue;
        int now = dp[u][2] - max(0, dp[to][2] + 2 * cost) + max(0, dp[to][0] + cost);
        if(dp[u][0] < now){
            dp[u][1] = dp[u][0];
            dp[u][0] = now;
            id[u] = to;
        }else if(dp[u][1] < now){
            dp[u][1] = now;
        }
    }
}

void dfs1(int u, int fa, int up1, int up2){
    ans[u] = max(dp[u][0] + up2, dp[u][2] + up1);

    for(int i = head[u]; i; i = e[i].nxt){
        int to = e[i].to;
        int cost = e[i].cost;
        int d1 = 0, d2 = 0;
        if(to == fa)continue;
        if(to == id[u])
            d1 = dp[u][1] - max(0, dp[to][2] + 2 * cost);
        else 
            d1 = dp[u][0] - max(0, dp[to][2] + 2 * cost);
        
        d2 = dp[u][2] - max(0, dp[to][2] + 2 * cost);
        d1 = max(d1, up2 + d1);
        d1 = max(d1, up1 + d2);
        d1 = d1 + cost;
        d2 = max(d2, up2 + d2);
        d2 =  d2 + 2 * cost; 
        dfs1(to, u, max(0, d1), max(0, d2)); 
    }
}

int main(){
    scanf("%d", &t);
    int ca = 1;
    while(t--){
        top = 1;
        scanf("%d", &n);
        for(int i = 0; i <= n + 1; i++){
            head[i] = 0;
            dp[i][0] = dp[i][1] = dp[i][2] = 0;
        }
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        for(int i = 1; i < n; i++){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            add_edge(u, v, -w);
            add_edge(v, u, -w);
        }
        dfs(1, 0);
        dfs1(1, 0, 0, 0);
        printf("Case #%d:\n", ca++);
        for(int i = 1; i <= n; i++){
            printf("%d\n", ans[i]);
        }
        
    }
}