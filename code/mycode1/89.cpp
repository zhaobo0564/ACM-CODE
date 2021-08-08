#include<iostream>
#include<stdio.h>
using namespace std;
const int N = 50007;

struct node{
    int lz, rz, maxn;
    int v, len;
}tree[4 * N];

int flag[4 * N];

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

void push_up(int node){
    if(tree[lson].len == tree[lson].lz){
        tree[node].lz = tree[lson].len + tree[rson].lz;
    }else{
        tree[node].lz = tree[lson].lz;
    }
    if(tree[rson].len == tree[rson].rz){
        tree[node].rz = tree[rson].len + tree[lson].rz;
    }else{
        tree[node].rz = tree[rson].rz;
    }
    tree[node].maxn = max(tree[node].lz, tree[node].rz);
    tree[node].maxn = max(tree[lson].maxn, tree[node].maxn);
    tree[node].maxn = max(tree[rson].maxn, tree[node].maxn);
    tree[node].maxn = max(tree[node].maxn, tree[lson].rz + tree[rson].lz);
}

void build(int l, int r, int node){
    tree[node].len = r - l + 1;
    flag[node] = -1;
    if(l == r){
        tree[node].lz = 1;
        tree[node].rz = 1;
        tree[node].maxn = 1;
        tree[node].v = 0;
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
    push_up(node);
}

void push_down(int node){
    if(flag[node] == 1){
       tree[lson].lz = tree[lson].rz = tree[lson].maxn = 0;
       tree[rson].lz = tree[rson].rz = tree[rson].maxn = 0;
       flag[lson] = flag[rson] = 1;
       flag[node] = -1;
    }
    else if(flag[node] == 0){
        tree[lson].lz = tree[lson].rz = tree[lson].maxn = tree[lson].len;
        tree[rson].lz = tree[rson].rz = tree[rson].maxn = tree[rson].len;
        flag[lson] = flag[rson] = 0;
        flag[node] = -1;
    }
}

void update(int v, int ql, int qr, int l, int r, int node){
    if(ql <= l && qr >= r){
        if(v == 1){
           // cout << "l == " << l << " r == " << r << endl;
            tree[node].lz = tree[node].maxn = tree[node].rz = 0;
        }else{
           //  cout << "l == " << l << " r == " << r << endl;
            tree[node].lz = tree[node].maxn = tree[node].rz = tree[node].len;
        }
        flag[node] = v;
        return;
    }
    push_down(node);
    if(ql <= m) update(v, ql, qr, l, m, lson);
    if(qr > m) update(v, ql, qr, m + 1, r, rson);
    push_up(node);
}

int query(int k, int l, int r, int node){
 //   cout << "k = " << k << " l = " << l << " r = "<< r << " maxn"<<  tree[node].maxn << endl;
    if(l == r)return l;
    push_down(node);
    if(tree[lson].maxn >= k) return query(k, l, m, lson);
    else if(tree[lson].rz + tree[rson].lz >= k)return m - tree[lson].rz + 1;
    else if(tree[rson].maxn >= k)return query(k, m + 1, r, rson);
    else return 0;
}

int main(){
    int n, mm;
    while(~scanf("%d %d", &n, &mm)){
        build(1, n, 1);
        while(mm--){
            int op, l, r;
            scanf("%d %d", &op, &l);
        // cout << op << endl;
            if(op == 1){
                int ans = query(l, 1, n, 1);
                printf("%d\n", ans);
                if(ans)update(1, ans, ans + l - 1, 1, n, 1);

            }else{
                scanf("%d", &r);
                update(0, l, l + r - 1, 1, n, 1);
            }
        }
    }
    
}
