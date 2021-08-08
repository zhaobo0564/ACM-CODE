#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

int  n, mm, a[N], flag[4 * N];

#define lson 2 * node
#define rson 2 * node + 1
#define m (l + r) / 2

struct node{
    int maxn, gcd;
    int value;
}tree[4 * N];

void build(int l, int r, int node){
    if(l == r){
        tree[node].gcd = a[l] - a[l - 1];
        tree[node].maxn = a[l] - a[l - 1];
        tree[node].value = a[l];
        return; 
    }
    build(l, m, lson);
    build(m + 1, r,rson);
    tree[node].gcd = __gcd(tree[lson].gcd, tree[rson].gcd);
    tree[node].maxn = max(abs(tree[lson].maxn), abs(tree[rson].maxn));
}

void update(int pos, int v, int l, int r, int node){
    if(pos < 1 || pos > n)return;
    if(l == r){
        tree[node].gcd = tree[node].gcd + v;
        tree[node].maxn = tree[node].maxn + v;
        //cout << tree[node].maxn << endl;
        return;
    }
    if(flag[node]){
        tree[lson].value += flag[node];
        tree[rson].value += flag[node];
        flag[lson] += flag[node];
        flag[rson] += flag[node];
        flag[node] = 0;
    }
    if(pos <= m) update(pos, v, l, m , lson);
    else update(pos, v, m + 1, r, rson);
    tree[node].gcd = __gcd(tree[lson].gcd, tree[rson].gcd);
    tree[node].maxn = max(abs(tree[lson].maxn), abs(tree[rson].maxn));
}

void update(int v, int ql, int qr, int l, int r, int node){
    if(qr < ql)return;
    if(ql <= l && r <= qr){
        tree[node].value += v;
        flag[node] += v;
      //  cout << "l=" << l << " r = " << r << endl;
       // cout <<"node" << tree[node].value<< endl;
        return;
    }
    if(flag[node]){
        tree[lson].value += flag[node];
        tree[rson].value += flag[node];
         flag[lson] += flag[node];
        flag[rson] += flag[node];
        flag[node] = 0;
    }
    if(ql <= m)update(v, ql, qr, l, m, lson);
    if(qr > m) update(v, ql, qr, m + 1, r, rson);

}

int query(int ql, int qr, int l, int r, int node){
    if(ql <= l && qr >= r) return tree[node].gcd;
    int ans = 0;
    if(flag[node]){
        tree[lson].value += flag[node];
        tree[rson].value += flag[node];
         flag[lson] += flag[node];
        flag[rson] += flag[node];
        flag[node] = 0;
    }
    if(ql <= m)ans = __gcd(ans, query(ql, qr, l, m, lson));
    if(qr > m)ans = __gcd(ans, query(ql, qr, m + 1, r, rson));
    return ans;
}

int query_max(int ql, int qr, int l, int r, int node){
    //cout <<"l = " << l << " r = " << tree[node].maxn << endl;
    if(ql <= l && qr >= r) return abs(tree[node].maxn);
    int ans = 0;
    if(flag[node]){
        tree[lson].value += flag[node];
        tree[rson].value += flag[node];
        flag[lson] += flag[node];
        flag[rson] += flag[node];
        flag[node] = 0;
    }
    if(ql <= m)ans = max(ans, query_max(ql, qr, l, m, lson));
    if(qr > m) ans = max(ans, query_max(ql, qr, m + 1, r, rson));
    return ans;
}

int query(int pos, int l, int r, int node){
  //  cout << "l = " << l << " r = " << r << endl;
    if(l == r)return tree[node].value;
    if(flag[node]){
        tree[lson].value += flag[node];
        tree[rson].value += flag[node];
        flag[lson] += flag[node];
        flag[rson] += flag[node];
       // cout << "l = " << l << " r = " << r << endl;
        flag[node] = 0;
    }
    if(pos <= m)return query(pos, l , m, lson);
    return query(pos, m + 1, r, rson);
}


int main(){
    scanf("%d %d", &n, &mm);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    build(1, n, 1);
    while(mm--){
        int op, l, r;
        scanf("%d %d %d", &op, &l, &r);
        if(op == 1){
            int x; scanf("%d", &x);
            update(l, x, 1, n, 1);
            update(x, l, r, 1, n, 1);
            update(r + 1, -x, 1, n, 1);
        }else if(op == 2){
            printf("%d\n", query_max(l + 1, r, 1, n, 1));
        }else{
            int ans = query(l, 1, n, 1);
           // cout <<"an s =" << ans << endl;
            ans = __gcd(ans, query(l + 1, r, 1, n, 1));
          //  cout << ans << " " << query(l + 1, r, 1, n, 1) << endl;
            printf("%d\n", abs(ans));
        }
        
    }
}

