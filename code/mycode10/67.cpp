#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;
typedef long long ll;

ll n, m, d[N];

ll sum[N];

struct edge{
    ll u, v, w;
}e[N];

struct node {
    ll to, w;
    bool operator < (const node x) const {
        return w > x.w;
    }
};


int vis[N];

int head[N], top = 1;

struct EDGE {
    int to, nxt;
    ll w;
}E[3 * N];


void add(int u, int v, int w) {
    E[top].to = v;
    E[top].w = w;
    E[top].nxt = head[u];
    head[u] = top++;
}

void add_edge(int u, int v, int w) {
    add(u, v, w);
    add(v, u, w);
}
 
vector<int> g;

int get_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

ll dist[42][N];
 priority_queue<node> q;
void dj(int s, int id) {
   
    q.push({s, 0});
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
        dist[id][i] = 1e16;
    }
    dist[id][s] = 0;
    while (q.size()) {
        node cd = q.top();
        q.pop();
        if (vis[cd.to]) continue;
        vis[cd.to] = 1;
        for (int i = head[cd.to]; i; i = E[i].nxt) {
            int to = E[i].to;
            ll w = E[i].w;
            if (dist[id][to] > dist[id][cd.to] + w) {
                dist[id][to] = dist[id][cd.to] + w;
                q.push({to, dist[id][to]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        if (i + 1 <= n) {
            add_edge(i, i + 1, d[i]);
        } else {
            add_edge(i, 1, d[n]);
        }
       
    }

    for (int  i = 1; i < n; i++) {
        sum[i + 1] = sum[i] + d[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        g.push_back(e[i].u);
        g.push_back(e[i].v);
        add_edge(e[i].u, e[i].v, e[i].w);
    }
    sort(g.begin(),g.end());
    g.erase(unique(g.begin(), g.end()), g.end());

    for (int  i = 1; i <= m; i++) {
        dj(e[i].u, get_id(e[i].u));
        dj(e[i].v, get_id(e[i].v));
    }

    int q; cin >> q;
    while (q--) {
        int x, y; cin >> x >> y;
        if (y < x) swap(x, y);
        ll ans = sum[y] - sum[x];

        ans = min(ans, sum[x] + sum[n] - sum[y] + d[n]);

        for  (int i: g) {
            ans = min(ans, dist[get_id(i)][x] + dist[get_id(i)][y]);
        }

        cout << ans << endl;
    }
}