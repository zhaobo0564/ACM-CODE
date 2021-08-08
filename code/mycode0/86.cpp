#include<bits/stdc++.h>
using namespace std;

const int N = 100007;
typedef long long ll;

struct power{
    int l, r;
}p[N];

int tree[4 * N];
int n, k, q;
ll sum[N];

#define m  (l + r) / 2
#define lson  2 * node
#define rson  2 * node + 1

int flag[4 * N];

bool cmp(power x, power y){
    return x.l < y.l;
}

void update(int pos, int l, int r, int node){
    tree[node]++;
    if(l == r)return;
    if(pos <= m) update(pos, l, m, lson);
    else update(pos, m + 1, r, rson);
}

int query(int k, int l, int r, int node){
    if(l == r)return l;
    if(tree[rson] >= k)return query(k, m + 1, r, rson);
    return query(k - tree[rson], l, m, lson);
}


int main(){
    while(~scanf("%d %d %d", &n, &k, &q)){
        for(int i = 1; i <= n; i++){
            ll x; scanf("%lld", &x);
            sum[i] = sum[i - 1] + x;
        }

        for(int i = 1; i <= q; i++){
            scanf("%d %d", &p[i].l, &p[i].r);
        }
        sort(p + 1, p + q + 1, cmp);
        for(int i = 1; i < k; i++){
            update(p[i].r, 1, n, 1);
        }
        ll ans = 0;
        for(int i = k; i <= q; i++){
            update(p[i].r, 1, n, 1);
            int r = query(k, 1, n, 1);
            ans = max(ans, sum[r] - sum[p[i].l - 1]);
        }
        printf("%lld\n", ans);
        memset(tree, 0, sizeof(tree));
    }
}