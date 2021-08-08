#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 1e5 + 7;

struct hjt{
    int sum, l, r;
}tree[24 * N];

int top = 1, rt[N], a[N];
#define m (l + r) / 2

void update(int pos, int last, int &now, int l, int r){
    now = top++;
    tree[now] = tree[last];
    tree[now].sum++;
    if(l == r)return;
    if(pos <= m) update(pos, tree[last].l, tree[now].l, l, m);
    else update(pos, tree[last].r, tree[now].r, m + 1, r);
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
    int n, q; scanf("%d %d", &n, &q);
   
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        g.push_back(a[i]);
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    n = g.size();
    for(int i = 1; i <= n; i++){
        int pos = get_id(a[i]);
        update(pos, rt[i - 1], rt[i], 1, n);
    }
    while(q--){
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        printf("%d\n", g[query(k, rt[l - 1], rt[r], 1, n) - 1]);
    }

    

}