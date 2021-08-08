#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 7;

struct edge{
    int u, v, w;
};

vector<edge> g;

bool cmp(edge x, edge y) {
    return x.w < y.w;
}

struct node {
    int u, v, w, id;
};

bool cmp1(node x, node y) {
    if (x.w == y.w) {
        return x.id < y.id;
    }
    return x.w < y.w;
}

vector<node> qu;
int ans[N];

int st[N], top = 0;

int fa[N], sz[N];

int find(int x) {
    if (x != fa[x]) {
        return find(fa[x]);
    }
    return x;
}

bool merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return false;
    if (sz[fx] > sz[fy]) swap(fx, fy);
    fa[fx] = fy;
    sz[fy] += sz[fx];
    st[top++] = fx; 
    return true; 
}

void del() {
    while(top) {
        int x = st[top - 1];
        while (fa[x] != x) {
            sz[fa[x]] -= sz[st[top - 1]];
            x = fa[x];
        }
        fa[st[top - 1]] = st[top - 1];
        top--;
    }
}

int main() {
    int n, m;
    for (int i = 1; i < N; i++) {
        fa[i] = i;
        sz[i] = 1;
    }
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g.push_back({u, v, w});
    }
    int q; scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int x; scanf("%d", &x);
        for (int j = 1; j <= x; j++) {
            int y; scanf("%d", &y);
            qu.push_back({g[y - 1].u, g[y - 1].v, g[y - 1].w, i});

        }
        ans[i] = 1;
    }
    sort(qu.begin(), qu.end(), cmp1);
    sort(g.begin(), g.end(), cmp);
    int pos = 0;
    for (int i = 0; i < g.size(); i++) {
        if (pos >= qu.size()) break;
        if (g[i].w < qu[pos].w) {
            merge(g[i].u, g[i].v);
        } else {
            top = 0;
            if (!merge(qu[pos].u, qu[pos].v)) {
                ans[qu[pos].id] = 0;
            }
            pos++;
            while (pos < qu.size() && qu[pos].w == qu[pos - 1].w && qu[pos].id == qu[pos - 1].id) {
                if (!merge(qu[pos].u, qu[pos].v)) {
                    ans[qu[pos].id] = 0;
    
                }
                pos++;
            }
            i--;
            del();
        }
    }
    for (int i = 1; i <= q; i++) {
        if (ans[i]) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    
}