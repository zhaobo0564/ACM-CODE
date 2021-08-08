#include<bits/stdc++.h>
using namespace std;

const int N = 10007;
typedef long long ll;

int head[N], n, top = 1, father[N];

struct edge{
    int to, nxt;
    ll cost;
}e[2 * N];

ll dp[N][2];

void add_edge(int u, int v, ll w){
    e[top].to = v;
    e[top].cost = w;
    e[top].nxt = head[u];
    head[u] = top++;
}

void dfs(int u, int fa){
    father[u] = fa;
    for(int i = head[u]; i; i = e[i].nxt){
        int to = e[i].to;
        ll cost = e[i].cost;
        if(to == fa)continue;
        dfs(to, u);
        dp[u][0] = max(dp[u][0], dp[to][0] + cost);
    }
}

void dfs1(int u, int fa){
    ll w = 0;
    dp[u][1] = dp[fa][1];
    if(fa){
        for(int i = head[fa]; i; i = e[i].nxt){
            int to = e[i].to;
            ll cost = e[i].cost;
            if(to == father[fa])continue;
            if(to == u)w = cost;
            else dp[u][1] = max(dp[u][1], dp[to][0] + cost);
        }
    }
    dp[u][1] += w;
    for(int i = head[u]; i; i = e[i].nxt){
        int to = e[i].to;
        if(to == fa)continue;
        dfs1(to, u);
    }
}

int main(){
    while(~scanf("%d", &n)){
        top = 1;
        memset(head, 0, sizeof(head));
        memset(dp, 0, sizeof(dp));
        for(int i = 2; i <= n; i++){
            int  v;
            ll w;
            scanf("%d %lld", &v, &w);
            add_edge(i, v, w);
            add_edge(v, i, w);
        }
        dfs(1, 0);
        dfs1(1, 0);
        for(int i = 1; i <= n; i++){
            printf("%lld\n", max(dp[i][0], dp[i][1]));
        }
    }
}

