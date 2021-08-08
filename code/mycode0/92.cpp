#include<bits/stdc++.h>
using namespace std;
const int N = 100007;

int head[N], top = 1, fa[N][33],deep[N];



struct EDGE{
    int v, next;
} e[2*N];

int n, m, s;

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
    int t; scanf("%d", &t);
    while(t--){
        top = 1;
        memset(deep, 0, sizeof(deep));
        memset(fa, 0, sizeof(fa));
        memset(head, 0, sizeof(head));
        memset(e, 0, sizeof(e));
        int n, q;
        scanf("%d %d", &n, &q);
 //       n = read(), q = read();
        for(int i = 1; i < n; i++){
            int x, y;
            //x = read(), y = read();
            scanf("%d %d", &x, &y);
            add_edge(x, y);
            add_edge(y, x);
        }
        dfs(1, 1);
        while(q--){
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
          //  a = read(), b = read(), c = read();
            int l = lca(b, c);
            int d = deep[b] + deep[c] - 2 * deep[l];
           // cout <<"d= " << d << endl;
            int da = deep[a] - d;
            int lc = lca(a, c);
            if(lc != 1 && da <= deep[c] ){
                printf("YES\n");
            }
            else if(da < deep[c]){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
            // l = lca(a, c);
            // int d1 = deep[a] - deep[l];
          
        }

    }
}

