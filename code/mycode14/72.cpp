#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

ll a[N], n;

int tree[40 * N], ls[40 * N], rs[40 * N], top = 1;
#define m (l + r >> 1)

void update(int pos, int l, int r, int &node) {
    if (!node) node = top++;
    tree[node]++;
    if (l == r) return;
    if (pos <= m) update(pos, l, m, ls[node]);
    else update(pos, m + 1, r, rs[node]);
}

int query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) return tree[node];
    int ans = 0;
    if (ql <= m) ans += query(ql, qr, l, m, ls[node]);
    if (qr > m) ans += query(ql, qr, m + 1, r, rs[node]);
    return ans;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int rt = 0;
    ll huaji = 0, jiezi = 0;
    for (int i = 1; i <= n; i++) {
        ll pos = query(0, a[i], 0, 1000000000, rt);
        ll neg = tree[rt] - pos;
        if (i % 2) {
            jiezi += 1 + pos - neg;

        } else {
            huaji += 1 + pos - neg;
        }
        update(a[i], 0, 1000000000, rt);
    }
    if (jiezi > huaji) {
        cout << "Calculus is hebei king!\n";
    } else if (jiezi < huaji) {
        cout << "huaji is hebei king!\n";
    } else {
        cout << "hebei shuang king!\n";
    }
    return 0;
}