#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 7;

struct edge {
    int u, v, w;
}e[N];

struct qu{
    int u, v, w, id;
};

vector<qu> v;

int n, m, q, a[N], ans[N];
int tree[40 * N], ls[40 * N], rs[40 * N];
int rt[N], fa[N];
vector<int> g;

bool cmp(edge x, edge y) {
    return x.w < y.w;
}

bool cmp1(qu x, qu y) {
    return x.v < y.v;
}

int find(int x) {
    if (x != fa[x]) {
        return fa[x] = find(fa[x]);
    }
    return x;
}

int get_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}
int top = 1;
void update(int pos, int l, int r, int &node) {
    if (!node) node = top++;
    tree[node]++;
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(pos, l, mid, ls[node]);
    else update(pos, mid + 1, r, rs[node]);
}

int query(int k, int l, int r, int node) {
    if (l == r)  return l;
    int mid = (l + r) / 2;
    if (tree[ls[node]] >= k) {
        return query(k, l, mid, ls[node]);
    }
    return query(k - tree[ls[node]], mid + 1, r, rs[node]);
}

int merge(int x, int y, int l, int r) {
    if (!x) return y;
    if (!y) return x;
    if (l == r) {
        tree[x] += tree[y];
        return x;
    }
    int mid = (l + r) / 2;
    ls[x] = merge(ls[x], ls[y], l, mid);
    rs[x] = merge(rs[x], rs[y], mid + 1, r);
    tree[x] = tree[ls[x]] + tree[rs[x]];
    return x;
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        g.push_back(a[i]);

        fa[i] = i;
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());

    for (int i = 1; i <= n; i++) {
        a[i] = get_id(a[i]);
        update(a[i], 0, N, rt[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
    }
    int pos = 1;
    sort(e + 1, e + m + 1, cmp);
    for (int i = 1; i <= q; i++) {
        int u, x, k; scanf("%d %d %d", &u, &x, &k);
        v.push_back({u, x, k, i});
    }
    sort(v.begin(), v.end(), cmp1);
    for (int i = 0; i< q; i++) {
        int u = v[i].u, x = v[i].v, k = v[i].w, id = v[i].id;
        while (pos <= m && e[pos].w <= x) {
           // cout << "u =" << e[pos].u << " v = " << e[pos].v << " w = "<< e[pos].w << endl;
            int fx = find(e[pos].u), fy = find(e[pos].v);
            if (fx != fy) {
                rt[fx] = merge(rt[fx], rt[fy], 0, N);
                fa[fy] = fx;
            }
            pos++;
        }
        int fx = find(u);
     //   cout <<"V " << tree[rt[fx]] << endl;
        k = tree[rt[fx]] - k + 1;
        if (k <= 0) {
            ans[id] = 0;
        } else {
            ans[id] = query(k, 0, N, rt[fx]); 
        }
       

    }

    for (int i = 1; i <= q; i++) {
        if (ans[i] == 0) {
            cout << -1 << endl;
        } else {
            cout << g[ans[i] -1]  << endl;
        }
    }
  

   
}