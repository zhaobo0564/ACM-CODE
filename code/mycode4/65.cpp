#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

struct segement{
   long long maxn, minn, sum;
   int l;
}tree[4 * N];

void build(int l, int r, int node){
    if(l == r){
        scanf("%lld", &tree[node].maxn);
        tree[node].minn = tree[node].maxn;
        tree[node].sum = 1;
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
    tree[node].maxn = max(tree[lson].maxn, tree[rson].maxn);
    tree[node].minn = min(tree[lson].minn, tree[rson].minn);
    tree[node].sum = tree[lson].sum + tree[rson].sum;
}

void update(int pos, int l, int r, int node){
    if(l == r){
        tree[node].maxn = INT_MIN;
        tree[node].minn = INT_MAX;
        tree[node].sum = 0;
        return;
    }
    if(pos <= m)update(pos, l, m, lson);
    else update(pos, m + 1, r, rson);
    tree[node].maxn = max(tree[lson].maxn, tree[rson].maxn);
    tree[node].minn = min(tree[lson].minn, tree[rson].minn);
    tree[node].sum = tree[lson].sum + tree[rson].sum;
}



long long maxn = INT_MIN, minn = INT_MAX;

void query_max(int ql, int qr, int l, int r, int node){
    if(ql <= l && qr >= r){
        maxn = max(maxn, tree[node].maxn);
        minn = min(minn, tree[node].minn);
        return;
    }
    if(ql <= m)query_max(ql, qr, l, m, lson);
    if(qr > m)query_max(ql, qr, m + 1, r, rson);
}

int query(int k, int l, int r, int node){
    if(l == r)return l;
    if(k > tree[lson].sum) return query(k - tree[lson].sum, m + 1, r, rson);
    return query(k, l, m, lson);
}



int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    build(1, n, 1);
    while(q--){
        int op;
        scanf("%d", &op);
        if(op == 1){
            int pos; scanf("%d", &pos);
            int l = query(pos, 1, n, 1);
            update(l, 1, n, 1);
           
        }else if(op == 2){
            int l, r;
            scanf("%d %d", &l, &r);
            l = query(l, 1, n, 1);
            r = query(r, 1, n, 1);
            maxn = INT_MIN;
            minn = INT_MAX;
            query_max(l, r, 1, n, 1);
            printf("%lld %lld\n", minn, maxn);
           
        }
    }
}