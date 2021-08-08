#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200007;

ll a[N], sum[N];
int n;
ll mod = 1e9 + 7;

int main(){
   scanf("%d", &n);
   for(int i = 1; i <= n; i++){
       scanf("%lld", &a[i]);
       sum[i] = sum[i - 1] + ((n - i + 1) * a[i] % mod) % mod;
       sum[i] %= mod;
   }
   ll ans = 0;
   for(int i = 1; i <= n; i++){
       ans += (((i * a[i] % mod) % mod)  * ((sum[n] - sum[i - 1] + mod) % mod)) % mod;
       ans %= mod;
   }
   printf("%lld\n", ans);

}