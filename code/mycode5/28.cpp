#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

vector<int> g[N], ans, G[N];

int n, m, t, d[N], vis[N];

struct edge{
    int x, y, z;
}p[N];

int pos[N];


vector<pair<int, int> >cnt;

int main() {
    scanf("%d", &t);
    while (t--) {
        ans.clear();
        cnt.clear();
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            d[i] = 0;
            vis[i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            if (x == 1) {
                g[y].push_back(z);
                d[z]++;
                cnt.push_back({y, z});
    
            } 
            p[i] = {x, y, z};
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (d[i] == 0) {
                q.push(i);
            }
        }
        while (q.size()) {
            int cd = q.front();
            q.pop();
            ans.push_back(cd);
            if (vis[cd]) continue;
            vis[cd] = 1;
            for (int to: g[cd]) {
                d[to]--;
                if (d[to] == 0) q.push(to);
            }

        }
        if (ans.size() != n) {
            puts("No");
        } else {
            puts("YES");
            for (int i = 0; i < ans.size(); i++) {
                pos[ans[i]] = i;
            }
            for (int i = 1; i <= m; i++) {
                if (p[i].x == 0) {
                    if (pos[p[i].y] > pos[p[i].z]) {
                        cnt.push_back({p[i].z, p[i].y});
                    } else {
                        cnt.push_back({p[i].y, p[i].z});
                    }
                }
            }
            for (auto it: cnt) {
                printf("%d %d\n", it.first, it.second);
            }
          //a  puts("");
        }


    }
}