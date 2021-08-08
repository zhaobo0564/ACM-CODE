#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 7;

vector<int> g[N];

int n, m, t, a[N], fa[N];

int find(int x) {
    if (x != fa[x]) {
        return fa[x] = find(fa[x]);
    } 
    return x;
}

vector<pair<int, int> >v;
int vis[N];

int main() {
    
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        v.clear();
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
            g[i].clear();
            vis[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            v.push_back({a[i], i});
        }
        sort(v.begin(), v.end(), [](pair<int, int> x, pair<int, int> y) {
            return x.first > y.first;
        });

        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ll ans = 0;
        ll count = 0;
        v.push_back({0, 0});
        for (int i = 0; i < v.size() - 1; i++) {
            int pos = v[i].second;
            int cost = v[i].first;
            int fx = find(pos);
            vis[pos] = 1;
            count++;
            for (int to: g[pos]) {
                if (!vis[to]) continue;
                int fy = find(to);
                if (fx != fy) {
                    fa[fy] = fx;
                    count--;
                }
            }
           ans += (count) * 1ll*(cost - v[i + 1].first);

            
        }
        printf("%lld\n", ans);

        

        
    }
}