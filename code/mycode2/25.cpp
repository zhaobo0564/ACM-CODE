#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int t, n;

struct node{
    int l, r, len, maxn;
    int value;
}tree[4 * N];

#define lson 2 * node
#define rson 2 * node + 1
#define m (l + r) / 2

void push_up(int node){
    if(tree[lson].len == tree[lson].l){
        tree[node].l = tree[lson].l + tree[rson].l;
    }else{
        tree[node].l = tree[lson].l;
    }

    if(tree[rson].r == tree[rson].len){
        tree[node].r = tree[rson].r + tree[lson].r;
    }else{
        tree[node].r = tree[rson].r;
    }
    tree[node].maxn = max(tree[lson].maxn, tree[rson].maxn);
    tree[node].maxn = max(tree[node].maxn, tree[lson].r + tree[rson].l);
}



void build(int l , int r, int node){
    tree[node].l = tree[node].r = tree[node].maxn = tree[node].len = r - l + 1;
    if(l == r){
        
        tree[node].value = 0;
        return;
    } 
    build(l, m, lson);
    build(m + 1, r, rson);
}


int query(int k, int l, int r, int node){
    if(l == r)return l;
    int ans = 0;
    if(tree[lson].maxn >= k) ans = query(k, l, m, lson);
    else if(tree[lson].r + tree[rson].l >= k) return m - tree[lson].r + 1;
    else if(tree[rson].maxn >= k)ans = query(k, m + 1, r, rson);
    return ans; 
}

void update(int v, int pos, int l, int r, int node){
    if(l == r){
        tree[node].value = v;
        tree[node].maxn = 0;
        tree[node].l = tree[node].r = 0;
        return;
    }
    if(pos <= m) update(v, pos, l, m, lson);
    else update(v, pos, m + 1, r, rson);
    push_up(node);
}

void out(int l, int r, int node){
    if(l == r){
        printf("%d ", tree[node].value);
        return;
    }
    out(l, m, lson);
    out(m + 1, r, rson);
}

void clear(int l, int r, int node){
    tree[node] = {0, 0, 0, 0, 0};
    if(l == r)return;
    clear(l, m, lson);
    clear(m + 1, r, rson);
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        build(1, n, 1);
        for(int i = 1; i <= n; i++){
            int maxn = tree[1].maxn;
            int l = query(maxn, 1,n, 1);
            int r = l + maxn - 1;
            int pos;
            if((r - l + 1) % 2 == 0){
                pos = (l + r - 1) / 2;
            }else{
                pos = (l + r) / 2;
            }
            update(i, pos, 1, n, 1);
        }
        out(1, n, 1);
        clear(1, n, 1);
        puts("");

    }
}