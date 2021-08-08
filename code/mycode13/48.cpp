#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int n, a[N], q;

#define m (l + r >> 1)

struct node {
    int u, v;
}Q[N];

int fa[N], sz[N];

int find(int x) {
    if (x != fa[x]) {
        return find(fa[x]);
    }
    return x;
}

int Stack[N], top = 0;

void merge(int x, int y) {
    //cout << "x = " << x << " y = " << y << endl;
    int fx = find(x);
    int fy = find(y);
    if (sz[fx] > sz[fy]) {
        swap(fx, fy);
    }
    fa[fx] = fy;
    sz[fy] += sz[fx];
    Stack[top++] = fx;
}

void del(int x) {
    while (top > x) {
        int y = Stack[top - 1];
        sz[fa[y]] -= sz[y];
        fa[y] = y;
        top--;
    }
}

int o = 1;
vector<int> tree[40 * N];
int ls[40 * N], rs[40 * N], sum[40 * N];




void update(int v, int ql, int qr, int l, int r, int &node) {
    if (!node) node = o++;
    if (ql <= l && qr >= r) {
        tree[node].push_back(v);
        sum[node] = tree[node].size();
        return;
    }
    if (ql <= m) update(v, ql, qr, l, m, ls[node]);
    if (qr > m) update(v, ql, qr, m + 1, r, rs[node]);
    sum[node] = sum[ls[node]] + sum[rs[node]];
}
long long ans = 0;
void query(int l, int r, int node) {
    int cnt = top;
    for (int i = 0; i < tree[node].size(); i++) {
        merge(Q[tree[node][i]].u, Q[tree[node][i]].v);
    }
    if (find(1) == find(n)) {
        ans += 1ll*(r - l + 1);
        del(cnt);
        return;
    } else if (sum[node] == 0) {
        del(cnt);
        return;
    } else if (ls[node] == 0 && rs[node] == 0) {
        del(cnt);
        return;
    }
    query(l, m, ls[node]);
    query(m + 1, r, rs[node]);
    del(cnt);
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < N; i++) {
        fa[i] = i;
        sz[i] = 1;
    }
    int rt = 0;

    for (int i = 1; i <= q; i++) {
        int u, v, l, r;
        scanf("%d %d %d %d", &u, &v, &l, &r);
        update(i, l, r, 1, 1000000000, rt);
        Q[i] = {u, v};
    }
    query(1, 1000000000, rt);
    printf("%lld\n", ans);
}

