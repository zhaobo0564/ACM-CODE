#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;
ll tree[4 * N];
ll sum[4 * N];
ll flag[4 * N];
ll down[ 4 * N];
ll vis[4 * N];
ll lazy[4 * N];

int n, q;

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

void push_down(int node, int nl, int nr){
    if(flag[node]){
        sum[lson] +=  flag[node] * nl;
        sum[rson] +=  flag[node] * nr;
        tree[lson] = lazy[node];
        tree[rson] = lazy[node] ;
        flag[lson] += flag[node];
        flag[rson] += flag[node];
        lazy[lson] = lazy[rson] = lazy[node];
        lazy[node] = 0;
        flag[node] = 0;
        
    }
}

void build(int l, int r, int node){
    if(l == r){
        tree[node] = l;
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);

}



void update(int x, int ql, int qr, int l, int r, int node){
    if(ql <= l && qr >= r){
        if(tree[node]){
            sum[node] += abs(1ll*x  - tree[node]) * 1ll* (r - l + 1);
            flag[node] += abs(1ll*x - (tree[node] ));
            lazy[node] = x;
            tree[node] = lazy[node];
            return;
        }
    }
    push_down(node, m - l + 1, r - m);
    if(ql <= m) update(x, ql, qr, l, m, lson);
    if(qr > m) update(x, ql, qr, m + 1, r, rson);
    sum[node] = sum[lson] + sum[rson];
    if(tree[lson] == tree[rson])tree[node] = tree[lson];
    else tree[node] = 0;

}

ll query(int ql, int qr, int l, int r, int node){
    if(ql <= l && qr >= r)return sum[node];
    ll ans = 0;
    push_down(node, m - l + 1, r - m);
    if(ql <= m) ans += query(ql, qr, l, m, lson);
    if(qr > m) ans += query(ql, qr, m + 1, r, rson);
    return ans;
}

int main(){
    scanf("%d %d", &n, &q);
    build(1, n, 1);
    while(q--){
        int op, l, r, x;
        scanf("%d %d %d", &op, &l, &r);
        if(op == 1){
            scanf("%d", &x);
            update(x, l, r, 1, n, 1);
        }else{
            printf("%lld\n", query(l, r, 1, n, 1));
        }
    }
}