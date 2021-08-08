#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

struct segment {
    ll sum, maxn;
}tree[4 * N];

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

ll a[N], ans[N];
int flag[4 * N], fmaxn[4 * N];

void push_down(int node) {
     if (fmaxn[node]) {
        tree[lson].maxn = max(tree[lson].maxn, fmaxn[node] + tree[lson].sum);
        tree[rson].maxn = max(tree[rson].maxn, tree[rson].sum + fmaxn[node]);
        fmaxn[lson] = max(fmaxn[lson], fmaxn[node] + flag[lson]);
        fmaxn[rson] = max(fmaxn[rson], fmaxn[node] + flag[rson]);
        fmaxn[node] = 0;
    }
    if (flag[node]) {
        tree[lson].sum += flag[node];
        tree[rson].sum += flag[node];
        flag[lson] += flag[node];
        flag[rson] += flag[node];
        flag[node] = 0;
    }
   
}

void update(ll v, int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {

        tree[node].sum += v;
        tree[node].maxn = max(tree[node].maxn, tree[node].sum);
       // cout << "sum = " << tree[node].sum << " maxn = " << tree[node].maxn << endl;
        flag[node] += v;
      //  cout << "node " << flag[node] << endl;
        fmaxn[node] = max(fmaxn[node], flag[node]);
         
        return;
    }
    push_down(node);
    if (ql <= m) update(v, ql, qr, l, m, lson);
    if (qr > m) update(v, ql, qr, m + 1, r, rson);
    tree[node].sum = max(tree[lson].sum, tree[rson].sum);
    tree[node].maxn = max(tree[lson].maxn, tree[rson].maxn);
}

ll query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
     //   cout << "maxn " << tree[node].maxn << endl;
        return tree[node].maxn;
    }
    ll ans = INT_MIN;
    push_down(node);
    if (ql <= m) ans = max(ans, query(ql, qr, l, m, lson));
    if (qr > m) ans = max(ans, query(ql, qr, m + 1, r, rson));
    return ans;
}

map<int , int>vis;

int pos[N];

struct qu{
    int l, r, id;
}p[N];

int main() {
    int n, q;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        pos[i] = vis[a[i]];
        vis[a[i]] = i;
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int l, r; scanf("%d %d", &p[i].l, &p[i].r);
        p[i].id = i;
    }

    sort(p + 1, p + 1 + q, [](qu x, qu y) {
        return x.r < y.r;
    });
    int l = 1;
    for (int i = 1; i <= n; i++) {
       // cout << "LL =  " << pos[i] + 1 << " r = " << i << endl;
        update(a[i], pos[i] + 1, i, 1, n, 1);
        while(p[l].r == i) {
         //   cout << "l == " << p[l].l << " r = " << p[l].r << endl; 
            ans[p[l].id] = query(p[l].l, p[l].r, 1, n, 1);
            l++;
        }
    }
    for (int i = 1; i <= q; i++) {
        printf("%lld\n", ans[i]);
    }

    



}