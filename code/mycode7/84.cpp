#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 7;

struct node {
    int dep, id;
};

vector<node> ans[N];
vector<int>g[N];

int sz[N], son[N], deep[N], ANS[N], a[N];
int cnt[N][27];
void dfs(int u, int fa) {
    sz[u] = 1;
    deep[u] = deep[fa] + 1;
    for (int to: g[u]) {
        if (to == fa) {
            continue;
        }
        dfs(to, u);
        sz[u] += sz[to];
        if (sz[son[u]] < sz[to]) {
            son[u] = to;
        }
    }
}

void gao(int u) {
    for (int i = 0; i < ans[u].size(); i++) {
        int dep = ans[u][i].dep;
        if (dep <= deep[u]) {
            ANS[ans[u][i].id] = 1;
            continue;
        }
        
        int res = 0;
        for (int j = 0; j <= 25; j++) {
            if (cnt[dep][j] % 2) {
                res++;
            }
        }

        ANS[ans[u][i].id] = (res > 1 ? 0 : 1);

    }

}



void work(int v, int u, int fa, int zson) {
    cnt[deep[u]][a[u]] += v;
    for (int to: g[u]) {
        if (to == fa || to == zson) continue;
        work(v, to, u, zson);
    }
}

void dfs1(int u, int fa, int ok) {
    for (int to: g[u]) {
        if (to != fa && to != son[u]) {
            dfs1(to, u, 1);
        }
    }
    if (son[u]) {
        dfs1(son[u], u, 0);
    }
    work(1, u, fa, son[u]);
    gao(u);
    if (ok) {
        work(-1, u, fa, -1);
    }
    
}

int n, m;
char s[N];

int main() {
    memset(ANS, -1, sizeof(ANS));
    scanf("%d %d", &n, &m);
    for (int i = 2; i <= n; i++) {
        int u; scanf("%d", &u);
        g[u].push_back(i);
        g[i].push_back(u);
    }
    scanf(" %s", s);
    for (int i = 1; i <= n; i++) {
        a[i] = s[i - 1] - 'a';
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        ans[u].push_back({v, i});
    }
    dfs(1, 0);
    dfs1(1, 0, 0);
    for (int i = 1; i <= m; i++) {
        if (ANS[i]) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    

}