#include<bits/stdc++.h>
using namespace std;

const int N = 5e4 + 7;

int  n, mm, flag[4 * N];

struct node{
    int l, r, len, maxn;
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

void push_down(int node){
    if(flag[node] == 1){
        tree[rson].l = tree[rson].r = tree[rson].maxn = tree[rson].len;
        tree[lson].l = tree[lson].r = tree[lson].maxn = tree[lson].len;
        flag[lson] = flag[node];
        flag[rson] = flag[node];
        flag[node] = 0;
    }else if(flag[node] == -1){
        tree[rson].l = tree[rson].r = tree[rson].maxn = 0;
        tree[lson].l = tree[lson].r = tree[lson].maxn = 0;
        flag[lson] = flag[node];
        flag[rson] = flag[node];
        flag[node] = 0;
    }
}

void build(int l , int r, int node){
    tree[node].l = tree[node].r = tree[node].maxn = tree[node].len = r - l + 1;
    if(l == r) return;
    build(l, m, lson);
    build(m + 1, r, rson);
}


int query(int k, int l, int r, int node){
   // cout << "l=" << l << "r = " << r << " " << tree[node].maxn<< " " << tree[node].l << " " << tree[node].r << endl;
    if(l == r)return l;
    int ans = 0;
    push_down(node);
    if(tree[lson].maxn >= k) ans = query(k, l, m, lson);
    else if(tree[lson].r + tree[rson].l >= k) return m - tree[lson].r + 1;
    else if(tree[rson].maxn >= k)ans = query(k, m + 1, r, rson);
    return ans; 
}

void update(int ok, int ql, int qr, int l, int r, int node){
    if(ql > qr )return;
    if(ql <= l && qr >= r){
        if(ok){
            tree[node].l = tree[node].r = tree[node].maxn = tree[node].len;
            flag[node] = 1;
        }else{
        //    cout << "LL " << l << "rr " << r << endl;
            tree[node].l = tree[node].r = tree[node].maxn = 0;
            //cout << tree[node].maxn << endl;
            flag[node] = -1;
        }
          
        return;
    }
 //   cout <<"l = " << l << "r = " << r << endl;
    push_down(node);
    if(ql <= m) update(ok, ql, qr, l, m, lson);
    if(qr > m) update(ok, ql, qr, m + 1, r, rson);
    push_up(node);
}


int main(){
//    freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout);
    scanf("%d %d", &n, &mm);
    build(1, n, 1);
    while(mm--){
        int op, a, b;
        scanf("%d", &op);
        if(op == 1){
            scanf("%d", &a);
            int ans = query(a, 1, n, 1);
            printf("%d\n", ans);
            if(ans == 0)continue;
            int l = ans , r = ans + a - 1;
            if(r > n) r = n;
            update(0, l, r, 1, n, 1);

        }else{
            scanf("%d %d", &a, &b);
            int l = a, r = a + b -1;
            if(r > n)r = n; 
            update(1, l, r, 1, n, 1);
        }
    }    
}