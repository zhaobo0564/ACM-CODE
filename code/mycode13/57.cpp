#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

int n, M, k, q, sz[N][57], fa[N][57];


struct edge {
    int u, v;
}e[2 * N];

vector<int> tree[4 * N];

#define m (l + r >> 1)
#define ls (node << 1)
#define rs (node << 1 | 1)

int vis[N];

struct qu {
    int x, y;
}Q[N];

int find(int x, int id) {
    if (x != fa[x][id]) {
        return find(fa[x][id], id);
    }
    return x;
}

pair<int, int> Stack[N];
int top = 1;

void merge(int x, int y, int id) {
  //  cout << "x = " << x << " y = " << y << " id = " << id << endl;
    int fx = find(x, id);
    int fy = find(y, id);
    int fx1 = find(x + n, id);
    int fy1 = find(y + n, id);
    if (fx == fy) return;
    if (fx == fy1) return;
    if (sz[fx][id] > sz[fy1][id]) swap(fx, fy1);
    
    fa[fx][id] = fy1;
    Stack[top++] = {fx, id};
    sz[fy1][id] += sz[fx][id];
    if (sz[fx1][id] > sz[fy][id]) swap(fx1, fy);
    fa[fx1][id] = fy;
    Stack[top++] = {fx1, id};
    sz[fy][id] += sz[fx1][id];
}

void del(int cnt) {
    while (top > cnt) {
        int x = Stack[top - 1].first;
        int id = Stack[top - 1].second;
        sz[fa[x][id]][id] -= sz[x][id];
        fa[x][id] = x;
        top--;
    }
}

void update(int id, int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        tree[node].push_back(id);
        return;
    }
    if (ql <= m) update(id, ql, qr, l, m, ls);
    if (qr > m) update(id, ql, qr, m + 1, r, rs);
}

int ans[N], last[N];

void query(int l, int r, int node) {
    int cnt = top;
    for (int i = 0; i < tree[node].size(); i++) {
        if (Q[tree[node][i]].y == 0) continue;
        merge(e[Q[tree[node][i]].x].u, e[Q[tree[node][i]].x].v, Q[tree[node][i]].y);
        
    }
    if (l == r) {
        if (find(e[Q[l].x].u, Q[l].y) == find(e[Q[l].x].v, Q[l].y)) {
            puts("NO");
            Q[l].y = last[Q[l].x];
        } else {
            puts("YES");
            last[Q[l].x] = Q[l].y;
        }
        del(cnt);
        return;
    }
    query(l, m, ls);
    query(m + 1, r, rs);
    del(cnt);
}


int w[N];

int main() {

    scanf("%d %d %d %d", &n, &M, &k, &q);
    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 1; j <= k; j++) {
            fa[i][j] = i;
            sz[i][j] = 1; 
        }
        
        
    }
    for (int i = 1; i <= M; i++) {
        int u, v; scanf("%d %d", &e[i].u, &e[i].v);
        vis[i] = q + 1;
    }

    for (int i = 1; i <= q; i++) {
        int x, y; scanf("%d %d", &x, &y);
        Q[i] = {x, y};
    }

    for (int i = q; i; i--) {
        if (i + 1 <= vis[Q[i].x] - 1) {
            update(i, i + 1, vis[Q[i].x] - 1, 1, q, 1);
        }
        vis[Q[i].x] = i;
    }
    query(1, q, 1);

}


