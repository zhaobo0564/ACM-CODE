#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;

int head[N], top = 1, n, m, fa[N], ranks[N];

list<int> q[N];

queue<int>p;

struct edge {
    int u, next;
}e[2 * N];

void add_edge(int u, int v) {
    e[top].u = v;
    e[top].next = head[u];
    head[u] = top++;
}

int find(int x) {
    if (x  != fa[x]) {
        return fa[x] = find(fa[x]);
    }
    return x;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);

        top = 1;
        for (int i = 0; i < n; i++) {
           q[i].clear();
        }
        for (int i = 0; i < n; i++) {
            head[i] = 0;
            fa[i] = i;
            ranks[i] = 1;
            q[i].push_back(i);
        }
        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            add_edge(u, v);
            add_edge(v, u);
        }
        int Q; scanf("%d", &Q);
 
        while (Q--) {
            int x; scanf("%d", &x);
            if (x != fa[x]) continue;
            int fx = find(x);
            int cnt = q[x].size();
            while (cnt--) {
               
                int cd = q[x].front();
                q[x].pop_front();
                p.push(cd);
                for (int i = head[cd]; i; i = e[i].next) {
                    int to = e[i].u;
                    int fy = find(to);
                    if(fx != fy) {
                        fa[fy] = fx;
                        q[x].splice(q[x].end(), q[fy]);
                    }
                   
                }
            }
         

        }

        for (int i = 0; i < n; i++) {
            printf("%d ", find(i));
        }
        puts("");
    }
}