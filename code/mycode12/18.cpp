#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
vector<int> g, G;
typedef long long ll;

int getx_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

int gety_id(int x) {
    return lower_bound(G.begin(), G.end(), x) - G.begin() + 1;
}

struct hjt{
    int l, r;
    ll value;
} tree[40 * N];

struct node {
    int x, y, z;
} p[N];

struct qu{
    int x0, y0, x, y;
}Q[N];

bool cmp(node x, node y) {
    return x.x < y.x;
}

int rt[N], top = 1;

#define m (l + r) / 2

void update(int pos, int v, int l, int r, int last, int &node) {
    node = top++;
    tree[node] = tree[last];
    if (l == r) {
        tree[node].value += 1ll*v;
        return;
    }
    if (pos <= m) update(pos, v, l, m, tree[last].l, tree[node].l);
    else update(pos, v, m + 1, r, tree[last].r, tree[node].r);
    tree[node].value = tree[tree[node].l].value + tree[tree[node].r].value;
    
}

ll query(int ql, int qr, int l, int r, int now) {
    if (ql <= l && qr >= r) {
        return tree[now].value;
    }
    ll ans = 0;
    if (ql <= m) ans += query(ql, qr, l, m, tree[now].l);
    if (qr > m) ans += query(ql, qr, m + 1, r, tree[now].r);
    return ans;
}
int n, q;

vector<pair<int, int> > v[N];
map<int, int> vis;


int main() {
    
    ios::sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y >> p[i].z;
        g.push_back(p[i].x);
        G.push_back(p[i].y);
        if (vis[p[i].x]) {
            v[vis[p[i].x]].push_back({p[i].y, p[i].z});
        } else {
            vis[p[i].x] = i;
            v[vis[p[i].x]].push_back({p[i].y, p[i].z});
        }

    } 
    for (int i = 1; i <= q; i++) {
        cin >> Q[i].x0 >> Q[i].y0 >> Q[i].x >> Q[i].y;
        g.push_back(Q[i].x0);
        G.push_back(Q[i].y0);
        g.push_back(Q[i].x);
        G.push_back(Q[i].y);
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    sort(G.begin(), G.end());
    G.erase(unique(G.begin(), G.end()), G.end());
    
    for (int i = 0; i < g.size(); i++) {
        int pos = vis[g[i]];
        if (pos) {
            int last = i;
            for (auto it: v[vis[g[i]]]) {
                update(gety_id(it.first), it.second, 1, G.size(), rt[last], rt[i + 1]);
                last = i + 1;
            }
        } else {
            rt[i + 1] = rt[i];
        }
    }
    
    for (int i = 1; i <= q; i++) {
        int x0 = getx_id(Q[i].x0);
        int y0 = gety_id(Q[i].y0);
        int x = getx_id(Q[i].x);
        int y = gety_id(Q[i].y);
       // cout << tree[rt[1]].value << endl;
        ll ans = query(y0, G.size(), 1, G.size(), rt[x]);
        ans = ans - query(y0, G.size(), 1, G.size(), rt[x0 - 1]);
       // cout << "ans = " << ans << endl;
        ans = ans - query(y + 1, G.size(), 1, G.size(), rt[x]);
        //cout << "ans = " << ans << endl;
        ans += query(y + 1, G.size(), 1, G.size(), rt[x0 - 1]);
        cout << ans << endl;
    }
  
    return 0;
}
