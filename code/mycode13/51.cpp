#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 7;

int a[N], n, tree[4 * N];

#define m (l + r >> 1)
#define lson (node << 1)
#define rson (node << 1 | 1)

void update(int v, int pos, int l, int r, int node) {
    tree[node] += v;
    if (l == r) return;
    if (pos <= m) update(v, pos, l, m, lson);
    else update(v, pos, m + 1, r, rson); 
}

int query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        return tree[node];
    }
    int ans = 0;
    if (ql <= m) ans += query(ql, qr, l, m, lson);
    if (qr > m) ans += query(ql, qr, m + 1, r, rson);
    return ans;
}

int t[4 * N];

void up(int v, int pos, int l, int r, int node) {
    t[node] += v;
    if (l == r) {
        return;
    }
    if (pos <= m) up(v, pos, l, m, lson);
    else up(v, pos, m + 1, r, rson);
}

int qu(int k, int l, int r, int node) {
    if (l == r) return l;
    if (t[lson] >= k) {
        return qu(k, l, m, lson);
    } else {
        return qu(k - t[lson], m + 1, r, rson);
    }
}
vector<int> v;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        update(1, a[i], 1, n, 1);
        up(1, i, 1, n, 1);
    }
    for (int i = 1; i <= n; i++) {
        update(-1, a[i], 1, n, 1);
        int ans = query(a[i], n, 1, n, 1);
        int cnt = qu(ans + 1, 1, n, 1);
        v.push_back(cnt);
        up(-1, cnt, 1, n, 1);
    }
    for (int i: v) {
        cout << i << " ";
    }
    cout << endl;

    

}