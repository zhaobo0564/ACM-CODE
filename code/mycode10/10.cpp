#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 7;
typedef long long ll;

int n, m1, m2, q;

vector<int> g[N];

int ans[N][N], vis[N], vis1[N];

void bfs(int u) {
    queue<int> q;
    for  (int i = 1; i <= n; i++) {
        vis[i] = 0;
    }
    q.push(u);
    while (q.size()) {
        int cd = q.front();
        q.pop();
        ans[u][cd] = 1;
        if (vis[cd]) continue;
        vis[cd] = 1;
        for (int to: g[cd]) {
            q.push(to);
        }
        
    }
}

int cnt[N][N];

int head[N];

struct edge {
    int to, next;
}e[N * N];

int top = 1;

void add_edge(int u, int v) {
    e[top].to = v;
    e[top].next = head[u];
    head[u] = top++;
}

int ans1[N][N];

void bfs1(int u) {
    queue<int> q;

    q.push(u);
    while (q.size()) {
        int cd = q.front();
        q.pop();
        ans1[u][cd] = 1;
        if (vis[cd]) continue;
        vis[cd] = 1;
        for (int i = head[u]; i; i = e[i].next) {
            q.push(e[i].to);
        }
    }
}

int fa[N];

int find(int x) {
    if (x != fa[x]) {
        return fa[x] = find(fa[x]);
    }
    return x;
}

int sz[N];

void merge(int x, int y) {
    if (sz[x] > sz[y]) {
        fa[y] = fa[x];
        sz[x] += sz[y];
    } else {
        fa[x] = fa[y];
        sz[y] += sz[x];
    }
}

vector<int> G[N];

int main() {
    scanf("%d %d %d %d", &n, &m1, &m2, &q);
    for (int i = 1; i <= m1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
    }
    for(int i = 1; i <= n; i++) {
        bfs(i);
        fa[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= m2; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        cnt[u][v] = 1;
    }
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
        for (int j = 1; j <= n; j++) {
            if (cnt[i][j] == 0 && cnt[j][i] == 0) {
               
                int fx = find(i), fy = find(j);
                if (fx != fy) { 
                    merge(fx, fy);
                }
            }
        }
    }
    int node = 1;
    for (int i = 1; i <= n; i++) {
        int fx = find(i);
        if (vis1[fx] == 0) {
            vis1[fx] = node++;
        }
        G[vis1[fx]].push_back(i);
    }
    for (int i = 1; i < node; i++) {
        for (int j = 1; j < node; j++) {
            int f = 0;
            for (int k: G[i]) {
                for (int z: G[j]) {
                    if (cnt[k][z] == 0) {
                        f = 1;
                        break;
                    }
                }
                if (f) break;
            }
            if (f) {
                add_edge(i, j);
            }
        }
    }
    for (int i = 1; i < node; i++) {
        for (int j = 1; j < node; j++) {
            vis[j] = 0;
        }
        bfs1(i);
    }
    while (q--) {
        int x, y; scanf("%d %d", &x, &y);
        if (ans[x][y]) {
            puts("Yes Yes");
        } else {
            int fx = find(x);
            int fy = find(y);
            if (fx == fy) {
                puts("No Yes");
            } else {
                if (ans1[vis1[fx]][vis1[fy]]) {
                    puts("No Yes");
                } else {
                    puts("No No");
                }
            }
        }
    }
}

/*
6 4 10 132
1 2
2 1
1 6
5 6
3 6
6 3
3 4
2 4
1 4
6 4
2 3
3 2
1 5
5 4
1 4
*/
