#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 7;

vector<int> g[N];


int dfn[N], flow[N], cnt, vis[N];
stack<int>q;

int cat[N], top = 1;


void tarjan(int u){
    dfn[u] = flow[u] = ++cnt;
    vis[u] = 1;
    q.push(u);
    for(int to: g[u]){
        if(!dfn[to]){
            tarjan(to);
            flow[u] = min(flow[u], flow[to]);
        }else if(vis[to]){
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

vector<int> G[N];

int cn[N][N], ans[N][N];
 int n, m1, m2, Q;
void bfs(int u) {
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(u);
    while (q.size()) {
        int cd = q.front();
        q.pop();
        ans[u][cd] = 1;
        if (vis[cd]) continue;
        vis[cd] = 1;
        for (int to: G[cd]) {
            q.push(to);
        }
    }
}

void work() {
    cnt = 0;
    top = 1;
    memset(vis, 0, sizeof(vis));
    memset(cn, 0, sizeof(cn));
    memset(ans, 0, sizeof(ans));
    memset(dfn, 0, sizeof(dfn));
    memset(flow, 0, sizeof(flow));
    memset(cat, 0, sizeof(cat));
    while (q.size()) q.pop();
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) {
            tarjan(i);
        }
        G[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        for (int to: g[i]) {
            int u = cat[i], v = cat[to];
            if (u == v) continue;
            if (cn[u][v] == 0) {
                cn[u][v] = 1;
                G[u].push_back(v);
            }
            
        }
    }
    for (int i = 1; i < top; i++) {
        bfs(i);
    }


}

int ans1[N][N], s[N][N];

int main() {
    cin >> n >> m1 >> m2 >> Q;
    for (int i = 1; i <= m1; i++) {
        int x, y; scanf("%d %d", &x, &y);
        g[x].push_back(y);
        s[x][y] = 1;
    }
    work();
    for (int i = 1; i <= n; i++) {
     //   g[i].clear();
        for (int j = 1; j <= n; j++) {
            ans1[i][j] = ans[cat[i]][cat[j]];
        }
    }
    for (int i = 1; i <= m2; i++) {
        int x, y; scanf("%d %d", &x, &y);
        s[x][y] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i][j] == 0 && i != j) {
                g[i].push_back(j);
            }
        }
    }
    work();
    while (Q--) {
        int x, y; scanf("%d %d", &x, &y);
        if (ans1[x][y]) {
            printf("Yes ");
        } else {
            printf("No ");
        }
        if (ans[cat[x]][cat[y]]) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }


}