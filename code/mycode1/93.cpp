#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int  n, mm, rt[N], top = 1, a[N];

struct hjt{
    int sum, l, r;
}tree[19 * N];

#define m  ((l + r) >> 1)

void update(int v, int last, int &now, int l, int r){
    now = top++;
    tree[now] = tree[last];
    tree[now].sum += 1;
    if(l == r)return;
    if(v <= m)update(v, tree[last].l, tree[now].l, l, m);
    else update(v, tree[last].r, tree[now].r, m + 1, r);
}tyhg

int query(int k, int last, int now, int l, int r){
    if(l == r){
        return l;
    }
    int sum = tree[tree[now].l].sum - tree[tree[last].l].sum;
    if(sum >= k) return query(k, tree[last].l, tree[now].l , l, m); 
    return query(k - sum, tree[last].r, tree[now].r, m + 1, r);
}

vector<int>g;

int get_id(int x){
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

int main(){
    scanf("%d %d", &n, &mm);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        g.push_back(a[i]);
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    for(int i = 1; i <= n; i++){
        int x = get_id(a[i]);
        update(x, rt[i - 1], rt[i], 1, n);
    }
    while(mm--){
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        int ans = g[query(k, rt[l - 1], rt[r], 1, n) - 1];
        printf("%d\n", ans);   
    }

}