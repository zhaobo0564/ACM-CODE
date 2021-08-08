#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
struct hjt{
    int sum, l, r;
}tree[24 * N];

int n, mm, h[N], top, rt[N];
#define m ((l + r) >>1)

void update(int v, int last, int &now, int l, int r){
    now = ++top;
    tree[now] = tree[last];
    tree[now].sum += 1;
    if(l == r)return;
    if(v <= m) update(v, tree[last].l, tree[now].l, l, m);
    else update(v, tree[last].r, tree[now].r, m + 1, r);
}

int query(int k, int last, int now, int l, int r){
    if(l == r)return l;
    int sum = tree[tree[now].l].sum - tree[tree[last].l].sum;
    if(sum >= k) return query(k, tree[last].l, tree[now].l, l, m);
    return query(k - sum, tree[last].r, tree[now].r, m + 1, r);
}
vector<int>g;

int get_id(int x){
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &h[i]);
        g.push_back(h[i]);
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    for(int i = 1; i <= n; i++){
        update(get_id(h[i]), rt[i - 1], rt[i], 1, n);
    }
    scanf("%d", &mm);
    while(mm--){
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        printf("%d\n", g[query(r - l + 1 - k + 1, rt[l - 1], rt[r], 1, n) - 1]);
    }
}