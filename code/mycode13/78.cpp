#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e4 + 10;
ll a, b, c;
struct kd_tree{
    ll maxn[2], minn[2], l, r;
    ll sum = 0;
}tree[N];

struct node {
    ll x, y, z;
}p[N];

bool cmp(node x, node y) {
    return x.x < y.x;
}

bool cmp1(node x, node y) {
    return x.y < y.y;
}

#define m (l + r >> 1)

void push_up(int node) {
    int ls = tree[node].l, rs = tree[node].r;
    for (int i = 0; i < 2; i++) {
        if (ls) tree[node].maxn[i] = max(tree[node].maxn[i], tree[ls].maxn[i]);
        if (ls) tree[node].minn[i] = min(tree[node].minn[i], tree[ls].minn[i]);
        if (rs) tree[node].maxn[i] = max(tree[node].maxn[i], tree[rs].maxn[i]);
        if (rs) tree[node].minn[i] = min(tree[node].minn[i], tree[rs].minn[i]);
    }
    tree[node].sum += tree[ls].sum + tree[rs].sum;
}

int build(int l, int r, int now) {
    if (now) {
        nth_element(p + l, p + m, p + r + 1, cmp);
    } else {
        nth_element(p + l, p + m, p + r + 1, cmp1);
    }
    tree[m].sum = p[m].z;
    tree[m].minn[0] = tree[m].maxn[0] = p[m].x;
    tree[m].minn[1] = tree[m].maxn[1] = p[m].y;  
    if (l < m) tree[m].l = build(l, m - 1, now ^ 1);
    if (r > m) tree[m].r =  build(m + 1, r, now ^ 1);
    push_up(m);
    return m;
}

int work(ll x, ll y) {
    return a * x + b * y < c;
}

ll query(int l, int r, int node) {
    int ans = 0;
    ans += work(tree[node].minn[0], tree[node].minn[1]);
    ans += work(tree[node].minn[0], tree[node].maxn[1]);
    ans += work(tree[node].maxn[0], tree[node].minn[1]);
    ans += work(tree[node].maxn[0], tree[node].maxn[1]);
    if (ans == 4) {
        return tree[node].sum;
    }
    if (ans == 0) return 0;
    ll res = 0;
    if (work(p[m].x, p[m].y)) {
        res += p[m].z;
    }
    if (tree[node].l) res += query(l, m - 1, tree[node].l);
    if (tree[node].r) res += query(m + 1, r, tree[node].r);
    return res;
}


int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld %lld", &p[i].x, &p[i].y, &p[i].z);
    } 
    int rt = build(1, n, 1);
    while (q--) {
        scanf("%lld %lld %lld", &a, &b, &c);
        printf("%lld\n", query(1, n, rt));
    }
    
}