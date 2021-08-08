#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int head[N], top = 1, fa[N][33],deep[N];

struct EDGE{
    int v, next;
} e[2*N];

int n, m, s, a[N];

void add_edge(int u,int v){
    e[top].v = v;
    e[top].next = head[u];
    head[u] = top++;
}

void dfs(int u,int f){
    fa[u][0] = f;
    for (int i = 1; i < 32;i++){
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    deep[u] = deep[f] + 1;
    for (int i = head[u]; i; i = e[i].next){
        int to = e[i].v;
        if(to!=f){
            dfs(to, u);
        }
    }
}

int lca(int x,int y){
    if(deep[x]<deep[y]){
        swap(x, y);
    }
    int d = deep[x] - deep[y];
    for (int i = 0; i < 32;i++){
        if(d&1){
            x = fa[x][i];
        }
        d = d / 2;
    }
    if(x==y){
        return x;
    }
    for (int i = 31; i >= 0;i--){
        int tox = fa[x][i];
        int toy = fa[y][i];
        if(tox==0){
            continue;
        }
        if(tox!=toy){
            x = tox;
            y = toy;
        }
    }
    return fa[x][0];
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <n; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(1, 0);
    while(m--){
        int k; scanf("%d", &k);
        int maxn = 0, pos;
        for(int i = 1; i <= k; i++){
            scanf("%d", &a[i]);
            if(deep[a[i]] > maxn){
                maxn = deep[a[i]];
                pos = a[i];
            }
        }
        int f = 0;
        for(int i = 1; i <= k; i++){
            if(a[i] == pos) continue;
            int ans = abs(deep[a[i]] - deep[lca(pos, a[i])]);
            if(ans > 1){
                f = 1;
                break;
            }
        }
        if(f){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }
}