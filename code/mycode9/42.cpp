#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;

ll a[N], n, m;
int L[N], R[N], block[N], vis[N], cat[400][N];

ll cnt[400][400];

vector<ll> g;

int get_id(ll x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin();
}

void build() {
    for (int i = 1; i <= n; i++) {
        L[block[i]] = n + 1;
        R[block[i]] = 0;
    }

    for (int i = 1; i <= n; i++) {
        L[block[i]] = min(L[block[i]], i);
        R[block[i]] = max(R[block[i]], i);
    }

    for (int i = block[1]; i <= block[n]; i++) {
        for (int j = L[i]; j <= R[i]; j++) {
            vis[a[j]]++;
            cat[i][a[j]] = vis[a[j]];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = block[1]; j <= block[n]; j++) {
            if (cat[j][a[i]] == 0) {
                cat[j][a[i]] += cat[j - 1][a[i]];
            }
        }
    }

    for (int i = block[1]; i <= block[n]; i++) {
        ll mx = 0;

        for (int j = i; j <= block[n]; j++) {
            ll maxn = 0;
            for (int k = L[j]; k <= R[j]; k++) {
                int count = cat[j][a[k]] - cat[i - 1][a[k]];
                maxn = max(maxn, 1ll * count * g[a[k]]);
            }
            mx = max(mx, maxn);
            cnt[i][j] = mx;
           // cout << "i = " << i << " j = " << j << " " << mx << endl;
        }
    }
}

vector<int> v;
int f[N];

ll query(int l, int r) {
    ll mx = 0;
    v.clear();
    for (int i = l; i <= R[block[l]]; i++) {
        if (i <= r) {
            f[a[i]]++;
            v.push_back(a[i]);
            int count = f[a[i]] + max(cat[block[r] - 1][a[i]] - cat[block[l]][a[i]], 0);
          //  cout << "count = " << count << endl;
            mx = max(mx, 1ll * count * g[a[i]]);
        }
    }
    if (block[l] != block[r]) {
        for (int i = L[block[r]]; i <= r; i++) {
            f[a[i]]++;
            v.push_back(a[i]);
            int count = f[a[i]] + cat[block[r] - 1][a[i]] - cat[block[l]][a[i]];
            mx = max(mx, 1ll * count * g[a[i]]);
        }
        mx = max(mx, cnt[block[l] + 1][block[r] - 1]);
    }
    for (int i: v) {
        f[i] = 0;
    }
    return mx;
}

int main() {
    scanf("%lld %lld", &n, &m);
    int b = sqrt(n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        g.push_back(a[i]);
        block[i] = i / b + 1;
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());

    for (int i = 1; i <= n; i++) {
        a[i] = get_id(a[i]);
    }
    build();
    ll last = 0;
    while (m--) {
        ll l, r;
        scanf("%lld %lld", &l, &r);
        l = (l ^ last) % n + 1;
        r = (r ^ last) % n + 1;
        if (l > r) swap(l, r);
       // cout << "l = " << l << " r = " << r << endl;
        last = query(l, r);
        printf("%lld\n", last);
    }



    
    
    



    
}