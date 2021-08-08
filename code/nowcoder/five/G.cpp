#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 7;

vector<pair<int, ll>>g[N];

int tree[40 * N][2], n, m;

vector<ll>v;

void dfs(int u, ll w, int fa) {
    v.push_back(w);
    for (auto it: g[u]) {
        int to = it.first;
        ll cost = it.second;
        if (to == fa) continue;
        dfs(to, w ^ cost, u);
    }
}

int top = 2;

void insert(ll x) {
    int rt = 1;
    for (int i = 29; i >= 0; i--) {
        if (x & (1 << i)) {
            if (tree[rt][1] == 0) {
                tree[rt][1] = top++;
            }
            rt = tree[rt][1];
        } else {
            if (tree[rt][0] == 0) {
                tree[rt][0] = top++;
            }
            rt = tree[rt][0];
        }
    }
}

ll find(ll value, ll sum, int rt, int p) {
    if ((value & (1 << p)) && tree[rt][1]) {
        return find(value, sum, tree[rt][1], p - 1);
    } else if ((value & (1 << p)) == 0 && tree[rt][0]) {
        return find(value, sum, tree[rt][0], p - 1);
    } else if(tree[rt][0]) {
        return find(value, sum, tree[rt][0], p - 1) + (1ll << p);
    } else if (tree[rt][1]) {
        return find(value, sum, tree[rt][1], p - 1) + (1ll << p);
    }

    return sum;
}

ll Ans = 0;

void work(ll sum, int p, int node) {
    if (p < 0) return;
    int r = sum + (1 << (p + 1)) - 1;
    int l = sum + (1 << p);
    l = lower_bound(v.begin(), v.end(), l) - v.begin();
    r = upper_bound(v.begin(), v.end(), r) - v.begin();
    ll minn = LLONG_MAX;
    for (int i = l; i < r; i++) {
        ll cnt = 0;
        if ((v[i] & (1 << p))) {
            cnt = (1 << p);
        }
        if (tree[node][0]) {
           // cout << "cnt " << cnt << " p" << p - 1 << endl;
            minn = min(minn, find(v[i], cnt,  tree[node][0], p - 1));
        }
    }
    if (minn != LLONG_MAX) {
        Ans += minn;
    }
    if (tree[node][0]) {
        work(sum, p - 1, tree[node][0]);
    }
    if (tree[node][1]) {
        work(sum + (1 << p), p - 1, tree[node][1]);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u++, v++;
        g[u].push_back({v, 1ll*w});
        g[v].push_back({u, 1ll*w});
    }
    dfs(1, 2123, 0);
    sort(v.begin(), v.end());
    for (ll i: v) {
        insert(i);
    }

    work(0, 29, 1);
    printf("%lld\n", Ans);

}