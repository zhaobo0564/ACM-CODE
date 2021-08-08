#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;

struct hjt{
    ll sum, maxn;
    int l, r, pos;
}tree[40 * N];

int top = 1, rt[N], n;
ll s;

vector<pair<int ,ll> > g[N];

int cnt = 1;
#define m (l + r) / 2

void update(ll v, int pos, int last, int &now, int l, int r) {
    now = top++;
    tree[now] = tree[last];
    if (l ==  r) {
        tree[now].sum = tree[now].maxn = v;
        tree[now].pos = l;
        return;
    }
    if (pos <= m) update(v, pos, tree[last].l, tree[now].l, l, m);
    else update(v, pos, tree[last].r, tree[now].r, m + 1, r); 
    tree[now].sum = tree[tree[now].l].sum + tree[tree[now].r].sum;
    if (tree[tree[now].l].maxn >= tree[tree[now].r].maxn) {
        tree[now].maxn = tree[tree[now].l].maxn;
        tree[now].pos = tree[tree[now].l].pos;
    } else {
        tree[now].maxn = tree[tree[now].r].maxn;
        tree[now].pos = tree[tree[now].r].pos;
    }
}

void update1(ll v, int pos, int l, int r, int now) {
    if (l == r) {
        tree[now].sum = tree[now].maxn = v;
        tree[now].pos = l;
        return;
    }
    if (pos <= m) update1(v, pos, l, m, tree[now].l);
    else update1(v, pos, m + 1, r, tree[now].r);
    tree[now].sum = tree[tree[now].l].sum + tree[tree[now].r].sum;
    if (tree[tree[now].l].maxn >= tree[tree[now].r].maxn) {
        tree[now].maxn = tree[tree[now].l].maxn;
        tree[now].pos = tree[tree[now].l].pos;
    } else {
        tree[now].maxn = tree[tree[now].r].maxn;
        tree[now].pos = tree[tree[now].r].pos;
    }

}

vector<ll> v;
int id[N];

ll Ans = 0;
int sz[N];

void dfs(int u, int fa, ll cost, int deep) {
   if (fa && g[u].size() == 1) {
       Ans += cost;
       sz[u] = 1;
   }
    for (auto it: g[u]) {
        int to = it.first;
        ll w = it.second;
        if (to == fa) continue;
        dfs(to, u, cost + w, deep + 1);
        sz[u] += sz[to];
    }
}

void dfs1(int u, int fa, ll cost) {
    
    for (auto it: g[u]) {
        int to = it.first;
        ll w = it.second;
        if (to == fa) continue;
        dfs1(to, u, w);
    }
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> s;
        top = 1;
        v.clear();
        for (int i = 0; i <= n; i++) {
            rt[i] = 0;
            g[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            ll w; cin >> u >> v >> w;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        dfs(1, 0, 0, 0);
        ll ans = 0;
        ll res = 0;
        do {
            res = 0;
             for (int i = 0; i < v.size(); i++) {
                int u = v[i];
                while(tree[rt[u]].sum > s) {
                    ll max = tree[rt[u]].maxn;
                    int pos = tree[rt[u]].pos;
                    ans++;
                    max = max / 2;
                    update1(max, pos, 1, n, rt[u]);
                }
                    res += tree[rt[u]].sum;
            }
            cout << "res " << res << endl;
        } while(res > s);
       
        cout << ans << endl;
        for (int i = 0; i < top; i++) {
            tree[i].l = tree[i].r = tree[i].maxn = tree[i].pos = tree[i].sum = 0;
        }
    }

}