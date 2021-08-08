#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e6 + 7;

int n, a[N], q;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int cnt[N], vis[N], head[N], top = 1;

struct edge {
    int u, nxt;
} e[N];

void add_edge(int u, int v) {
    e[top].u = v;
    e[top].nxt = head[u];
    head[u] = top++;
}

int o = 1, id[N], cat[N], sz[N];

void dfs(int u) {
    id[u] = o++;
    cat[id[u]] = u;
    sz[u] = 1;
    for (int i = head[u]; i; i = e[i].nxt) {
        dfs(e[i].u);
        sz[u] += sz[e[i].u];
    }
}

int tree[4 * N];
#define m (l + r >> 1)
#define ls (node << 1)
#define rs (node << 1 | 1)

void build(int l, int r, int node) {
    if (l == r) {
        tree[node] = cat[l];
        return;
    }
    build(l, m, ls);
    build(m + 1, r, rs);
    tree[node] = max(tree[ls], tree[rs]);
}

int query(int ql, int qr, int l, int r, int node) {
   if (ql <= l && qr >= r) {
       return tree[node];
   }
   int ans = 0;
   if (ql <= m) ans = max(ans, query(ql, qr, l, m, ls));
   if (qr > m) ans = max(ans, query(ql, qr, m + 1, r, rs));
   return ans;
}



void update(int pos, int l, int r, int node) {
    if (l == r) {
        tree[node] = 0;
        return;
    }
    if (pos <= m) update(pos, l, m, ls);
    else update(pos, m + 1, r, rs);
    tree[node] = max(tree[ls], tree[rs]);
}

int du[N];



int main() {
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &du[i]);
    }
    nth_element(du + 1, du + 3, du + n + 1);
    for (int i = 1; i <= n; i++) {
        cout << du[i] << " ";
    }
    cout << endl;
    

}