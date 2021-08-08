#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 7;
typedef long long ll;
struct line {
    int l, r;
}p[N];

int n, q;
vector<int> g;

struct segment {
    int l, r, id;
}tree[14 * N];

struct qu{
    int l, r, id;
}Q[N];

bool cmp(qu x, qu y) {
    if (x.l == y.l) {
        return x.r < y.r;
    }
    return x.l < y.l;
}

#define m (l + r >> 1)
#define ls (node << 1)
#define rs (node << 1 | 1)

int lowbit(int x) {
    return (x & -x);
}

int sum[N];

void add(int v, int x) {
    while (x <= n) {
        sum[x] += v;
        x += lowbit(x);
    }
}

ll ask(int l, int r) {
    ll ans = 0;
    while (r > 0) {
        ans += 1ll * sum[r];
        r -= lowbit(r);
    } 
    l--;
    while (l > 0) {
        ans -= 1ll * sum[l];
        l -= lowbit(l);
    }
    return ans;
}

void build(int l, int r, int node) {
    tree[node].l = g[l - 1];
    tree[node].r = g[r - 1];
    if (l + 1 == r) return;
    build(l, m, ls);
    build(m, r, rs);
}

void push_up(int node) {
    if (tree[node].id > -1) {
        tree[ls].id = tree[node].id;
        tree[rs].id = tree[node].id;
    }
}

void update(int v, int ql, int qr, int node) {

    if (tree[node].l >= ql && tree[node].r <= qr && tree[node].id > -1) {
        //cout << "L = " << tree[node].l << " R = " << tree[node].r << endl;
        if (tree[node].id) {
         //   cout << "id =  " << tree[node].id << " r = " << tree[node].r << " l " << tree[node].l << endl;
            add(-(tree[node].r - tree[node].l), tree[node].id);
        }
        tree[node].id = v;
        return;
    }
    push_up(node);
    if (tree[ls].r >= ql && qr >= tree[ls].l)
        update(v, ql, qr, ls);
    if (tree[rs].l <= qr && ql <= tree[rs].r)
        update(v, ql, qr, rs);
    if (tree[ls].id == tree[rs].id) {
        tree[node].id = tree[ls].id;
    } else {
        tree[node].id = -1;
    }
}
ll Ans[N];

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &p[i].l, &p[i].r);
        p[i].r++;
        g.push_back(p[i].l);
        g.push_back(p[i].r);
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    for (int i = 1; i <= q; i++) {
        scanf("%d %d", &Q[i].l, &Q[i].r);
        Q[i].id = i;
    }
    sort(Q + 1, Q + q + 1, cmp);
    int pos = q;
    build(1, g.size(), 1);
    for (int i = n; i; i--) {
        update(i, p[i].l, p[i].r, 1);
     //   cout << "IDD " << i << " v " << p[i].r - p[i].l << endl;
        add(p[i].r - p[i].l, i);
        while (pos > 0 && Q[pos].l == i) {
            Ans[Q[pos].id] = ask(Q[pos].l, Q[pos].r);
            pos--;
        }
    }
    for (int i = 1; i <= q; i++) {
        printf("%lld\n", Ans[i]);
    }

}