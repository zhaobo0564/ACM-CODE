#include<bits/stdc++.h>
using namespace std;
const int N = 500007;
#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1
int n ,inde[N], num[N];

struct segement{
    int v, num;
}tree[4 * N];



void build(int l, int r, int node){
    tree[node].num = r - l + 1;
    if(l == r)return;
    build(l, m, lson);
    build(m + 1, r, rson);
}

void update(int pos, int v, int l, int r, int node){
    tree[node].num--;
    if(l == r){
        tree[node].v = v;
        return;
    }
    if(pos <= m ) update(pos, v, l, m, lson);
    else update(pos, v, m + 1, r, rson);
}

int query(int pos, int l, int r, int node){
    if(l == r)return l;
    if(tree[lson].num >= pos) return query(pos, l, m, lson);
    return query(pos - tree[lson].num, m + 1, r, rson);
}

void work(int l, int r, int node){
    if(l == r){
        printf("%d ", tree[node].v);
        return;
    }
    work(l, m, lson);
    work(m + 1, r, rson);
}


int main(){
    scanf("%d", &n);
    build(1, n, 1);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &inde[i], &num[i]);
    }
    for(int i = n; i; i--){
        int id = query(inde[i], 1, n, 1);
        update(id, num[i], 1, n, 1);
    }
    work(1, n, 1);
    puts("");


}