#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;


#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

typedef long long ll;
vector<pair<int, ll> > g[N];
int d[N], cat[N], top = 1;

ll tree[4 * N];

void tp(int n) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) {
            q.push(i);
        }
    }
    while (q.size()) {
        int cd = q.front();
        q.pop();
        cat[cd] = top++;
        for (auto it: g[cd]) {
            int to = it.first;
            d[to]--;
            if (d[to] == 0) {
                q.push(to);
            }
        }

    }
}

ll dist[3][N], vis[N];

struct node {
    int to;
    ll w;
    bool operator <(const node  x) const {
        return w > x.w;
    }
};

priority_queue<node> q;


void dj(int s, int n, int id) {
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
        dist[id][i] = 1e15;
    }
    q.push({s, 0});
    dist[id][s] = 0;
    while (q.size()) {
        node cd = q.top();
        q.pop();
        if (vis[cd.to]) continue;  
        vis[cd.to] = 1;
        for (auto it: g[cd.to]) {
            int to = it.first;
            ll w = it.second;
            if (dist[id][to] > dist[id][cd.to] + w) {
                dist[id][to] = dist[id][cd.to] + w;
                q.push({to, dist[id][to]});
            }
        }
    }

}


void update(ll v, int ql, int qr, int l, int r, int node) {
    if (ql > qr) return;
    if (ql <= l && qr >= r) {
        tree[node] = min(tree[node], v);
        return ;
    } 
    if (ql <= m) update(v, ql, qr, l, m, lson);
    if (qr > m) update(v, ql, qr, m + 1, r, rson);
}

ll query(int pos, int l, int r, int node) {
    if (l == r) {
        return tree[node];
    }

    if (pos <= m) return min(tree[node], query(pos, l, m, lson));
    else return min(tree[node], query(pos, m + 1, r, rson));
}

struct edge{
    int u, v, w;
} e[N];

int main() {
    int n, M, s, t;
    scanf("%d %d %d %d", &n, &M, &s, &t);
    for (int i = 0; i < 4 * N; i++) {
        tree[i] = 1e16;
    }
    for (int i = 1; i <= M; i++) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        g[u].push_back({v, w});
    
        d[v]++;
        e[i].u = u, e[i].v = v, e[i].w = w;
    }
    tp(n);
 
    top--;
    dj(s, n, 1);
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
    for (int i = 1; i <= M; i++) {
        g[e[i].v].push_back({e[i].u, e[i].w});
    }

    dj(t, n, 2);
    for (int i = 1; i <= M; i++) {
        int u = e[i].u, v = e[i].v;
        ll w = e[i].w + dist[1][u] + dist[2][v];
      //  cout << "l = " << cat[u] + 1 << " r = " << cat[v] - 1<< " w = " << w << endl;
        update(w, cat[u] + 1, cat[v] - 1, 1, top, 1);
    }
    int q; scanf("%d", &q);
    while (q--) {
        int x; scanf("%d", &x);
        ll ans = query(cat[x] , 1, top, 1);
        if (ans >= 1e15) {
            puts("-1");
        } else {
            printf("%lld\n", ans);
        }

    }
    
}