#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 7;
typedef long long ll;

vector<ll> g[N];

ll n, a[N], flag[N];
int block[N], L[N], R[N];

void build() {
    for (int i = 1; i <= n; i++) {
        g[block[i]].push_back(a[i]);
        L[block[i]] = n + 1;
        R[block[i]] = 0;
    }

    for (int i = 1; i <= n; i++) {
        L[block[i]] = min(L[block[i]], i);
        R[block[i]] = max(R[block[i]], i);
    }
    for (int i = 1; i <= n; i = R[block[i]] + 1) {
        sort(g[block[i]].begin(), g[block[i]].end());
    }

}

void update(int l, int r, ll v) {
    g[block[l]].clear();
    for (int i = L[block[l]]; i <= R[block[l]]; i++) {
        if (i >= l && i <= r)
            a[i] += v;
        g[block[l]].push_back(a[i]);
    }
    sort(g[block[l]].begin(), g[block[l]].end());
    if (block[l] == block[r]) {
       
    } else {
        g[block[r]].clear();
        for (int i = L[block[r]]; i <= R[block[r]]; i++) {
            if (i >= l && i <= r)
                a[i] += v;
            g[block[r]].push_back(a[i]);
        }
        sort(g[block[r]].begin(), g[block[r]].end());
        for (int i = block[l] + 1; i < block[r]; i++) {
            flag[i] += v;
        }
    }
}

int query(int l, int r, ll v) {
    g[block[l]].clear();
    int ans = 0;
    for (int i = L[block[l]]; i <= R[block[l]]; i++) {
        a[i] += flag[block[l]];
        if (i >= l && i <= r) {
            if (a[i] < v) {
                ans++;
            }
        }
        g[block[l]].push_back(a[i]);
    }
    flag[block[l]] = 0;
    sort(g[block[l]].begin(), g[block[l]].end());
    if (block[l] != block[r]) {
        g[block[r]].clear();
        for (int i = L[block[r]]; i <= R[block[r]]; i++) {
            a[i] += flag[block[r]];
            if (i >= l && i <= r) {
                if (a[i] < v) {
                    ans++;
                }
            }
            g[block[r]].push_back(a[i]);
        }
        flag[block[r]] = 0;
        sort(g[block[r]].begin(), g[block[r]].end());
        for (int i = block[l] + 1; i < block[r]; i++) {
            int p = lower_bound(g[i].begin(), g[i].end(), v - flag[i]) - g[i].begin();
            if (p > 0) {
                ans += p;
            }
        }
    }
    return ans;

}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    int b = sqrt(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        block[i] = i / b;
    }
    build();
    while (n--) {
        ll op, l, r, c;
        cin >> op >> l >> r >> c;
        if (op == 0) {
            update(l, r, c);
        } else {
            cout << query(l, r, c * c) << endl;
        }
    }


}