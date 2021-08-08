#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
typedef long long ll;
struct hjt {
    int l, r;
    ll sum, lmaxn, maxn, rmaxn;    


}tree[40 * N];

int top = 1;

#define m (l + r) / 2

void push_down(int node) {
    
    int lson = tree[node].l, rson = tree[node].r;
    tree[node].lmaxn = max(tree[lson].lmaxn, tree[lson].sum + tree[rson].lmaxn);
    tree[node].rmaxn = max(tree[rson].rmaxn, tree[rson].sum + tree[lson].rmaxn);
    tree[node].maxn = max(tree[node].lmaxn, tree[node].rmaxn);
    tree[node].maxn = max(tree[lson].maxn, max(tree[node].maxn, tree[rson].maxn));
    tree[node].maxn = max(tree[node].maxn, tree[lson].rmaxn + tree[rson].lmaxn);
    tree[node].sum = tree[lson].sum + tree[rson].sum;
        
}

hjt merg(hjt x, hjt y) {
    if (x.l == -1) return y;
    hjt ans;
    ans.l = 0;
    ans.lmaxn = max(x.lmaxn, x.sum + y.lmaxn);
    ans.rmaxn = max(y.rmaxn, y.sum + x.rmaxn);
    ans.maxn = max(ans.lmaxn, ans.rmaxn);
    ans.maxn = max(ans.maxn, max(x.maxn, y.maxn));
    ans.maxn = max(ans.maxn, x.rmaxn + y.lmaxn);
    cout <<"L " << x.maxn << " r = " << y.maxn << endl;
    ans.sum = x.sum + y.sum;
    return ans;
}

void update(int pos, ll v, int l, int r, int &last, int & now) {
    now = top++;
    tree[now] = tree[last];
    if (l == r) {
        tree[now].lmaxn = v;
        tree[now].rmaxn = v;
        tree[now].maxn = v;
        tree[now].sum = v;
        return;
    }
    if (pos <= m) {
        update(pos, v, l, m, tree[last].l, tree[now].l);
    } else {
        update(pos, v, m + 1, r, tree[last].r, tree[now].r);
    }
    push_down(now);
}

hjt query (int ql, int qr, int l, int r, int now) {
    if (ql <= l && qr >= r) {
cout << "l = " << l << " r " << r << endl;
cout <<"max " << tree[now].maxn << endl;
        return tree[now];
    }
    hjt ans;
    ans.l = -1;
    
    if (ql <= m) ans = merg(ans, query(ql, qr, l, m, tree[now].l));
    if (qr > m) ans = merg(ans, query(ql, qr, m + 1, r, tree[now].r));
    return ans;

}
ll a[N];
map<int, int> vis;
int rt[N];

int main() {
    int n, q;
    tree[0].lmaxn = -1e16;
    tree[0].maxn = -1e16;
    tree[0].rmaxn = -1e16;
    tree[0].sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[a[i]] == 0) {
            update(i, a[i], 1, n, rt[i - 1], rt[i]);
        } else {
            int temp;
            update(vis[a[i]], 0, 1, n, rt[i - 1], temp);
            update(i, a[i], 1, n, temp, rt[i]);
        }
        vis[a[i]] = i;
    }
    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        if (l > r) swap(l, r);
        printf("%lld\n",  max(1ll*0, query(l, r, 1, n, rt[r]).maxn));
    }

}