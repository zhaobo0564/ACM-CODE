#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<int>G[N];
void init(){
    int top = 0;
    for(int i = 1; i <= 1000; i++){
        for(int j = i ; j < N; j += i){
            if(i * i <= j){
                G[j].push_back(i);
                if(j / i != i){
                    G[j].push_back(j / i);
                }
            }
        }
    }

}
int n, a[N], sz[N], son[N];

vector<int> g[N];

void dfs(int u, int fa) {
    sz[u] = 1;
    for (int to: g[u]) {
        if (to == fa) continue;
        dfs(to, u);
        if (sz[son[u]] < sz[to]) {
            son[u] = to;
        }
        sz[u] += sz[to];
    }
}

int vis[N];
vector<int> cat, all;
int ans[N], maxn, cnt, mx[N];

void cal() {
    for (int i: cat) {
       // cout << "u " << i << endl;
        for (int j: G[i]) {
            if (vis[j]) {
                if (maxn < j) {
                    maxn = j;
                    cnt = vis[j];
                } else if (maxn == j) {
                    cnt += vis[j];
                }
            }
        }
    }
    for (int i: cat) {
        for (int j: G[i]) {
            vis[j]++;
        }
        all.push_back(i);
    }
}

void gao(int u, int fa) {
    cat.push_back(a[u]);
    for (int to: g[u]) {
        if (to == fa) continue;
        gao(to, u);
    }
}


void work(int u, int fa, int zson) {
    cat.clear();
    cat.push_back(a[u]);
   // cout << "u = " << u << endl;
    cal();

    for (int to: g[u]) {
        if (to == zson || to == fa) continue;
        cat.clear();
        gao(to, u);
        cal();
    }

}

void dfs1(int u, int fa, int ok) {
    for (int to: g[u]) {
        if (to == son[u] || to == fa) continue;
        dfs1(to, u, 1);
    }
    if (son[u]) dfs1(son[u], u, 0);
    maxn = 0;
    cnt = 0;
    work(u, fa, son[u]);
    ans[u] = cnt;
    mx[u] = maxn;

    if (ok) {
        for (int i: all) {
            for (int j: G[i]) {
                vis[j]  = 0;
            }
        }
        all.clear();
    }

}

int main() {
    init();
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    dfs(1, 0);
    dfs1(1, 0, 1);
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n",mx[i], ans[i]);
    }

}