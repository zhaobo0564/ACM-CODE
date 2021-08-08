#include<bits/stdc++.h>
using namespace std;
const int N = 124514;
typedef long long ll;
int n, mm;
ll a[N], flag[4 * N];

#define lson 2 * node
#define rson 2 * node + 1
#define m (l + r) / 2


struct segement{
    ll v;
    ll maxn, minn;
}tree[4 * N];

void build(int l, int r, int node){
    if(l == r){
        tree[node].maxn = a[l];
        tree[node].maxn = a[l];
        tree[node].v = a[l];
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
    tree[node].maxn = max(tree[lson].maxn, tree[rson].maxn);
    tree[node].minn = min(tree[lson].minn, tree[rson].minn);
    tree[node].v = tree[lson].v + tree[rson].v;
}

void push_up(int node, int nl, int nr){
    if(flag[node]){
        tree[lson].v = flag[node] * 1ll*nl;
        tree[rson].v = flag[node] * 1ll* nr;
        tree[lson].maxn =  tree[rson].minn = flag[node];
        flag[lson] = flag[node];
        flag[rson] = flag[node];
        flag[node] = 0;
    }
}



void update(ll x, int ql, int qr, int l, int r, int node){
    if(ql <= l && qr >= r){
        if(tree[node].maxn == 1 && tree[node].minn == 1){
            return;
        }
        else if(tree[node].maxn == tree[node].minn){
            tree[node].v = __gcd(x, tree[node].maxn) * 1ll*(r - l + 1);
            tree[node].minn = tree[node].minn = __gcd(tree[node].maxn, x);
            flag[node] = __gcd(x, tree[node].maxn);
            return;
        }else if(l == r){
            tree[node].v = __gcd(tree[node].v, x);
            tree[node].maxn = tree[node].minn = tree[node].v;
            return;
        }
    }
    push_up(node, m - l + 1, r - m);
    if(ql <= m)update(x, ql, qr, l, m, lson);
    if(qr > m) update(x, ql, qr, m + 1, r, rson);
    tree[node].maxn = max(tree[lson].maxn, tree[rson].maxn);
    tree[node].minn = min(tree[lson].minn, tree[rson].minn);
    tree[node].v = tree[lson].v + tree[rson].v;
}

ll query(int ql, int qr, int l, int r, int node){
    if(ql <= l && qr >= r)return tree[node].v;
    ll ans = 0;
    push_up(node, m - l + 1, r - m);
    if(ql <= m) ans += query(ql, qr, l, m, lson);
    if(qr > m) ans += query(ql, qr, m + 1, r, rson);
    return ans;
}


int main(){
    scanf("%d %d", &n, &mm);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    build(1, n, 1);
    while(mm--){
        int op, l, r;
        scanf("%d %d %d", &op, &l, &r);
        if(op == 1){
            ll x;
            scanf("%lld", &x);
            update(x, l, r, 1, n, 1);
        }else{
            printf("%lld\n", query(l, r, 1, n, 1));
        }
    }
}

