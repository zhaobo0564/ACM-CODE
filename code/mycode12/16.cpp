#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int a[N], b[N], n, q;

#define m (l + r) / 2

int tree[40 * N], ls[40 * N], rs[40 * N];

int top = 1;

void update(int v, int pos, int l, int r, int &node) {
    if (!node) node = top++;
    tree[node] += v;
    if (l == r) {
        return;
    }
    if (pos <= m) update(v, pos, l, m, ls[node]);
    if (pos > m) update(v, pos, m + 1, r, rs[node]);
} 

int query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        return tree[node];
    }
    int ans = 0;
    if (ql <= m) ans += query(ql, qr, l, m, ls[node]);
    if (qr > m) ans += query(ql, qr, m + 1, r, rs[node]);
    return ans;
}

map<int, int> vis;
int sum[N];

vector<int>A, B;

int solve() {
    int l = 1, r = 1e9, rt = 0, top = 1;
    int ans = 0;
    vis.clear();
    for (int i: A) {
        vis[i] = 1;
    }
    for (int i = 0; i < B.size(); i++) {
        update(1, B[i], l, r, rt);
        if (vis[B[i]]) {
            sum[i] = 1;
        }
    }
    for (int i = B.size() - 1; i >= 0; i--) {
        sum[i] += sum[i + 1];
    }
    for (int i = 0; i < B.size(); i++) {
        int p = upper_bound(A.begin(), A.end(), B[i]) - A.begin();
        ans = max(ans, query(B[i] - p + 1, B[i], l, r, rt) + sum[i + 1]);
    }
    for (int i: B) {
        update(-1, i, l, r, rt);
    }

    return ans;
    
}


int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        A.clear(), B.clear();
        cin >> n >> q;
        for (int i = 0; i <= q + 1; i++) {
            sum[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] > 0) {
                A.push_back(a[i]);
            }
        }
        for (int i = 1; i <= q; i++) {
            cin >> b[i];
            if (b[i] > 0) {
                B.push_back(b[i]);
            }
            
        }
        int ans = 0;
        ans = solve();
        A.clear(), B.clear();
        for (int i = 1; i <= n; i++) {
            if (a[i] < 0) {
                A.push_back(-a[i]);
            }
        }
        for (int i = 1; i <= q; i++) {
            if (b[i] < 0) {
                B.push_back(-b[i]);
            }
        }
        for (int i = 0; i <= q + 1; i++) {
            sum[i] = 0;
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        ans += solve();
        cout << ans << endl;
    }
}

/*
5 6
-1 1 5 11 15
-4 -3 -2 6 7 15
*/