#include<bits/stdc++.h>
using namespace std;
const int N = (2e5+7)*2;
int n,a[N],b[N],c[N] ,d[N];
vector<int>v;
int tree[4*N];
#define lson 2*node
#define rson 2*node+1
#define m (l+r)/2
typedef long long ll;
ll mod = 998244353;

ll fpow(ll a, ll x){
    ll base = 1;
    while(x){
        if(x & 1){
            base = base * a % mod;
        }
        a = a * a %mod;
        x = x / 2;
    }
    return base;
}



void update(int p, int l, int r, int node){
    tree[node]++;
    if(l == r){
        return;
    }
    if(p <= m)update(p, l, m, lson);
    else update(p, m+1, r, rson);
}

int query(int ql, int qr, int l, int r, int node){
    if(ql>qr)return 0;
    if(ql <= l && qr >= r){
        return tree[node];
    }
    int ans = 0;
    if(ql <= m)ans += query(ql, qr, l, m, lson);
    if(qr > m)ans += query(ql, qr, m + 1, r, rson);
    return ans;
}

int get_id(int x){
    return lower_bound(v.begin(), v.end(), x)-v.begin()+1;
}

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
    }
    for(int i = 1; i<= n; i++){
        scanf("%d", &b[i]);
        c[i] = a[i] - b[i];
        d[i] = b[i] - a[i];
        v.push_back(d[i]);
        v.push_back(c[i]);
    }
    sort(v.begin(), v.end());

    int pos = get_id(d[n]);
    update(pos, 1, N - 1, 1);
    long long ans =0 ;
    for(int i=n-1; i ;i--){
        int cn = get_id(c[i]);
        ans = ans + 1ll*query(1,cn -1,1,N - 1, 1 );
        cn = get_id(d[i]);
        update(cn,1,N-1,1);

    }
    printf("%lld\n",ans);
}