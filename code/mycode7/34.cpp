#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

int head[N];

struct edge{
    int to, nxt;
}e[4 * N];

int top = 1;
void add_adge(int u, int v) {
    e[top].to = v;
    e[top].nxt = head[u];
    head[u] = top++;
}

ll son[N], sz[N], a[N], all[N], color[N], ans[N], fa[N];

ll n;

void dfs(int u, int f) {
    sz[u] = 1;
    fa[u] = f;
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        if (to == f) continue;
        dfs(to, u);
        sz[u] += sz[to];
        if (sz[son[u]] < sz[to]) {
            son[u] = to;
        }
    }
}
int sum = 0;
void work(int v, int u, int f, int zson) {
    
   
    all[a[u]] -= v;
    if (all[a[u]] == 0 && color[a[u]]) {
        sum--;
    } else if (all[a[u]] && color[a[u]] == 0) {
        sum++;
    }
    color[a[u]] += v;
   
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        if (to == f || to == zson) {
            continue;
        }
        work(v, to, u, zson);
    }

}


void dfs1(int u, int f, int ok) {

    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        if (to == f || to == son[u]) {
            continue;
        }
        dfs1(to , u, 1);
      
    }

    if (son[u]) {
        dfs1(son[u], u, 0);
    }

    work(1, u, f, son[u]);
    ans[u] = sum;
    if (ok == 1) {
        work(-1, u, f, 0);
        sum = 0;
    } 


}

vector<pair<int, int> >cat;

int main() {
    while (~scanf("%d", &n)) {
        cat.clear();
        top = 1;
        for (int i = 0; i <= n; i++) {
            color[i] =0;
            son[i] = 0;
            all[i] = 0;
            head[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            all[a[i]]++;
        }

        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            add_adge(u, v);
            add_adge(v, u);
            cat.push_back({v, u});
        }

        dfs(1, 0);
        dfs1(1, 0, 0);
        for (auto it: cat) {
            if (fa[it.first] == it.second) {
                cout << ans[it.first] << endl;
            } else {
                cout << ans[it.second] << endl;
            }
        }
    }

    
    
}
