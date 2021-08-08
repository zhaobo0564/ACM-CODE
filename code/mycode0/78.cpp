#include<bits/stdc++.h>
using namespace std;

const int N = 2e4 + 7;
int a[N], n, t;

int tree[20 * N], tree1[20 * N];

#define m (l + r) / 2
#define  lson 2 * node
#define rson 2 * node + 1

void update(int pos, int l ,int r, int node){
    tree[node]++;
    if(l == r){
        return;
    }
    if(pos <= m)update(pos, l, m , lson);
    else update(pos, m + 1, r, rson);
}

void update1(int v, int pos, int l, int r, int node){
    tree1[node] += v;
    if(l == r){
        return;
    }
    if(pos <= m)update1(v, pos, l, m, lson);
    else update1(v, pos, m + 1, r,rson);
}

int query(int ql, int qr, int l, int r, int node){
    if(ql > qr)return 0;
    if(ql <= l && qr >= r)return tree[node];
    int ans = 0;
    if(ql <= m)ans += query(ql, qr, l, m , lson);
    if(qr > m) ans += query(ql, qr, m + 1, r ,rson);
    return ans;
}

int query1(int ql , int qr, int l, int r, int node){
    if(ql > qr)return 0;
    if(ql <= l && qr >= r)return tree1[node];
    int ans = 0;
    if(ql <= m)ans += query1(ql, qr, l, m , lson);
    if(qr > m) ans += query1(ql, qr, m + 1, r ,rson);
    return ans;
}

void clear(int l ,int r, int node){
    tree[node] = tree1[node] = 0;
    if(l == r)return;
    clear(l, m, lson);
    clear(m + 1, r, rson);
    
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int maxn = 100000;
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            update1(1, a[i], 1, maxn, 1);
        }

        long long ans = 0;
        update(a[1], 1, maxn, 1);
        update1(-1, a[1], 1, maxn, 1);
        for(int i = 2; i < n; i++){
            long long res = 1ll*query(1, a[i] - 1, 1, maxn, 1);
            long long res1 = 1ll*query1(a[i] + 1, maxn, 1, maxn, 1);
         //   cout << res << " " << res1 << endl;
            ans += res * res1;
            res = i - 1 - res;
            res1 = n - i - res1;
            ans += res * res1;
            update(a[i], 1, maxn, 1);
            update1(-1, a[i], 1, maxn, 1);
        }
        printf("%lld\n", ans);
        clear(1, maxn, 1);

    }
}