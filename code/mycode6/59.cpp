#include<bits/stdc++.h>
using namespace std;
const int N = 6e5 + 7;

int n, a[N], k, tree[4 * N];

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

void update(int pos, int v, int l, int r, int node) {
    if (l == r) {
        tree[node] = v;
        return;
    }
    if (pos <= m) update(pos, v, l, m, lson);
    else update(pos, v, m + 1, r, rson);
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



int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int res = query(max(a[i] - k, 0), a[i] + k, 0, N, 1) + 1;
        ans = max(ans, res);
        update(a[i], res, 0, N, 1);
    }
    cout << ans << endl;



    
}