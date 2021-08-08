#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
typedef long long ll;

int block[N];
int n, a[N], q, L[N], R[N];

struct node {
    int l, r, id;
};
vector<node>g[N];
bool cmp(node x, node y) {
    return x.r < y.r;
}
void init() {
    for (int i = 1; i <= n; i++) {
        L[block[i]] = min(L[block[i]], i);
        R[block[i]] = max(R[block[i]], i);
    }
    for (int i = 1; i <= n; i = R[block[i]] + 1) {
        sort(g[block[i]].begin(), g[block[i]].end(), cmp);
    }
}

ll vis[N], ans[N], cnt[N], cat[N];

ll cal(ll x) {
    return 1ll* (1ll*x * 1ll*(x  - 1)) / 2;
}

void solve() {

    for (int i = 1; i <= n; i = R[block[i]] + 1) {
        int pos = R[block[i]] + 1;
        ll dog = 0;
        for (int j = 0; j < g[block[i]].size(); j++) {
            int l = g[block[i]][j].l;
            int r = g[block[i]][j].r;
            int id = g[block[i]][j].id;
            if (r <= R[block[i]]) {
                ll res = 0;
                for (int k = l; k <= r; k++) {
                    res -= 1ll*cal(vis[a[k]]);
                    vis[a[k]]++;
                    res += 1ll*cal(vis[a[k]]);
                }
                for (int k = l; k <= r; k++) {
                    vis[a[k]] = 0;
                }
                ans[id] = res;
                cat[id] = cal(r - l + 1);
            } else {
                int res = 0;
                while (pos <= r) {
                    dog -= cal(cnt[a[pos]]);
                    cnt[a[pos]]++;
                    dog += cal(cnt[a[pos]]);
                    pos++;
                }
                for (int k = l; k <= R[block[i]]; k++) {
                    res -= cal(vis[a[k]] + cnt[a[k]]);
                    vis[a[k]]++;
                    res += cal(vis[a[k]] + cnt[a[k]]);
                }
                for (int k = l; k <= R[block[i]]; k++) {
                    vis[a[k]] = 0;
                }
                ans[id] = res + dog;
                cat[id] = cal(r - l + 1);

            }
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
        L[i] = n + 1;
        R[i] = 0;
    }
    for (int i = 1; i <= q; i++) {
        int l, r; scanf("%d %d", &l, &r);
        g[block[l]].push_back({l, r, i});
    }
    init();
    solve();
    for (int i = 1; i <= q; i++) {
        if (ans[i] == 0) {
            puts("0/1");
            continue;
        }
        int gcd = __gcd(ans[i], cat[i]);
        printf("%lld/%lld\n", ans[i] / gcd, cat[i] / gcd);
    }
    
}