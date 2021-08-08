#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 7;
int n;
ll a[N];
ll lsum[N], rsum[N];

vector<ll>v;

struct segment{
    ll sum, maxn;
}tree[4 * N];
#define m (l + r) / 2
#define lson 2  * node
#define rson 2 * node + 1

ll add[4 * N];

void push_up(int node){
    tree[node].sum = tree[lson].sum + tree[rson].sum;
    tree[node].maxn = max(tree[lson].maxn, tree[rson].maxn);
}

void push_down(int node, int nl, int nr){
    if(add[node]){
        tree[lson].sum = nl * add[node];
        tree[rson].sum = nr * add[node];
        tree[lson].maxn = add[node];
        tree[rson].maxn = add[node];
        add[lson] = add[node];
        add[rson] = add[node];
        add[node] = 0;
    }
}

void update(ll v, int pos, int l, int r, int node){
    if(l == r){
        tree[node].maxn = v;
        tree[node].sum = v;
        return;
    }
    push_down(node, m - l + 1, r - m);
    if(pos <= m) update(v, pos, l, m, lson);
    else update(v, pos, m + 1, r, rson);
    push_up(node);
}

void update(ll v, int ql, int qr, int l, int r , int node){
    if(ql <= l && qr >= r){
        tree[node].sum = v * (r - l + 1);
        tree[node].maxn = v;
        add[node] = v;
        return;
    }
    push_down(node, m - l + 1, r - m);
    if(ql <= m) update(v, ql, qr, l, m, lson);
    if(qr > m) update(v, ql, qr, m + 1, r, rson);
    push_up(node);
}

int query(ll v, int l, int r, int node){
    if(l == r)return l;
    push_down(node, m - l + 1, r - m);
    if(tree[lson].maxn >= v) return query(v, l, m, lson);
    return query(v, m + 1, r, rson);
}

int query1(ll v, int l, int r, int node){
    if(l == r)return l;
    push_down(node, m - l + 1, r - m);
    if(tree[rson].maxn >= v) return query1(v, m + 1, r, rson);
    return query1(v, l, m, lson);
}




int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }

    for(int i = 1; i <= n; i++){
        if(a[i] >= tree[1].maxn){
            update(a[i], i, 1, n, 1);
            lsum[i] = tree[1].sum;
        }else{
            int pos = query(a[i], 1, n, 1);
            update(a[i], pos, i, 1, n, 1);
            lsum[i] = tree[1].sum;
        }
    }

    for(int i = 1; i <= n; i++) update(0, i, 1, n, 1);
    for(int i = n; i; i--){
        if(a[i] >= tree[1].maxn){
            update(a[i], i, 1, n, 1);
            rsum[i] = tree[1].sum;
        }else{
            int pos = query1(a[i], 1, n, 1);
            update(a[i], i, pos, 1, n, 1);
            rsum[i] = tree[1].sum;
        }
    }
    int pos = 0;
    ll maxn = 0;
    for(int i = 1; i <= n; i++){
        ll cnt = lsum[i] + rsum[i] - a[i];
        if(cnt > maxn){
            maxn = cnt;
            pos = i;
        }
    }

    int i = pos;
    ll cnt = a[i];
    for(int j = i - 1; j; j--){
        if(cnt >= a[j]){
            v.push_back(a[j]);
            cnt = a[j];
        }else{
            v.push_back(cnt);
        }
    }
    reverse(v.begin(), v.end());
    v.push_back(a[i]);
    cnt = a[i];
    for(int j = i + 1; j <= n; j++){
        if(cnt >= a[j]){
            v.push_back(a[j]);
            cnt = a[j];
        }else{
            v.push_back(cnt);
        }
    }
    for(ll j: v){
        printf("%lld ", j);
    }
    puts("");

}