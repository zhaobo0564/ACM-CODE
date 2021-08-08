#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;
int n, mm;
ll tree[4 * N];
ll maxn[4 * N];
#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

void build(int l, int r, int node){
    if(l == r){
        scanf("%lld", &tree[node]);
        maxn[node] = tree[node];
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
    tree[node] = tree[lson] + tree[rson];
    maxn[node] = max(maxn[lson], maxn[rson]);
}

void push(int x, int l, int r, int node){
    if(maxn[node] < x)return;
    if(l == r){
        tree[node] %= x;
        maxn[node] = tree[node];
        return;
    }
    push(x, l, m, lson);
    push(x, m + 1, r, rson);
    tree[node] = tree[lson] + tree[rson];
    maxn[node] = max(maxn[lson], maxn[rson]);

}

void update(int x, int ql, int qr, int l, int r, int node){
    if(ql <= l && qr >= r){
        push(x, l, r, node);
        return;
    }
    if(ql <= m)update(x, ql, qr, l, m, lson);
    if(qr > m)update(x, ql, qr, m + 1, r, rson);
    tree[node] = tree[lson] + tree[rson];
    maxn[node] = max(maxn[lson], maxn[rson]);
}

ll query(int ql, int qr, int l, int r, int node){
    if(ql <= l && qr >= r)return tree[node];
    ll ans = 0;
    if(ql <= m) ans += query(ql, qr, l, m, lson);
    if(qr > m) ans += query(ql, qr, m + 1, r, rson);
    return ans;
}

void update(int pos, int x, int l, int r, int node){
    if(l == r){
        tree[node] = x;
        maxn[node] = x;
        return;
    }
    if(pos <= m)update(pos, x, l, m, lson);
    else update(pos, x, m + 1, r, rson);
    tree[node] = tree[lson] + tree[rson];
    maxn[node] = max(maxn[lson], maxn[rson]);
}

int main(){
    scanf("%d %d", &n, &mm);
    build(1, n, 1);
    while(mm--){
        int op;
        scanf("%d", &op);
        if(op == 1){
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%lld\n", query(l, r, 1, n, 1));
        }else if(op == 2){
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            update(x, l, r, 1, n, 1);
        }else{
            int l, x;
            scanf("%d %d", &l, &x);
            update(l, x, 1, n, 1);
        }
    }
    
}