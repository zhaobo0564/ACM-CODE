#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int head[N], a[N], dp[N][4], top = 1;
int n, t;

struct edge{
    int to, cost, nxt;
}e[2 * N];

void add_edge(int u, int v, int w){
    e[top].to = v;
    e[top].cost = w;
    e[top].nxt = head[u];
    head[u] = top++;
}

void dfs(int u, int fa){
    dp[u][0] = a[u];
    dp[u][1] = a[u];
    for(int i = head[u]; i; i = e[i].nxt){
        int to = e[i].to;
        int cost = e[i].cost;
        if(to == fa)continue;
        dfs(to, u);
        dp[u][0] = max(dp[u][0], dp[to][0] + cost + a[u]);
        dp[u][0] = max(dp[u][0], dp[u][1] + dp[to][0] + 2 * cost);
        dp[u][1] = max(dp[u][1], dp[to][1] + 2 * cost + a[u]);
    }
}

void dfs1(int u, int fa){
    
}


int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i<= n; i++){
            scanf("%d", &a[i]);
        }
        for(int i = 1; i < n; i++){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            add_edge(u, v, -w);
            add_edge(v, u, -w);
        }

    }
}