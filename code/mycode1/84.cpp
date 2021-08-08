#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;

int n, mm;
ll tree[4 * N];
int flag[4 * N];

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1


void build(int l, int r, int node){
   // cout << "l =  " << l << "r = " << r<< endl;
   flag[node] = 0;
    if(l == r){
        scanf("%lld", &tree[node]);
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
    tree[node] = tree[lson] + tree[rson];
}

void update(int ql, int qr, int l, int r, int node){
    if(ql <= l && qr >= r){
       // cout << tree[node] << " " << l << " " << r << endl;
        if(flag[node]){
            return;
        }
        if(l == r){
            tree[node] = sqrt(tree[node]);
            if(tree[node] == 1 || tree[node] == - 1 || tree[node] == 0){
                flag[node] = 1;
            }
            return;
        }
    }
    if(ql <= m) update(ql, qr, l, m , lson);
    if(qr > m) update(ql, qr, m + 1, r, rson);
    tree[node] = tree[lson] + tree[rson];
    flag[node] = flag[lson] & flag[rson];
}

ll query(int ql, int qr, int l, int r, int node){
    if(ql <= l && qr >= r){
        return tree[node];
    }
    ll ans = 0;
    if(ql <= m) ans += query(ql, qr, l, m, lson);
    if(qr > m) ans += query(ql, qr, m + 1, r, rson);
    return ans;
}



int main(){
    int t = 1;
    while(~scanf("%d", &n)){
        printf("Case #%d:\n", t++);
        build(1, n, 1);
        scanf("%d", &mm);
        while(mm--){
            int op, l, r;
            scanf("%d %d %d", &op, &l, &r); 
            if(r < l )swap(l, r);
            if(op == 0){
                update(l, r, 1, n, 1);
            }else{
                printf("%lld\n", query(l, r, 1, n, 1));
            }
        }   
        printf("\n"); 
    }
   

}