#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;
ll a[N], b[N], sumx[N], sumy[N], n, q;
ll minnx[N], minny[N];

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

struct segment {
    ll sx_maxn, sy_maxn, sx_minn, sy_minn, sumxy, sumyx;
} tree[4 * N];

void build(int l, int r, int node) {
    if (l == r) {
        tree[node].sx_maxn = tree[node].sx_minn = sumx[l];
        tree[node].sy_maxn = tree[node].sy_minn = sumy[l];
        tree[node].sumxy = sumx[l] - minny[l];
        tree[node].sumyx = sumy[l] - minnx[l];
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
    tree[node].sumyx = max(tree[lson].sumyx, tree[rson].sumyx);
    tree[node].sumxy = max(tree[lson].sumxy, tree[rson].sumxy);
    tree[node].sx_maxn = max(tree[lson].sx_maxn, tree[rson].sx_maxn);
    tree[node].sx_minn = min(tree[lson].sx_minn, tree[rson].sx_minn);
    tree[node].sy_maxn = max(tree[lson].sy_maxn, tree[rson].sy_maxn);
    tree[node].sy_minn = min(tree[lson].sy_minn, tree[rson].sy_minn);
}

void update(int v, int pos, int l, int r, int node) {
    if (l == r) {
        
    }
}

int qu_yx(ll k, int l, int r, int node) {
    if (l == r) {
        return l;
    }
    if (tree[lson].sumyx >= k) {
        return qu_yx(k, l, m, lson);
    } else if (tree[rson].sumyx >= k) {
        return qu_yx(k, m + 1, r, rson);
    }
    return -1;
}

int qu_sy_maxn(ll k, int l, int r, int node) {
    if (l == r) {
        return l;
    }
    if (tree[lson].sy_maxn >= k) {
        return qu_sy_maxn(k, l, m, lson);
    } else if (tree[rson].sy_maxn >= k) {
        return qu_sy_maxn(k, m + 1, r, rson);
    } else {
        return -1;
    }
}

int qu_sx_minn(ll k, int l, int r, int node) {
    if (l == r) {
        return l;
    }
    if (tree[lson].sx_minn <= k) {
        return qu_sx_minn(k, l, m, lson);
    } else if (tree[rson].sx_minn <= k) {
        return qu_sx_minn(k, m + 1, r, rson);
    } else {
        return -1;
    }
}

int qu_xy_maxn(ll k, int l, int r, int node) {
    if (l == r) {
        return l;
    }
    if (tree[lson].sumxy >= k) {
        return qu_xy_maxn(k, l, m, lson);
    } else if (tree[rson].sumxy >= k) {
        return qu_xy_maxn(k, m + 1, r, rson);
    } else {
        return -1;
    }
}

int qu_sx_maxn(ll k, int l, int r, int node) {
    if (l == r) {
        return l;
    }
    if (tree[lson].sx_maxn >= k) {
        return qu_sx_maxn(k, l, m, lson);
    } else if (tree[rson].sx_maxn >= k) {
        return qu_sx_maxn(k, m + 1, r, rson);
    } else {
        return -1;
    }
}

int qu_sy_minn(ll k, int l, int r, int node) {
    if (l == r) {
        return l;
    } 
    if (tree[lson].sy_minn <= k) {
        return qu_sy_minn(k, l, m, lson);
    } else if (tree[rson].sy_minn <= k) {
        return qu_sy_minn(k, m + 1, r, rson);
    } else {
        return -1;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin >> n >> q;
    minnx[0] = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sumx[i] = sumx[i - 1] + a[i];
        minnx[i] = min(minnx[i - 1], sumx[i]);
    }
    minny[0] = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        sumy[i] = sumy[i - 1] + b[i];
        minny[i] = min(minny[i - 1], sumy[i]);
    }
    build(1, n, 1);

    while (q--) {
        int x, y; 
        cin >> x >> y;
        if (x > y) {
            int ans = qu_yx(x - y, 1, n, 1);
            int ans1 = qu_sy_maxn(x - y, 1, n, 1);
            int ans2 = qu_sx_minn(y - x, 1, n, 1);
            if (ans == -1) ans = n + 1;
            if (ans1 == -1) ans1 = n + 1;
            if (ans2 == -1) ans2 = n + 1;
            ans = min({ans, ans1, ans2});
            if (ans > n) {
                ans = -1;
            }
            cout << ans << endl;
        } else if (x < y) {
            int ans = qu_xy_maxn(y - x, 1, n, 1);
            int ans1 = qu_sx_maxn(y - x, 1, n, 1);
            int ans2 = qu_sy_minn(x - y, 1, n, 1);
            if (ans == -1) ans = n + 1;
            if (ans1 == -1) ans1 = n + 1;
            if (ans2 == -1) ans2 = n + 1;
            ans = min({ans, ans1, ans2});
            if (ans == n + 1) {
                ans = -1;
            }
            cout << ans << endl;
        } else {
            cout << 0 << endl;
        }
    }
}