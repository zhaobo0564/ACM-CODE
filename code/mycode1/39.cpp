#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 7;

ll a[N], sum[N], cnt[N];
int n;

int main(){
    scanf("%d", &n);
    ll mod = 1000000007;
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        sum[i] = sum[i - 1] + a[i];
        sum[i] %= mod;
        cnt[i] = cnt[i - 1] + (a[i]*a[i] % mod);
        cnt[i] %= mod;
    }
    
    ll ans = 0;
    for(int i = n - 1; i >= 1; i--){
        ans =ans + ((i*((a[i + 1] % mod * a[i + 1] % mod)%mod)%mod + cnt[i] - (((2 * sum[i] % mod) % mod )* (a[i + 1] % mod))%mod + mod) % mod);
        ans = ans % mod;
    }
    printf("%lld\n", ans);
}

