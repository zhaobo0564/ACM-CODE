#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
typedef long long ll;

ll tree[4 * N], n, mm, p;
ll add[4 * N], mul[4 * N], re[4 * N];

#define lson 2 * node
#define rson 2 * node + 1
#define m (l + r) / 2

void push_up(int node){
     tree[node] = (tree[lson] + tree[rson]) % p;
}

void push_down(int node, ll nl, ll nr){
    // if(re[node] != -1){
    //     tree[rson] = (re[node] %p * nl %p) % p;
    //     tree[lson] = (re[node]%p * nr %p) % p;
    //     re[lson] = re[rson] = re[node];
    //     re[node] = -1;
    //     mul[node] = 1;
    //     add[node] = 0;
    // }
    if(add[node] || mul[node] != 1){
		mul[lson] = ((mul[lson] % p ) * ( mul[node] % p)) % p;
		mul[rson]=((mul[rson]%p)*(mul[node]) % p ) % p;
		add[lson]=(add[lson]*mul[node]+add[node])%p;
		add[rson]=(add[rson]*mul[node]+add[node])%p;
		tree[lson]=(((tree[lson]%p)*(mul[node]%p))%p+add[node]*nl%p)%p;
		tree[rson]=(((tree[rson]%p)*(mul[node]%p))%p+add[node]*nr%p)%p;
		mul[node]=1,add[node]=0;

	}
}

void update(int pos , ll v, int l, int r, int node){
    if(l == r){
        tree[node] += v;
        tree[node] %= p;
        return;
    }
    push_down(node, m - l + 1, r - m);
    if(pos <= m) update(pos, v, l, m , lson);
    else update(pos, v, m + 1, r, rson);
    push_up(node);
}

void update_add(ll v, int ql, int qr, int l, int r, int node){
    if(ql <= l && qr >= r){
        tree[node] = (tree[node] + v * 1ll * (r - l + 1)) % p;
        add[node] = (add[node] + v) % p;
        return;
    }
     push_down(node, m - l + 1, r - m);
    if(ql <= m) update_add(v, ql, qr, l, m, lson);
    if(qr > m) update_add(v, ql, qr, m + 1, r, rson);
    push_up(node);
}

void update_mul(ll v, int ql, int qr, int l, int r, int node){
    if(ql <= l && qr >= r){
        tree[node] = (tree[node] % p * v % p) % p;
        mul[node] = (mul[node] %p * v %p) % p;
        add[node] = (add[node] %p * v % p) % p;
        return;
    }
     push_down(node, m - l + 1, r - m);
    if(ql <= m) update_mul(v, ql, qr, l, m, lson);
    if(qr > m) update_mul(v, ql, qr, m + 1, r, rson);
    push_up(node);
}

void update_re(ll v, int ql, int qr, int l, int r, int node){
    if(ql <= l && qr >= r){
        tree[node] = (v % p) * 1ll*(r - l + 1) % p;
        re[node] = v;
        add[node] = 0;
        mul[node] = 1;
        return; 
    }
     push_down(node, m - l + 1, r - m);
    if(ql <= m) update_re(v, ql, qr, l, m, lson);
    if(qr > m) update_re(v, ql, qr,m + 1, r, rson);
    push_up(node);
}

ll query(int ql, int qr, int l, int r, int node){
    if(ql <= l && qr >= r){
        return tree[node];
    }
    ll ans = 0;
     push_down(node, m - l + 1, r - m);
    if(ql <= m) ans = (ans + query(ql, qr, l, m, lson)) % p;
    if(qr > m) ans = (ans + query(ql, qr, m + 1, r, rson)) % p;
    return ans % p;
}

int main(){
    scanf("%lld %lld %lld", &n, &mm, &p);
    for(int i = 0; i < 4 * N; i++){
        mul[i] = 1;
        add[i] = 0;
        re[i] = -1;
    }
    int maxn = n + mm + 1;
    for(int i = 1; i <= n; i++){
        ll x; scanf("%lld", &x);
        update(i, x, 1, maxn, 1);
    }
    while(mm--){
        int op, l, r;
        ll k;
        scanf("%d", &op);
        if(op == 1){
            scanf("%d %d %lld", &l, &r, &k);
            update_add(k, l, r, 1, maxn, 1);
        }else if(op == 2){
            scanf("%d %d %lld", &l, &r, &k);
            update_mul(k, l, r, 1, maxn, 1);
        }else if(op == 3){
            scanf("%d %d %lld", &l, &r, &k);
            //update_re(k, l, r, 1, maxn, 1);
            update_mul(0, l, r, 1, maxn, 1);
            update_add(k, l, r, 1, maxn, 1);
        }else if(op == 4){
            scanf("%lld", &k);
            update(n + 1, k, 1, maxn, 1);
            n++;
        }else{
            scanf("%d %d", &l, &r);
            printf("%lld\n", query(l, r, 1, maxn, 1) % p);
        }


    }
}
