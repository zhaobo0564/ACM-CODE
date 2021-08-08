#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e7 + 1;
struct segment {
    int maxn, minn;
}tree[4 * N];

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

void update(int v, int pos, int l, int r, int node) {
    if (l == r) {
        tree[node].maxn = tree[node].minn = v;
        return;
    }
    if (pos <= m) update(v, pos, l, m, lson);
    else update(v, pos, m + 1, r, rson);
    tree[node].maxn = max(tree[lson].maxn, tree[rson].maxn);
    tree[node].minn = min(tree[lson].minn, tree[rson].minn);
}

int maxn = INT_MIN, minn = INT_MAX;

void query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        maxn = max(maxn, tree[node].maxn);
        minn = min (minn, tree[node].minn);
        return;
    }
    if (ql <= m) query(ql,qr, l, m, lson);
    if (qr > m)  query(ql, qr, m + 1,r, rson);
}


int n, q, k;
ll a[N], b, c;
const ll mod = 1e9;
int main() {
    scanf("%d %d", &n, &k);
    scanf("%lld %lld %lld", &a[0], &b, &c);
    for(int i = 1; i <= n; i++) {
        a[i] = (a[i - 1] * b + c) % mod;
        update(a[i], i, 1, n, 1);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        
    }
   
    
}