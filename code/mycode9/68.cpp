#include<bits/stdc++.h>
using namespace std;
#define N 200000 + 5
#define int long long
#define rep(i, l, r) for(int i = l; i <= r; ++i)
#define Next1(i, u) for(int i = h1[u]; i; i = e1[i].next)
#define Next2(i, u) for(int i = h2[u]; i; i = e2[i].next)
struct edge{
    int v, next, w;
}e1[N << 1], e2[N << 1];
bool book[N];
int n, m, u, v, w, S, E, D, ans, now, tot1, tot2;
int s[N], d[N], h1[N], h2[N], fa[N], Fa[N], son[N], top[N], dep1[N], dep2[N];
int read(){
    char c; int x = 0, f = 1;
    c = getchar();
    while(c > '9' || c < '0'){ if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
void add1(int u, int v, int w){
    e1[++tot1].v = v, e1[tot1].w = w, e1[tot1].next = h1[u], h1[u] = tot1;
}
void add2(int u, int v, int w){
    e2[++tot2].v = v, e2[tot2].w = w, e2[tot2].next = h2[u], h2[u] = tot2;
}
void dfs1(int u, int fa){
    Fa[u] = fa;
    Next2(i, u){
        int v = e2[i].v; if(v == fa) continue;
        dep2[v] = dep2[u] + e2[i].w, dfs1(v, u); 
    }
}
void dfs2(int u, int Fa){
    fa[u] = Fa, s[u] = 1, d[u] = d[Fa] + 1;
    int Max = -1;
    Next1(i, u){
        int v = e1[i].v; if(v == Fa) continue;
        dep1[v] = dep1[u] + e1[i].w, dfs2(v, u);
        s[u] += s[v];
        if(s[v] > Max) Max = s[v], son[u] = v;
    }
}
void dfs3(int u, int topf){
    top[u] = topf;
    if(!son[u]) return;
    dfs3(son[u], topf);
    Next1(i, u){
        int v = e1[i].v; if(v == son[u] || v == fa[u]) continue;
        dfs3(v, v);
    }
}
void dfs4(int u, int f, int d){
    //printf("now here is %lld %lld\n", u, d);
   // book[u] = true;
    if(d > ans) ans = d, now = u;
    Next1(i, u){
        int v = e1[i].v; if(v == f) continue;
        dfs4(v, u,  d + e1[i].w);
    }
}
int LCA(int x, int y){
    while(top[x] != top[y]){
        if(d[top[x]] < d[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    return d[x] < d[y] ? x : y;
}
int dis(int x, int y){ return dep1[x] + dep1[y] - 2 * dep1[LCA(x, y)];}
vector<int> cat;

void dfs5(int u, int fa){
    cat.push_back(u);
   // dep1[u + n] += w;
    // int D1 = dis(u + n, S), D2 = dis(u + n, E); D = max(D1, D2);
    // if(D1 > D2) now = S;
    // else now = E;
    // if(D > ans) ans = D, S = now, E = u + n;
    Next2(i, u){
        int v = e2[i].v; if(v == fa) continue;
        dfs5(v, u);
    }
}
signed main(){
    n = read(), m = read();
    rep(i, 1, n - 1) u = read(), v = read(), w = read(), add1(u, v, w), add1(v, u, w);
    rep(i, 1, n - 1) u = read(), v = read(), w = read(), add2(u, v, w), add2(v, u, w);
    dfs1(1, 0);
    rep(i, 1, n) add1(i, i + n, dep2[i]), add1(i + n, i, dep2[i]);
    dfs2(1, 0);
    dfs3(1, 1);
    dfs4(1, 0, 0), S = now;
    ans = 0; //memset(book, 0, sizeof(book));
    dfs4(S, 0, 0), E = now;
    printf("%lld\n", ans);
    rep(j, 1, m){
        u = read(), w = read();
        cat.clear();
        dfs5(u, Fa[u]);
        
        for (int i: cat) {
            int u = i;
            dep1[u] += w;
            // int cn = dis(i + n, S);
            // int cnt = dis(i + n, E);
            // if (cn > cnt) {
            //     if (ans < cn) {
            //         ans = cn;
            //         E = i + n;
            //     }
            // } else {
            //     if (cnt > ans) {
            //         ans = cnt;
            //         S = i + n;
            //     }
            // }
             int D1 = dis(u + n, S), D2 = dis(u + n, E); D = max(D1, D2);
            if(D1 > D2) now = S;
            else now = E;
            if(D > ans) ans = D, S = now, E = u + n;
        }
        printf("%lld\n", ans);
    }
    return 0;
}