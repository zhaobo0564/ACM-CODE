#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;
ll n, a[N], k, w[N];

int vis[N];


int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
   scanf("%lld %lld", &n, &k);
   for (int i = 1; i <= n; i++) {
       scanf("%lld", &a[i]);
   }
   for (int i = 1; i <= n / 2; i++) {
       int x; scanf("%d", &x);
       w[i] = x; 
   }
   ll ans = 0;
   for (int i = 1; i <= n; i++) {
       if (vis[a[i]]) {
           ans += 1ll*(i - vis[a[i]]) * w[a[i]];
       }
       vis[a[i]] = i;
   }
   printf("%lld\n", ans);
   
   
}