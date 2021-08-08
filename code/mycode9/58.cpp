#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int a[N], L[N], R[N], block[N], n, m, ans[N];

struct node {
    int l, r, id, t;
};
vector<node> g[N];
vector<int> v;

bool cmp(node x, node y) {
    return x.r < y.r;
}

int get_id(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

void init() {
    for (int i = 1; i <= n; i++) {
        R[block[i]] = 0;
    }
    for (int i = 1; i <= n; i++) {
        R[block[i]] = max(R[block[i]], i);
    }
    for (int i = 1; i <= n; i = R[block[i]] + 1) {
        sort(g[block[i]].begin(), g[block[i]].end(), cmp);
    }
}

int vis[N], maxn_vis[N], cnt[N], maxn_cnt[N];

void solve() {
    for (int i = 1; i <= n; i = R[block[i]] + 1) {
        int pos = R[block[i]] + 1;
        for (int j = 0; j < g[block[i]].size(); j++) {
            int l = g[block[i]][j].l;
            int r = g[block[i]][j].r;
            int id = g[block[i]][j].id;
            int t = g[block[i]][j].t;
          //  cout << "l = " << l << " r = " << r << endl;
            if (r <= R[block[i]]) {
                for (int k = l; k <= r; k++) {
                    vis[a[k]]++;
                    maxn_vis[vis[a[k]]] = max(maxn_vis[vis[a[k]]], a[k]);
                }
                int T = (r - l + 1) / t;

                int res = 0;
                for (int k = T + 1; k <= T + 30; k++) {
                    res = max(res, maxn_vis[k]);
                }
                for (int k = l; k <= r; k++) {
                    maxn_vis[vis[a[k]]] = 0;
                    vis[a[k]]--;

                }
                ans[id] = res;
            } else {
                while (pos <= r) {
                    cnt[a[pos]]++;
                    maxn_cnt[cnt[a[pos]]] = max(maxn_cnt[cnt[a[pos]]], a[pos]);
                    pos++;
                }
                for (int k = l; k <= R[block[i]]; k++) {
                    vis[a[k]]++;
                    maxn_vis[vis[a[k]] + cnt[a[k]]] = max(maxn_vis[vis[a[k]] + cnt[a[k]]], a[k]);
                }
                int T = (r - l + 1) / t;
                int res = 0;
                for (int k = T + 1; k <= T + 30; k++) {
                    res = max(res, maxn_vis[k]);
                    res = max(res, maxn_cnt[k]);
                }
                ans[id] = res;
                for (int k = l; k <= R[block[i]]; k++) {
                    maxn_vis[vis[a[k]] + cnt[a[k]]] = 0;
                    vis[a[k]]--;
                }
            }
        }
        for (int j = 1; j <= n; j++) {
            maxn_cnt[cnt[a[j]]] = 0;
            if (cnt[a[j]])
                cnt[a[j]]--;

        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    int b = sqrt(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        v.push_back(a[i]);
        block[i] = i / b;
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 1; i <= n; i++) {
        a[i] = get_id(a[i]);
    }
    for (int i = 1; i <= m; i++) {
        int l, r, t; scanf("%d %d %d", &l, &r, &t);
        g[block[l]].push_back({l, r, i, t});
    }
    init();
    solve();
    for (int i = 1; i <= m; i++) {
        if (ans[i] == 0) {
            puts("-1");
            continue;
        }
        printf("%d\n", v[ans[i] - 1]);
    }
}