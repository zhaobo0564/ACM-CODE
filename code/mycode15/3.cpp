#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;

// 无向图求桥 与环的大小
vector<pair<int, int> >g[N];

int dfn[N], flow[N], cnt, vis[N];
stack<int>q;

int cat[N], top = 1;

int n, m;
int ans;

void tarjan(int u, int fa){
    dfn[u] = flow[u] = ++cnt;
    vis[u] = 1;
    q.push(u);
    for(auto it: g[u]){
        int to = it.first;
        if(!dfn[to]){
            tarjan(to, u);
            flow[u] = min(flow[u], flow[to]);
            if(flow[to] > dfn[u]) ans++; // 求桥的数量
        }else if(vis[to] && fa != to){
            flow[u] = min(flow[u], dfn[to]);
        }
    }


    if(flow[u] == dfn[u]){
        while(1){
            int now = q.top();
            q.pop();
            vis[now] = 0;  // now为强连通
            cat[now] = top;
            if(now == u)break;
        }
        top++;
    }
}

int OK[N];

vector<pair<int, int> > G[N];

int s, t;

void dfs(int u, int fa, int ok) {
    if (OK[u]) ok = 1;
 //   cout << "u = " << u << endl;
    if (u == cat[t]) {
        if (ok) {
            puts("YES");
        } else {
            puts("NO");
        }
        return;
    }
    for (auto it: G[u]) {
        int to = it.first;
        int w = it.second;
        if (to == fa) continue;
        dfs(to, u, w | ok);
    }
}


int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    scanf("%d %d", &s, &t);
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i, 0);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto it: g[i]) {
            int to = it.first;
            int w = it.second;
            if (cat[i] != cat[to]) {
                G[cat[i]].push_back({cat[to], w});
             //   G[cat[to]].push_back({cat[i], w});
            } else {
                if (w == 1) {
                    OK[cat[i]] = 1;
                }
            }
        }
    }
    dfs(cat[s], 0, 0);



}