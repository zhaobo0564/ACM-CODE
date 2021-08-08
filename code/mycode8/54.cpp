#include<bits/stdc++.h>
using namespace std;
#define m (l + r) / 2
const int N = 4e5 + 7;
#define int long long
vector<int> gx, gy;

int n, res = 0;

struct point{
    int lx, ly, rx, ry;
}p[N];

bool cmp(point x, point y) {
    return x.lx < y.lx;
}


int ans = 0;

struct node {
    int lx, ly, rx, ry, f;
};

int getx_id(int x) {
    return lower_bound(gx.begin(), gx.end(), x) - gx.begin() + 1;
}

int gety_id(int x) {
    return lower_bound(gy.begin(), gy.end(), x) - gy.begin() + 1;
}

vector<node>v;

bool cmp1(node x, node y) {
    return x.ly < y.ly;
}

int tree[4 * N], vis[N];

#define lson 2 * node
#define rson 2 * node + 1

void update(int v, int pos, int l, int r, int node) {
    if (l == r) {
        tree[node] = v;
        return;
    }
    if (pos <= m) update(v, pos, l, m, lson);
    else update(v, pos, m + 1, r, rson);
    tree[node] = max(tree[lson], tree[rson]);
}

int query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        return tree[node];
    }
    int ans = 0;
    if (ql <= m) ans = max(ans, query(ql, qr, l, m, lson));
    if (qr > m) ans = max(ans, query(ql, qr, m + 1, r, rson));
    return ans;
}

void work(int l, int r) {
    if (l == r) return;
    v.clear();
    for (int i = l; i <= m; i++) {
        v.push_back({p[i].lx, p[i].ly, p[i].rx, p[i].ry, -1});
    }
    for (int i = m + 1; i <= r; i++) {
        v.push_back({p[i].lx, p[i].ly, p[i].rx, p[i].ry, 1});
    }
    sort(v.begin(), v.end(), cmp1);
    for (int i = 0; i < v.size(); i++) {
        if (v[i].f == -1) {
            update(v[i].ry, v[i].rx, 1, n, 1);
        } else {
            int maxn = query(v[i].rx, n, 1, n, 1);
            if (maxn >= v[i].ry && vis[v[i].ry] == 0) {
                res++;
                vis[v[i].ry] = 1;
            }
        }
    }

    for (int i = 0; i < v.size(); i++) {
         if (v[i].f == -1) {
            update(0, v[i].rx, 1, n, 1);
        }
    }
    work(l, m);
    work(m + 1, r);
}

int32_t main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld %lld %lld", &p[i].lx, &p[i].ly, &p[i].rx, &p[i].ry);
        gx.push_back(p[i].lx); gx.push_back(p[i].rx);
        gy.push_back(p[i].ly); gy.push_back(p[i].ry);
    }
    sort(gx.begin(), gx.end());
    sort(gy.begin(), gy.end());
    gx.erase(unique(gx.begin(), gx.end()), gx.end());
    gy.erase(unique(gy.begin(), gy.end()), gy.end());

    for (int i = 1; i <= n; i++) {
        p[i].lx = getx_id(p[i].lx);
        p[i].ly = gety_id(p[i].ly);
        p[i].rx = getx_id(p[i].rx);
        p[i].ry = gety_id(p[i].ry);
        //cout << p[i].lx << " " << p[i].ly << " " << p[i].rx << " " << p[i].ry << endl;
    }


    sort(p + 1, p + n + 1, cmp);
    int nn = n;
    n = gx.size() + 1;

    work(1, nn);

    printf("%lld\n", res);



}