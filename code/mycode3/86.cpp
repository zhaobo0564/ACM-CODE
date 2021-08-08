#include<iostream>
#include<stdio.h>
#include<cmath>
#include<cstring>
using namespace std;
const int N = 1e6 + 7;
typedef long long ll;
#define LLONG_MAX 900000000000000

int head[N], top = 1, father[N];

struct edge{
    int to, nxt;
    ll cost;
}e[2 * N];

int n, mm;
ll dp[N][2];

void add_edge(int u, int v, ll cost){
    e[top].to = v;
    e[top].cost = cost;
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

void dfs1(int u){
    dp[u][1] = dp[father[u]][1];  
    ll w = 0;
    if(father[u]){
        int fa = father[u];
        for(int i = head[fa]; i; i = e[i].nxt){
            int to = e[i].to;
            ll cost = e[i].cost;
            if(to == u){
                w = cost;
                continue;
            }
            if(to == father[fa]) continue;
            dp[u][1] = max(dp[u][1], dp[to][0] + cost);
        }
    }
    dp[u][1] += w;
    for(int i = head[u]; i; i = e[i].nxt){
        int to = e[i].to;
        ll cost = e[i].cost;
        if(to == father[u])continue;
        dfs1(to);
    }
}

ll ans[N], maxn[4 * N], minn[4 * N];
#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

void build(int l, int r, int node){
    if(l == r){
        maxn[node] = minn[node] = ans[l];
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
    maxn[node] = max(maxn[lson], maxn[rson]);
    minn[node] = min(minn[lson], minn[rson]);
}

ll mx = 0, mn =LLONG_MAX;

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
    while(~scanf("%d %d", &n, &mm)){
       top = 1;
        memset(head, 0, sizeof(head));
         memset(dp, 0, sizeof(dp));
         memset(father, 0, sizeof(0));
        for(int i = 2; i <= n; i++){
            int v;
            ll d;
            scanf("%d %lld", &v, &d);
            add_edge(i, v, d);
            add_edge(v, i, d);
        }
        dfs(1, 0);
        dfs1(1);
        for(int i = 1; i <= n; i++){
            ll man = max(dp[i][1], dp[i][0]);
            ans[i] = man;
            //printf("%lld\n", man);
        }
        build(1, n, 1);
        int ans = 0;
        int l = 1, r = 2;
        while(l <= r && r <= n){
            mx = 0;
            mn = LLONG_MAX;
            query(l, r, 1, n, 1);
            if(mx - mn < m){
                ans = max(ans, r - l + 1);
                r++;
            }
            while(mx - mn >= m){
                l++;
                mx = 0;
                mn = LLONG_MAX  ;
                query(l, r, 1, n, 1);
            }

        }
        printf("%d\n", ans);
    

    }
 
}
