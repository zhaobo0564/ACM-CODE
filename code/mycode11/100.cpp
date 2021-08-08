#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

struct node {
    ll u, d;
    bool operator < (const node x) const {
        return d > x.d;
    }
};

struct edge{
    ll to, w, k;
};

vector<edge> g[N];
int vis[N];
priority_queue<node>q;

ll dj(int s, int t) {
    q.push({s, 0});
    while (q.size()) {
        node cd = q.top();
        q.pop();
        if (cd.u == t) {
            return cd.d;
        }
        if (vis[cd.u]) continue;
        vis[cd.u] = 1;
     //   cout << " u " << cd.u << endl;
        for (edge it: g[cd.u]) {
            ll to = it.to;
            ll w = it.w;
            ll k = it.k;
            ll cat = cd.d;
          //  cout << cat  << " " << k << endl;
            if (cat % k) {
               // cout << "AA" <<  (cat % k) << endl;
                cat = (k - cat % k) + cat;
               // cout << "cat " << cat << endl;
            }
            q.push({to, cat + w});
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= m; i++) {
        ll a, b, t, k;
        cin >> a >> b >> t >> k;
        g[a].push_back({b, t, k});
        g[b].push_back({a, t, k});
    }
    cout << dj(x, y) << endl;
}