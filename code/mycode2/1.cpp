#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
struct hjt{
    int lz, rz, maxn, len;
    int lson, rson;
    hjt(){
        lz = rz = maxn = len = lson = rson = 0;
    }
}tree[24 * N];

struct node{
    int v, pos;
}p[N];

bool cmp(node x, node y){
    return x.v > y.v;
}

int n, mm, top, rt[N];

#define m (l + r) / 2
#define ls tree[now].lson
#define rs tree[now].rson
 
void push_up(int now){
    tree[now].len = tree[ls].len + tree[rs].len;
    if(tree[ls].len == tree[ls].lz){
        tree[now].lz = tree[ls].len + tree[rs].lz;
    }else{
        tree[now].lz = tree[ls].lz;
    }
    if(tree[rs].len == tree[rs].rz){
        tree[now].rz = tree[rs].len + tree[ls].rz;
    }else{
        tree[now].rz = tree[rs].rz;
    }
    tree[now].maxn = max(tree[ls].maxn, tree[rs].maxn);
    tree[now].maxn = max(tree[now].maxn, tree[ls].rz + tree[rs].lz);
    
}

void update(int pos, int last, int &now, int l, int r){
    now = ++top;
    tree[now] = tree[last];
    if(l == r){
        tree[now].lz = tree[now].rz = tree[now].maxn = tree[now].len = 1;
        return;
    }
    if(pos <= m) update(pos, tree[last].lson, tree[now].lson, l, m);
    else update(pos, tree[last].rson, tree[now].rson, m + 1, r);
    push_up(now);
}

hjt merg(hjt a, hjt b){
    if(a.len == 0)return b;
    hjt c;
    if(a.len == a.lz){
        c.lz = a.len + b.lz;
    }else{
        c.lz = a.lz;
    }
    if(b.len == b.rz){
        c.rz = b.len + a.rz;
    }else{
        c.rz = b.rz;
    }
    c.maxn = max(a.maxn, b.maxn);
    c.maxn = max(c.maxn, a.rz + b.lz);
    return c;
}

hjt query(int ql, int qr, int now, int l, int r){
    if(ql <= l && qr >= r){
        return tree[now];
    }
    hjt ans;
    if(ql <= m) ans = merg(ans, query(ql, qr, tree[now].lson, l, m));
    if(qr > m) ans = merg(ans, query(ql, qr, tree[now].rson, m + 1, r));
    return ans;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &p[i].v);
        p[i].pos = i;
    }
    sort(p + 1, p + n + 1, cmp);
    for(int i = 1; i <= n; i++){
        update(p[i].pos, rt[i - 1], rt[i], 1, n);
    }
    scanf("%d", &mm);
    while(mm--){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int l = 1, r = n;
        int ans;
        while(l <= r){
            int mid = (l + r) / 2;
            hjt res = query(l, r, rt[mid], 1, n);
            cout << res.maxn << " " << mid << endl;
            if(res.maxn >= c){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        printf("%d\n", ans);
    }
}