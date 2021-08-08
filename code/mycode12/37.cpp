#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;

int a[N], n, L[N], R[N], q, block[N]; 
ll ans[N];

struct node {
    int l, r, id;
};

bool cmp(node x, node y) {
    return x.r < y.r;
}

vector<node>g[N];

void init() {
    for (int i = 1; i <= n; i++) {
        L[block[i]] = min(i, L[block[i]]);
        R[block[i]] = max(R[block[i]], i);
    }

    for (int i = 1; i <= n; i = R[block[i]] + 1) {
        sort(g[block[i]].begin(), g[block[i]].end(), cmp);
    }
    
}

int vis[N], cnt[N];

vector<int> v;

int get_id(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

void solve() {
    
    for (int i = 1; i <= n; i = R[block[i]] + 1) {
        int pos = R[block[i]] + 1;
        ll res1 = 0;
        for (auto it: g[block[i]]) {
            int l = it.l;
            int r = it.r;
            int id = it.id;
          //  cout << "l = " << l << " r = " << r << endl;
            ll res = 0;
            if (block[l] == block[r]) {
                for (int j = l; j <= r; j++) {
                    vis[a[j]]++;
                    res = max(res, 1ll * vis[a[j]] * 1ll * v[a[j] - 1]);
                }
                ans[id] = res;
                for (int j = l; j <= r; j++) {
                    vis[a[j]] = 0;
                }
            } else {
                while (pos <= r) {
                    cnt[a[pos]]++;
                    res1 = max(res1, 1ll * cnt[a[pos]] * 1ll * v[a[pos] - 1]);
                    pos++;
                }
                for (int j = l; j <= R[block[i]]; j++) {
                    vis[a[j]]++;
                    ll t = vis[a[j]] + cnt[a[j]];
                    res = max(res, 1ll * t * 1ll*v[a[j] - 1]);
                }
                ans[id] = max(res, res1);
                for (int j = l; j <= R[block[i]]; j++) {
                    vis[a[j]] = 0;
                }
            }
           // cout << "res = " << res << " res1 = " << res1 << endl; 
        }
        for (int j = 1; j <= n; j++) {
            cnt[a[j]] = 0;
        }
    }
}


int main() {
    scanf("%d %d", &n, &q);
    int b = sqrt(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        block[i] = i / b;
        L[block[i]] = n;
        v.push_back(a[i]);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 1; i <= n; i++) {
        a[i] = get_id(a[i]);
    }
    for (int i = 1; i <= q; i++) {
        int l, r; scanf("%d %d", &l, &r);
        g[block[l]].push_back({l, r, i});
    }
    init();
    solve();
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << endl;
    }
}