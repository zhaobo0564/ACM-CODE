#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int n, q;

typedef long long ll;

ll a[N];
vector<ll>v;
vector<int> g[N];

#define m (l + r) / 2

struct hjt{
    int sum, l, r;
}tree[24 * N];

int father[N], top = 1, rt[N], deep[N], fn[N][32];

int get_id(ll x){
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

void update(int pos, int last, int &now, int l, int r){
    now = top++;
    tree[now] = tree[last];
    tree[now].sum++;
    if(l == r)return;
    if(pos <= m) update(pos, tree[last].l, tree[now].l, l, m);
    else update(pos, tree[last].r, tree[now].r, m + 1, r);
}

int query(int k, int last_fa, int last, int now, int now1, int l, int r){
    if(l == r)return l;
    int sum = tree[tree[now].l].sum + tree[tree[now1].l].sum - tree[tree[last].l].sum - tree[tree[last_fa].l].sum;
    if(sum >= k) return query(k, tree[last_fa].l, tree[last].l, tree[now].l, tree[now1].l, l, m);
    return query(k - sum, tree[last_fa].r, tree[last].r, tree[now].r, tree[now1].r, m + 1, r);
}






void dfs(int u, int fa){
    father[u] = fa;
    int pos = get_id(a[u]);
    deep[u] = deep[fa] + 1;
    fn[u][0] = fa;
    for (int i = 1; i < 32;i++){
        fn[u][i] = fn[fn[u][i - 1]][i - 1];
    }

    update(pos, rt[fa], rt[u], 1, n);
    for(int to: g[u]){
        if(to == fa)continue;
        dfs(to, u);

    }
}
int lca(int x,int y){
    if(deep[x]<deep[y]){
        swap(x, y);
    }
    int d = deep[x] - deep[y];
    for (int i = 0; i < 32;i++){
        if(d&1){
            x = fn[x][i];
        }
        d = d / 2;
    }
    if(x==y){
        return x;
    }
    for (int i = 31; i >= 0;i--){
        int tox = fn[x][i];
        int toy = fn[y][i];
        if(tox==0){
            continue;
        }
        if(tox!=toy){
            x = tox;
            y = toy;
        }
    }
    return fn[x][0];
}




int main(){
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i = 1; i < n; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    ll ans = 0;
    while(q--){
        int u, vv, k;
        scanf("%d %d %d", &u, &vv, &k);
        u = u ^ ans;
        int lc = lca(u, vv);
        int res = query(k, rt[father[lc]], rt[lc], rt[u], rt[vv], 1, n);
        printf("%lld\n", v[res - 1]);
        ans = v[res - 1];
    }


}