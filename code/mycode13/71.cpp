#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 7;
ll a[N], n;

struct node {
    int a, b, c, pos;
}p[N];

bool cmp(node x, node y) {
    if (x.a == y.a) {
        if (x.b == y.b) {
            return x.c < y.c;
        }
        return x.b < y.b;
    }
    return x.a < y.a;
}
#define m (l + r >> 1)

int ans[N], fn[N], k;

int rt[N], tree[40 * N], ls[40 * N], rs[40 * N];

int lowbit(int x) {return x & -x;};

int o = 1;
void update(int v, int pos, int l, int r, int &node) {
    if (!node) node = o++;
    tree[node] += v;
    if (l == r) {
        return;
    }
    if (pos <= m) update(v, pos, l, m, ls[node]);
    else update(v, pos, m + 1, r, rs[node]);
}

ll query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        return tree[node];
    }
    ll ans = 0;
    if (ql <= m) ans += query(ql, qr, l, m, ls[node]);
    if (qr > m) ans += query(ql, qr, m + 1, r, rs[node]);
    return ans;
}

void add(int v, int pos, int x) {
    while (x <= k) {
        update(v, pos, 1, k, rt[x]);
        x += lowbit(x);
    }
}

ll qu(int pos, int x) {
    ll ans = 0;
    while (x > 0) {
        ans += query(1, pos, 1, k, rt[x]);
        x -= lowbit(x);
    }
    return ans;
}

int main() {
 
    int n; scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &p[i].a, &p[i].b, &p[i].c);
        p[i].pos = i;
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        ans[p[i].pos] += qu(p[i].c, p[i].b);
        add(1, p[i].c, p[i].b);
    }
    for (int i = 1; i < n; i++) {
        if (p[i + 1].a == p[i].a && p[i + 1].b == p[i].b && p[i + 1].c == p[i].c) {
            int pos = i + 1;
            int maxn = ans[p[i].pos];
            while (p[pos].a == p[i].a && p[pos].b == p[i].b && p[pos].c == p[i].c) {
                maxn = max(maxn, ans[p[pos].pos]);
                pos++;
            }
            for (int j = i; j < pos; j++) {
                ans[p[j].pos] = maxn;
            }
            i = pos - 1;

        }
    }
    for (int i = 1; i <= n; i++) {
        fn[ans[i]]++;
    }   
    for (int i = 0; i < n; i++) {
        cout << fn[i] << endl;
    }
}
  


