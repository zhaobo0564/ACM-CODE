#include<bits/stdc++.h>
using namespace std;
#define m (l + r) / 2
const int N = 1e6 + 7;

struct hjt {
    int l, r, sum;
}tree[30 * N];

int id[N], cnt = 1, a[N], n, q, cat[N], top = 1, rt[N];

vector<int> g[N];
int fa[N][23], deep[N];

void dfs(int u, int f, int d) {
    fa[u][0] = f;
    deep[u] = d;
    for (int i = 1; i <= 20; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];   
    }
    for (int to: g[u]) {
        if (to == f) continue;
        dfs(to, u, d + 1);
    }
}

bool vis[N];
queue<int> Q;
void bfs() {
    
    Q.push(1);
    
    while (Q.size()) {
        int cd = Q.front();
        Q.pop();
        if (vis[cd]) continue;
        vis[cd] = 1;
        cat[cnt] = cd;
        id[cd] = cnt++;
        for (int to: g[cd]) {
            Q.push(to);
        }   
    }

}

int update(int pos, int l, int r, int last) {
    int now = top++;
    tree[now] = tree[last];
    tree[now].sum++;
    if (l == r) {
        return now;
    }
    if (pos <= m) {
        tree[now].l  = update(pos, l, m, tree[last].l);
    } else {
        tree[now].r = update(pos, m + 1, r, tree[last].r);
    }
    return now;
} 

int query(int k, int l, int r, int last, int now) {
    if (l == r) return l;
    int sum = tree[tree[now].l].sum - tree[tree[last].l].sum;
    if (k <= sum) {
        return query(k, l, m, tree[last].l, tree[now].l);
    } else {
        return query(k - sum, m + 1, r, tree[last].r, tree[now].r);
    }
}

bool judge(int u, int f, int d) {
    for (int i = 0; i <= 20; i++) {
        if (d & 1) {
            u = fa[u][i];
        }
        d = d / 2;
    }
    return u == f;
}

int get_l(int f, int d, int r) {
    int l = id[g[deep[cat[r]]][0]];
    int ans;
    while (l <= r) {
        if (judge(cat[m], f, d)) {
           ans = m; 
           r = m - 1;
            
        } else {
            l = m + 1;
        }
    }
    return ans;
}

int get_r(int f, int d, int l) {
    int r = id[g[deep[cat[l]]][g[deep[cat[l]]].size() - 1]];
    int ans = 0;
    while (l <= r) { 
        if (judge(cat[m], f, d)) {
           
            ans = m;   
            l = m + 1;
            
        } else {
            r = m - 1;
        }
    }
    return ans;
}


int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }
    dfs(1, 0, 0);
    bfs();
    
    for (int i = 1; i < cnt; i++) {
        rt[i] = update(a[cat[i]], 1, n, rt[i - 1]);
    }
    for (int i = 0; i <= n; i++) {
        g[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        g[deep[i]].push_back(i);
    }
    int lastans = 0;
    while (q--) {
        int l, r; scanf("%d %d", &l, &r);
        l = (l ^ lastans) % n + 1;
        int f = l, d = r;
        for (int i = 0; i <= 20; i++) {
            if (d & 1) {
                f = fa[f][i];
            }
            d = d / 2;
        }
        if (f == 0) {
            puts("?");
         
        } else {
            int k = r;
      
            int L = l;
            l = get_l(f, k, id[l]);
            r = get_r(f, k, id[L]);
            if (l > r)continue;
        
            if (tree[rt[r]].sum - tree[rt[l - 1]].sum < k) {
                puts("?");

            }  else {
                int ans = query(k, 1, n, rt[l - 1], rt[r]);
                lastans = ans;
                printf("%d\n", ans); 
            }
           
        }

        
        
    }
}

