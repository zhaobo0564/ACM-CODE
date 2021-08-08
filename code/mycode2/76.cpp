#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10000;

#define lson 2 * node
#define rson 2 * node + 1
#define m (l + r) / 2
int n;

struct node{
    int v;
    int pos;
}tree[4 * N];

vector<pair<int, int> >v;
vector<int>g;

void build(int l, int r, int node){
    if(l == r){
        tree[node].v = 0;
        tree[node].pos = l;
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
    tree[node].pos = min(tree[lson].pos, tree[rson].pos);
}

void update(int v, int x, int l, int r, int node){
    if(l == r){
        tree[node].v = v;
        if(tree[node].v)
            tree[node].pos = N;
        else tree[node].pos = l;
        return;
    }
    if(x <= m)update(v, x, l, m, lson);
    else update(v, x, m + 1, r, rson);
    tree[node].pos = min(tree[lson].pos, tree[rson].pos);
}

int query(int ql, int qr, int l, int r, int node){
    if(ql <= l && qr >= r){
        return tree[node].pos;
    }
    int ans = N;
    if(ql <= m)ans = min(ans, query(ql, qr, l, m, lson));
    if(qr > m) ans = min(ans, query(ql, qr, m + 1, r, rson));
    return ans;
}

int get_id(int x){
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}


int main(){
    scanf("%d", &n);
    
    while(n--){
        int id, x;
        scanf("%d %d", &id, &x);
        v.push_back({id, x});
        g.push_back(x);
        g.push_back(x + 1);
    }

    int maxn = 2000007;
    build(1, maxn, 1);

    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    for(auto it: v){
        if(it.first == 1){
            int x = get_id(it.second);
            update(1, x, 1, maxn, 1);
        }else if(it.first == 2){
            int x = get_id(it.second);
            update(0, x, 1, maxn, 1);
        }else{
            int x = get_id(it.second);
            int ans = query(x, maxn, 1, maxn, 1);
            printf("%d\n", g[ans - 1]);
        }
    }
}