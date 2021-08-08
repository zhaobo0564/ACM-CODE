#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int vis[N], a[N], n, q;
#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1
int lefts[N], rights[N], num[N], tree[4 * N];

void build(int l, int r, int node){
    if(l == r){
        tree[node] = vis[l];
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
    tree[node] = max(tree[lson], tree[rson]);
}

int query(int ql, int qr, int l, int r, int node){
    if(ql > qr)return 0;
    if(ql <= l && qr >= r) return tree[node];
    int ans = 0;
    if(ql <= m)ans = max(ans, query(ql, qr, l, m, lson));
    if(qr > m)ans = max(ans, query(ql, qr, m + 1, r, rson));
    return ans;
}

void clear(int l , int r, int node){
    tree[node] = 0;
    if(l == r)return;
    clear(l, m, lson);
    clear(m + 1, r, rson);
}

int main(){
  //  FILE * fs =fopen("in.txt","a");
    while(scanf("%d", &n) != EOF && n){
        scanf("%d", &q);
       
        for(int i = 1; i <= n; i++){
            vis[i] = 1;
            lefts[i] = 0;
            num[i] = 1;
            rights[i] = 0;
        }
        a[0] = INT_MAX;
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            if(a[i] == a[i - 1]){
                vis[i] += vis[i - 1];
                lefts[i] = vis[i];            
            }
        }
        for(int i = n; i; i--){
            if(a[i] == a[i - 1]){
                num[i-1] += num[i];
                rights[i] = num[i];
            }
        }
        build(1, n, 1);
        while(q--){
            int x, y;
            scanf("%d %d", &x, &y);
            int res = rights[x];
            int res1 = lefts[y];
            if (res >= y - x + 1)res = y - x + 1;
            if(res1 >= y - x + 1)res1 = y - x + 1;
            int ans = query(x + res, y - res1, 1, n, 1);
            ans = max(ans, res);
            ans = max(ans, res1);
           // fprintf(fs, "%d\n", ans);
            printf("%d\n", ans);

        }
         clear(1, n, 1);
    }
    




}