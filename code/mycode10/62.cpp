#include<bits/stdc++.h>
using namespace std;
#define m (l + r) / 2
#define int long long
const int N = 2e5 + 7;

int n;

int tree[40 * N], ls[40 * N], rs[40 * N], rt[4 * N];

int top = 1;
void update(int pos, int l, int r, int &node) {
    if (!node) node = top++;
    tree[node]++;
    if (l == r) {
        return;
    }
    if (pos <= m) 
        update(pos, l, m, ls[node]);
    else
        update(pos, m + 1, r, rs[node]); 
}

int sum[10 * N], ans = 0;

int merge(int x, int y, int l, int r) {
    if (!x) return y;
    if (!y) return x;
    if (l == r) {
        tree[x] += tree[y];
        return x;
    }
    ls[x] = merge(ls[x], ls[y], l, m);
    rs[x] = merge(rs[x], rs[y], m + 1, r);
    tree[x] = tree[ls[x]] + tree[rs[x]];
    return x;
}

int work(int x, int y, int l, int r) {
    if (!x) return 0;
    if (!y) return 0;
    int ans = 0;
    ans += tree[rs[x]] * tree[ls[y]];
    //cout << "val = " << tree[rs[x]] * tree[ls[y]] << endl;
    if (l == r) {
        return ans;
    }
    ans += work(ls[x], ls[y], l, m);
    ans += work(rs[x], rs[y], m + 1, r);
    
    return ans;
    
}
int cnt = 1;

int lson[20 * N], rson[20 * N], a[20 * N];

void dfs(int &u) {
    u = cnt++;
    scanf("%d", &a[u]);

    if (a[u]) {
        update(a[u], 1, N, rt[u]);
        return;
    } 
    dfs(lson[u]);
    dfs(rson[u]);
    int ans = min(work(rt[lson[u]], rt[rson[u]], 1, N), work(rt[rson[u]], rt[lson[u]], 1, N));
   // cout << "u = " << u << " " << ans << endl; 
    rt[u] = rt[lson[u]];
    rt[u] = merge(rt[u], rt[rson[u]], 1, N);
    sum[u] = ans + sum[lson[u]] + sum[rson[u]];
   
}

int32_t main() {
    scanf("%lld", &n);
    int RT = 0;
    dfs(RT);
   // cout << tree[rt[3]] << endl;
    cout << sum[1] << endl;
    

}