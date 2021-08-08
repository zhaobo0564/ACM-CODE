#include<bits/stdc++.h>
using namespace std;

const int N = 200007;
typedef long long ll;
ll a[N], n;
ll fn[N];
ll mod = 1e9 + 7;

ll vis[70];

ll C3(ll x){
    ll an = x *(x - 1) * (x - 2);
    return an / 6;
}

ll C2(ll x){
    ll an = x * (x - 1);
    return an / 2;
}

int main(){
    fn[0] = 1;
    for(int i = 1; i <=63; i++){
        fn[i] = fn[i - 1] * 2;
        fn[i] %= mod;
    }
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        ll x = a[i];
        int cnt = 0;
        while(x){
            if(x & 1){
                vis[cnt]++;
            }
            x = x / 2;
            cnt++;
        }
    }
    ll ans = 0;
    for(int i = 0; i < 64; i++){
        ans = (ans + (C3(vis[i]) % mod + (1ll*C2(n - vis[i])% mod * vis[i] % mod) % mod) * fn[i] % mod) % mod;
    }
    printf("%lld\n", ans);
}
 