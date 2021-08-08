    #include<bits/stdc++.h>
    using namespace std;
     
    const int N = 5e5 + 7;
    typedef long long ll;
     
    ll a[N], n, k, b[N];
    int rt;
     
    int tree[40 * N], ls[40 * N], rs[40 * N], dp[N];
    int top = 1;
    #define m (l + r) / 2
    void update(int v, int pos, int l, int r, int &node) {
        if (node == 0) node = top++;
        if (l == r) {
            tree[node] = v;
            return;
        }
        if (pos <= m) update(v, pos, l, m, ls[node]);
        else update(v, pos, m + 1, r, rs[node]);
        tree[node] = max(tree[ls[node]], tree[rs[node]]);
    }
     
    int query(int ql, int qr, int l, int r, int node) {
        if (ql <= l && qr >= r) {
            return tree[node];
        }
        int ans = 0;
        if (ql <= m) ans = max(ans, query(ql, qr, l, m, ls[node]));
        if (qr > m) ans = max(ans, query(ql, qr, m + 1, r, rs[node]));
        return ans;
    }
     
    int work(int l, int r) {
        int maxn = n + 2;
        
        for (int i = l + 1; i <= r; i++) {
            if (a[i] >= a[l]) {
                dp[i] = 2;
            } else {
                dp[i] = -1e8;
            }
        }
     
        for (int i = l + 1; i <= r; i++) {
            dp[i] = max(dp[i], query(1, a[i], 1, maxn, rt) + 1);
            if (dp[i] > 1)
            update(dp[i], a[i], 1, maxn, rt);
        }
     
        for (int i = l; i <= r; i++) {
            update(0, a[i], 1, maxn, rt);
        }
        
        if (dp[r] < 2) {
            return -1;
        }
        return (r - l + 1) - dp[r];
        
    }
     
    vector<int> g;
     
    int get_id(int x) {
        return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
    }
     
    int main() {
        ios::sync_with_stdio(0);
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] = a[i] - i;
            g.push_back(a[i]);
        }
        sort(g.begin(), g.end());
        g.erase(unique(g.begin(), g.end()), g.end());
        for (int i = 1; i <= k; i++) {
            cin >> b[i];
        }
        for (int i = 2; i <= k; i++) {
            if (a[b[i]] < a[b[i - 1]]) {
                cout << -1 << endl;
                return 0;
            }
        }
     
        for (int i = 1; i <= n; i++) {
            a[i] = get_id(a[i]);
        }
        b[0] = 0;
        b[k + 1] = n + 1;
        a[0] = 0;
        a[n + 1] = n + 2;
     
        int ans = 0;
     
        for (int i = 1; i <= k + 1; i++) {
            int cnt = work(b[i - 1], b[i]);
            if (cnt < 0) {
                cout << -1 << endl;
                return 0;
            }
            ans += cnt;
        }
        cout << ans << endl;
     
     
    }