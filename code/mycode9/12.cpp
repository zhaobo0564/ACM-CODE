#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

typedef long long ll;

ll tree[4 * N], n, a[N], maxn[N];
#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

void build(int l, int r, int node) {
    if (l == r) {
        tree[node] = a[l];
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
    tree[node] = min(tree[lson], tree[rson]);
}

int query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        return tree[node];
    }
    int ans = INT_MAX;
    if (ql <= m) ans = min(ans, query(ql, qr, l, m, lson));
    if (qr > m) ans = min(ans, query(ql, qr, m + 1, r, rson));
    return ans;
}

int queryl(int k, int l, int r, int node) {
    if (tree[node] < k && l == r) {
        return l;
    } else if (l == r) {
        return n + 1;
    }
    if (tree[lson] < k) {
        return queryl(k, l, m, lson);
    } else if (tree[rson] < k) {
        return queryl(k, m + 1, r, rson);
    }
    return n + 1;
}

int workl(int k, int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        return queryl(k, l, r, node);
    }
    int ans = 1e7;
    if (ql <= m) ans = min(ans, workl(k, ql, qr, l, m, lson));
    if (qr > m) ans = min(ans, workl(k, ql, qr, m + 1, r, rson));
    return ans;
}




void solve() {
    build(1, n, 1);
    ll mx = 0;
    for (int i = 1; i < n; i++) {
       mx = max(mx, a[i]);
       int l = i + 2, r = n, ans = 0;
       while (l <= r) {
           int mid = (l + r) / 2;
           if (maxn[mid] >= mx) {
               l = mid + 1;
               ans = mid;
           } else {
               r = mid - 1;
           }
       }
       if (maxn[ans] == mx && i + 1 <= ans - 1) {
           int pos = workl(mx, i + 1, ans - 1, 1, n, 1);
           if (pos == n + 1) pos = ans;
           if (pos <= ans&& i + 1 <= pos - 1) {
               int minn = query(i + 1, pos - 1, 1, n, 1);
               if (minn == mx && maxn[pos] == mx) {
                   cout << "YES\n";
                   cout << i << " " << pos - 1 - i <<" "<< n - (pos - 1) << endl;                 
                   return;
               }
           }
       }

    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            maxn[i] = 0;
        }
        maxn[n + 1] = 0;
        
        for (int i = n; i; i--) {
            maxn[i] = max(maxn[i + 1], a[i]);
        }
        solve();
    }
}