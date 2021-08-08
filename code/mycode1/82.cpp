#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int tree[4 * N], flag[4 * N], n, mm;

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

struct node{
    int l, r, v;
}p[N];


void push_down(int node){
    if(flag[node]){
        tree[lson] |= flag[node];
        tree[rson] |= flag[node];
        flag[lson] |= flag[node];
        flag[rson] |= flag[node];
        flag[node] = 0;
    }
}

void update(int v, int ql, int qr, int l, int r, int node){
    if(ql <= l && qr >= r){
        tree[node] |= v;
        flag[node] |= v;
        return;
    }
    push_down(node);
    if(ql <= m) update(v, ql, qr, l, m, lson);
    if(qr > m) update(v, ql, qr, m + 1, r, rson);
    tree[node] = tree[lson] & tree[rson];
}

int query(int ql, int qr, int l, int r, int node){
    if(ql <= l && qr >= r){
        return tree[node];
    }
    int ans = (1 << 30 ) - 1;
    push_down(node);
    if(ql <= m) ans &= query(ql, qr, l, m, lson);
    if(qr > m) ans &= query(ql, qr, m + 1, r, rson);
    return ans;
}

void print(int l, int r, int node){
    if(l == r){
        printf("%d ", tree[node]);
        return;
    }
    push_down(node);
    print(l, m, lson);
    print(m + 1, r, rson);
}

int main(){
    scanf("%d %d", &n, &mm);
    for(int  i = 1; i <= mm; i++){
        scanf("%d %d %d", &p[i].l, &p[i].r, &p[i].v);
        update(p[i].v, p[i].l, p[i].r, 1, n, 1);
    }
    
    for(int i = 1; i <= mm; i++){
        if(query(p[i].l, p[i].r, 1, n, 1) != p[i].v){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    print(1, n, 1);



}