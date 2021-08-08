#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

vector<ll>s;
vector<ll>p;

int n, mm;
ll tree[4 * N];

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1
void build(int l, int r,int node){
    if(l == r){
        tree[node] = s[l - 1] *p[l - 1];
        return;
    }
    build(l, m , lson);
    build(m + 1, r , rson);
    tree[node] = min(tree[lson], tree[rson]);
}

ll query(int ql, int qr, int l, int r, int node){
    if(ql > qr)return LLONG_MAX;
    if(ql <= l && qr >= r){
        return tree[node];
    }
    ll ans = LLONG_MAX;
    if(ql <= m)ans = min(ans, query(ql, qr ,l, m, lson));
    if(qr > m)ans = min(ans, query(ql, qr, m + 1, r, rson));
    return ans;
}


int main(){
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &mm);
        for(int i = 1; i <= n; i++){
            ll x, y;
            scanf("%lld %lld", &x, &y);
            s.push_back(x);
            p.push_back(y);
        }
        build(1, n, 1);
        while(mm--){
            ll x; scanf("%lld", &x);
            int pos = upper_bound(s.begin(), s.end(), x) - s.begin();
           // cout << "pos = " << pos << endl;
            pos--;  
            ll ans = p[pos] * x;
            ll ans1 = query(pos + 2, n, 1, n, 1);
            printf("%lld\n", min(ans, ans1));
        }
        s.clear(),p.clear();
    }
}