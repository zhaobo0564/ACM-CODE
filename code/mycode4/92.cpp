#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
#define m (l + r) / 2

int  deep[N], fn[N][32];
vector<int>cat;

int head[N], cnt = 1, top = 1, rt[N];

struct edge{
    int to, nxt, w;
}e[2 * N];

struct hjt{
    int sum, l, r;
}tree[24 * N];
 int n, q;
void add_edge(int u, int v, int w){
    e[cnt].to = v;
    e[cnt].w = w;
    e[cnt].nxt = head[u];
    head[u] = cnt++;
}

int get_id(int x){
    return lower_bound(cat.begin(), cat.end(), x) - cat.begin() + 1;
}

void update(int pos, int last, int &now, int l, int r){
    now = top++;
    tree[now] = tree[last];
    tree[now].sum++;
    if(l ==  r)return;
    if(pos <= m) update(pos, tree[last].l, tree[now].l, l, m);
    else update(pos, tree[last].r, tree[now].r, m + 1, r);
}

int query(int k, int lc, int lc_fa, int u, int v, int l, int r){
    if(l == r){
        return tree[u].sum + tree[v].sum - tree[lc].sum - tree[lc_fa].sum;
    }
    int ans = 0;
    if(k <= m){
        ans += query(k, tree[lc].l, tree[lc_fa].l, tree[u].l, tree[v].l, l, m);
    }else{
        ans = tree[tree[u].l].sum + tree[tree[v].l].sum - tree[tree[lc].l].sum - tree[tree[lc_fa].l].sum;
        ans += query(k, tree[lc].r, tree[lc_fa].r, tree[u].r, tree[v].r, m + 1, r);
    }
    return ans;
}


void dfs(int u, int fa, int va){
    //cout <<u << endl;
    if(fa){
         int pos = get_id(va);
  //  cout <<"Pos " << pos << endl;
    update(pos, rt[fa], rt[u], 1, n);
    }
   
    
    deep[u] = deep[fa] + 1;
    fn[u][0] = fa;
    for(int i = 1; i < 32; i++){
        fn[u][i] = fn[fn[u][i - 1]][i - 1];
    }
    for(int i = head[u]; i; i = e[i].nxt){
        int to = e[i].to;
        int cost = e[i].w;
        if(to == fa)continue;
        dfs(to, u, cost);
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
    for(int i = 1; i < n; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        cat.push_back(w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    cat.push_back(0);
    sort(cat.begin(), cat.end());
    cat.erase(unique(cat.begin(), cat.end()), cat.end());
    dfs(1, 0, 0);
    while(q--){
        int u, v, k;
        scanf("%d %d %d", &u, &v, &k);
        int pos = get_id(k);
        if(cat[pos - 1] > k){
            pos--;
        }
        int lc = lca(u, v);
      //  cout << "lc " << lc << " lc_fa " << fn[lc][0] <<" " << pos << endl;
        int ans = query(pos, rt[lc], rt[lc], rt[u], rt[v], 1, n);
        printf("%d\n", ans);
    }
}