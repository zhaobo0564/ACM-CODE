#include<iostream>
#include<vector>
#include<stdio.h>
#include<cstring>
using namespace std;
const int N = 1e6 + 7;
typedef long long ll;
ll dp[N][2], ans[N];
int father[N], head[N], top;
struct edge{
    int to, nxt;
    ll cost;
}e[2 * N];

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
        ll w = e[i].cost;
        if(to == fa)continue;
        dfs(to, u);
        dp[u][0] = max(dp[u][0], dp[to][0] + w);
    }
}

void dfs1(int u){
    dp[u][1] = dp[father[u]][1];
    if(father[u]){
        ll w = 0;
        for(int i = head[father[u]]; i; i = e[i].nxt){
            int to = e[i].to;
            ll cost = e[i].cost;
            if(to == father[father[u]]){
                continue;
            }
            if(to == u){
                w = cost;
                continue;
            }
            dp[u][1] = max(dp[u][1], dp[to][0] + cost);
        }
        dp[u][1] += w;
    }
    for(int i = head[u]; i ; i = e[i].nxt){
        int to = e[i].to;
        if(to == father[u]){
            continue;
        }
        dfs1(to);
    }
}

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

ll maxn[4 * N], minn[4 * N];

void build(int l , int r, int node){
    if(l == r){
        maxn[node] = minn[node] = ans[l];
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
    maxn[node] = max(maxn[lson], maxn[rson]);
    minn[node] = min(minn[lson], minn[rson]);
}

ll mx = 0, mn = 1e15;

void query(int ql, int qr, int l, int r, int node){
    if(ql <= l && qr >= r){
        mx = max(mx, maxn[node]);
        mn = min(mn, minn[node]);
        return;
    }
    if(ql <= m)query(ql, qr, l, m, lson);
    if(qr > m)query(ql, qr, m + 1, r, rson);
}

int main(){
    int n, mm;
    while(~scanf("%d %d", &n, &mm)){
        memset(dp, 0, sizeof(dp));
        memset(head, 0, sizeof(head));
        top = 1;
    
        for(int i = 2; i <= n; i++){
            int u;
            ll w;
            scanf("%d %lld", &u, &w);
            add_edge(i, u, w);
            add_edge(u, i, w);

        }
        dfs(1, 0);
        dfs1(1);
        for(int i = 1; i <= n; i++){
            ans[i] = max(dp[i][0], dp[i][1]);
          //  printf("%lld\n", ans[i]);
        }
        int l = 1, r = 2;
        int res = 0;
        build(1, n, 1);
        while(l <= r && r <= n){
            mx = 0;
            mn = 1e15;
            query(l, r, 1, n, 1);
            if(mx - mn < mm){
                res = max(res, r - l + 1);
                r++;
            }else{
                l++;
            }
        }

        printf("%d\n", res);

    }
}