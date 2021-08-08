#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2007;

struct node{
    ll u, v, d;

}p[N];

ll dist(node x, node y) {
    return (x.u - y.u) * (x.u - y.u) + (x.v - y.v) * (x.v - y.v);
}

ll mp[N][N];

bool cmp(node x, node y) {
    return x.d > y.d;
}

vector<node > g;

int vis[N][N];
int t, n;
void work(int u, ll d) {
    for (int i = 1; i <= n; i++) {
        if (i == u)continue;
        if (mp[min(u, i)][max(u, i)] >= d) {
            vis[min(u, i)][max(u, i)] = 1;
        } else {
            vis[min(u, i)][max(u, i)] = -1;
        }
    }
}


int main() {
   
    scanf("%d", &t);
    while (t--) {
        g.clear();
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                vis[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            p[i].u = x;
            p[i].v = y;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ll d = dist(p[i], p[j]);
                mp[i][j] = d;
                g.push_back({i, j, d});
            }
        }
        sort(g.begin(), g.end(), cmp);
        for (int i = 0; i < g.size(); i++) {
            int u = g[i].u;
            int v = g[i].v;
            ll d = g[i].d;
            if (vis[min(u, v)][max(v, u)] != 0) {
                continue;
            } else {
                vis[min(u, v)][max(v, u)] = 1;
                work(u, d);
                work(v, d);
            }
        }
        int f = 0;
        for (int i = 2; i <= n; i++) {
            if (vis[1][i] == 1) {
                f = 1;
                break;
            }
        }
        if (f) {
            puts("YES");
        } else {
            puts("NO");
        }
        

    }    
}