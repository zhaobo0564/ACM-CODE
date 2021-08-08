#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

typedef long long ll;

ll n, a[N], flag[N];
int block[N], L[N], R[N];
vector<ll> g[N];

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
    for (int i = L[block[l]]; i <= R[block[l]]; i++) {
        if (i >= l && i <= r)
            a[i] += v;
    }
    g[block[l]].clear();
    for (int i = L[block[l]]; i <= R[block[l]]; i++) {
        g[block[l]].push_back(a[i]);
    }
    sort(g[block[l]].begin(), g[block[l]].end());

    if (block[l] != block[r]) {
        for (int i = L[block[r]]; i <= R[block[r]]; i++) {
            if (i >= l && i <= r)
                a[i] += v;
        }
        g[block[r]].clear();
        for (int i = L[block[r]]; i <= R[block[r]]; i++) {
            g[block[r]].push_back(a[i]);
        }
        sort(g[block[r]].begin(), g[block[r]].end());

        for (int i = block[l] + 1; i < block[r]; i++) {
            flag[i] += v;
        }
    }
}

ll query(int l, int r, ll v) {
    ll maxn = LLONG_MIN;
    for (int i = L[block[l]]; i <= R[block[l]]; i++) {
        if (i >= l && i <= r) {
            if (a[i] + flag[block[l]] < v) {
                maxn = max(a[i] + flag[block[l]], maxn);
            }
        } 
    }
    if (block[l] != block[r]) {
        for (int i = L[block[r]]; i <= R[block[r]]; i++) {
            if (i >= l && i <= r) {
                if (a[i] + flag[block[r]] < v) {
                    maxn = max(a[i] + flag[block[r]], maxn);
                }
            }
        }

        for (int i = block[l] + 1; i < block[r]; i++) {
            int p = lower_bound(g[i].begin(), g[i].end(), v - flag[i]) - g[i].begin();
            p--;
            if (p >= 0 && p < g[i].size()) {
                maxn = max(maxn, g[i][p] + flag[i]);
            }
        }
    }

    return maxn == LLONG_MIN ? -1: maxn;

}

int main() {
    cin >> n;
    int b = 500;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        block[i] = i / b;
    }
    build();

    int q = n;
    while (q--) {
        ll op, l, r, c;
        scanf("%lld %lld %lld %lld", &op, &l, &r, &c);
        if (op == 0) {
            update(l, r, c);
        } else {
            printf("%lld\n", query(l, r, c));
        }
    }
    
}