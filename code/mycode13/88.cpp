#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int maxn=1e9+7;
typedef long long ll;


struct node{
    int cover,l,r, ct;
    int ls, rs;
    ll sum;
}tree[40*N];

vector<int> x;


#define m (l + r >> 1) 

int top = 1;
void build(int l,int r,int &node){
    node = top++;
    tree[node].l=x[l-1];
    tree[node].r=x[r-1];
    tree[node].cover=0;
    if(r-l==1)return;
    build(l,m,tree[node].ls);
    build(m,r,tree[node].rs);
}

void push_up(int node) {
    int ls = tree[node].ls, rs = tree[node].rs;
    tree[node].ct = tree[ls].ct + tree[rs].ct;
    ll sum = tree[ls].sum + tree[rs].sum;
    if (tree[node].cover == 0) {
        tree[node].sum = sum;
    }
    if (tree[node].ct == 0) {
    
    }
}

void up(int v, int ql, int qr, int last, int &node) {
    node = top++;
    tree[node] = tree[last];
    if(ql>=tree[node].r||tree[node].l>=qr)return;
    if(ql<=tree[node].l&&qr>=tree[node].r){
        tree[node].cover += v;
        tree[node].ct = tree[node].cover;
        tree[node].sum = tree[node].r - tree[node].l;
        return;
    }
    up(v, ql, qr, tree[last].ls, tree[node].ls);
    up(v, ql, qr, tree[last].rs, tree[node].rs);
    push_up(node);
    
}


ll qu(int last, int node) {
    if(tree[node].l==0&&tree[node].r==0)return 0;
    if (tree[node].cover > tree[last].cover) {
        return tree[node].sum;
    }
    if (tree[node].ct > tree[last].ct && tree[last].ct == 0) {
        return tree[node].sum;
    }
    ll ans = 0;
    ans += qu(tree[last].ls, tree[node].ls);
    ans += qu(tree[last].rs, tree[node].rs);
    return ans;
}

int rt[N], a[N], b[N];

int main() {
    int n, q; scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        int l, r; scanf("%d %d", &l, &r);
        r++;
        a[i] = l, b[i] = r;
        x.push_back(l);
        x.push_back(r);
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    build(1, x.size(), rt[0]);
    for (int i = 1; i <= n; i++) {
        up(1, a[i], b[i], rt[i - 1], rt[i]);
    }
    while (q--) {
        int l, r; scanf("%d %d", &l, &r);
        ll ans = qu(rt[l - 1], rt[r]);
        printf("%lld\n", ans);
    }
}