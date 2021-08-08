#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

typedef long long ll;
struct hjt{
    int l, r, cnt;
    ll sum, maxn;
}tree[40 * N];


vector<ll> g;
int get_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

ll a[N], n, q, b[N];
int rt[N], top = 1;

#define m (l + r) / 2

void update(int pos, int l, int r, int last, int &now) {
    now = top++;
    tree[now] = tree[last];
    tree[now].cnt++;
    if (l == r) {
        tree[now].sum += g[l - 1];
        tree[now].maxn = tree[now].cnt;
        return;
    }
    if (pos <= m) update(pos, l, m, tree[now].l, tree[now].l);
    else update(pos, m + 1, r, tree[last].r, tree[now].r);
    tree[now].sum = max(tree[tree[now].l].sum, tree[tree[now].r].sum);
    tree[now].maxn = max(tree[tree[now].l].maxn, tree[tree[now].r].maxn);
}

ll mx = 0;
ll ans = 0;

void query(int last, int now, int l, int r, int base) {
    if (l == r) {
        ll su = tree[now].cnt - tree[last].cnt;
        ll va = tree[now].sum - tree[last].sum;
        mx = max(mx, 1ll*su);
        ans = max(ans, va);
        return;
    }
    int sumr = tree[tree[now].r].cnt - tree[tree[last].r].cnt;
    int suml = tree[tree[now].l].cnt - tree[tree[last].l].cnt;
    
    if (sumr > mx && ans < tree[tree[now].r].sum) {
        query(tree[last].r, tree[now].r, m + 1, r, base);
    }
    if (suml > mx && ans < tree[tree[now].l].sum) {
        query(tree[last].l, tree[now].l, l, m, base);
    }

}


int main() {
    scanf("%lld %lld", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        g.push_back(a[i]);
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()));

    for (int i = 1; i <= n; i++) {
        b[i] = get_id(a[i]);
    }
    int maxn = g.size();
    for (int i = 1; i <= n; i++) {
        update(b[i], 1, maxn, rt[i - 1], rt[i]);
    }
    ll last = 0;
    while (q--) {
        ll l, r;
        scanf("%lld %lld", &l, &r);
        l = (l ^ last) % n + 1;
        r = (r ^ last) % n + 1;
        if (l > r) swap(l, r);
        ans = 0; mx = 0;
        query(rt[l - 1], rt[r], 1, maxn, r - l + 1);
        printf("%lld\n", ans);
        last = ans;

    }


}