#include<bits/stdc++.h>
using namespace std;
const int N = 30007;
typedef long long ll;

struct hjt{
    int l, r;
    ll sum;
}tree[40 * N];

int n, q, rt[N], top = 1;
ll a[N];

#define m  (l + r) / 2

void update(ll v, int pos,int last, int &now, int l, int r){
    now = top++;
    tree[now] = tree[last];
    if(l == r){
        tree[now].sum = v;
        return;
    }
    if(pos <= m) update(v, pos, tree[last].l, tree[now].l, l, m);
    else update(v, pos, tree[last].r, tree[now].r, m + 1, r);
    tree[now].sum = tree[tree[now].l].sum + tree[tree[now].r].sum;
}

ll query(int now, int ql, int qr, int l, int r){
    if(ql <= l && qr >= r) return tree[now].sum;
    ll ans = 0;
    if(ql <= m) ans += query(tree[now].l, ql, qr, l, m);
    if(qr > m) ans += query(tree[now].r, ql, qr, m + 1, r);
    return ans;
}

map<ll, int>vis;

int main(){
    int t; scanf("%d", &t);
    while(t--){
        memset(rt, 0, sizeof(rt));
        vis.clear();
        top = 1;
        memset(tree, 0, sizeof(tree));
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%lld", &a[i]);
        }

        for(int i = 1; i <= n; i++){
            if(vis[a[i]] == 0){
                update(a[i], i, rt[i - 1], rt[i], 1, n);
                vis[a[i]] = i;
            }else{
                int temp;
                update(0, vis[a[i]], rt[i - 1], temp, 1, n);
                update(a[i], i, temp, rt[i], 1, n);
                vis[a[i]] = i;
            }
        }


        scanf("%d", &q);
        while(q--){
           int l, r;
           scanf("%d %d", &l, &r);
           ll ans = query(rt[r], l, r, 1, n);
           printf("%lld\n", ans);
        }
    }
}