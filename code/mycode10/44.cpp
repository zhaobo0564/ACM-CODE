#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

int a[N], s, n;
int d = 131071;

vector<pair<int, int> > g[N];

int vis[N], dist[N];
struct node {
    int u, w;

    bool operator < (const node & x) const {
        return w > x.w;
    }
};

priority_queue<node> q;

int main() {
    for (int i = 0; i < N; i++) {
        dist[i] = 1e9;
    }
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int to = d ^ a[i];
        g[i].push_back({to + n + 1, 1});
        g[a[i] + n + 1].push_back({i, 0});
    }
    for (int i = 1; i <= d; i++) {
        for (int j = 0; j <= 20; j++) {
            if ((i & (1 << j))) {
                g[i + n + 1].push_back({i - (1 << j) + n + 1, 0});
            }
        }
    }
    q.push({s, 0});
    dist[s] = 0;
    while (q.size()) {

        int cd = q.top().u;
        q.pop();
        if (vis[cd]) continue;
        vis[cd] = 1;
        for (auto it: g[cd]) {
            if (dist[it.first] > dist[cd] + it.second) {
                dist[it.first] = dist[cd] + it.second;
                q.push({it.first, dist[it.first]});
              
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i] == 1000000000) {
            cout << -1 << " ";
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << endl;




}