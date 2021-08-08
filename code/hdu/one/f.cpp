#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 7;

struct segement {
    int sum, l, r;
    int count;
}tree[60 * N];

vector<int> G[N];
vector<int> mp[N];





int n, mm, q, top = 1, rt[N], a[N];


#define m (l + r) / 2




void up(int v, int pos, int l, int r, int &node) {
    if (pos > r) return;
    if (!node) node = top++;
    if (l == r) {
        tree[node].count += v;
        if (tree[node].count > 0) {
            tree[node].sum = 1;
        } else {
            tree[node].sum = 0;
        }
        return;
    }
    if (pos <= m) up(v, pos, l, m, tree[node].l);
    else  up(v, pos, m + 1, r, tree[node].r);
    tree[node].sum = tree[tree[node].l].sum + tree[tree[node].r].sum;


}

int query(int l, int r, int node) {
    if (l == r) return l;
    if ((m - l + 1) > tree[tree[node].l].sum) {
        return query(l, m, tree[node].l);
    } else {
        return query(m + 1, r, tree[node].r);
    }

}

int du[N];

vector<int>num[N];


int main() {
 

    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &mm);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        top = 1;
        for (int i = 1; i <= n; i++) {
            G[i].clear();
            mp[i].clear();
            du[i] = 0;
            rt[i] = 0;
            num[i].clear();
        }
        for (int i = 1; i <= mm; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
         int block = (int)sqrt(n);

        for (int i = 1; i <= n; i++) {
            sort(G[i].begin(), G[i].end());
            G[i].erase(unique(G[i].begin(), G[i].end()), G[i].end());
            du[i] = G[i].size();
        }

        for (int i = 1; i <= n; i++) {
            for (int to: G[i]) {
                if (du[to] >= block) {
                    mp[i].push_back(to);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (du[i] >= block) {
                num[i].resize(du[i] + 2);
                for (int to: G[i]) {
                    if (a[to] <= du[i]) {
                        if (++num[i][a[to]] == 1)
                            up(1, a[to], 0, du[i], rt[i]);
                    }
                   
                    
                }
            }
        }

        int q; scanf("%d", &q);
        while (q--) {
            int op; scanf("%d", &op);
            if (op == 1) {
                int u, x; scanf("%d %d", &u, &x);
                if (a[u] == x) continue;
                for (int to: mp[u]) {
                    if (a[to] <= du[to]) {
                        if ((--num[to][a[u]]) == 0)
                            up(-1, a[u], 0, du[to], rt[to]);
                    }
                    if (x <= du[to]) {
                        if (++num[to][x] == 1)
                            up(1, x, 0, du[to], rt[to]);
                    }
                    
                }
                a[u] = x;
            } else {
                int u; scanf("%d", &u);
                if (du[u] >= block) {
                    int ans = query(0, du[u], rt[u]);
                    printf("%d\n", ans);
                } else {
                    vector<int> v;
                    v.resize(400);
                    for (int to: G[u]) {
                        if (a[to] >= 400) continue;
                        v[a[to]]++;
                    }
        
                    int ans = 0;
                    for (int i = 0; i < 400; i++) {
                        if (v[i] == 0) {
                            ans = i;
                            break;
                        }
                    }
                    printf("%d\n", ans);
                }
            }
        }
        for (int i = 0; i <= top; i++) {
            tree[i].count = tree[i].l = tree[i].r = tree[i].sum = 0;
        }

       
    }
}