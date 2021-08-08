#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2007;

bitset<2000007> dp, temp;
int n, a[N];

int main() {
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum += 1ll * a[i];
    }
    dp.set(0);
    for (int i = 1; i <= n; i++) {
        temp = dp << a[i];
        dp = temp | dp;
    }
    ll ans = 0;
    for (int i = 0; i < 2000007; i++) {
        if (dp[i]) {
            ans = max(ans, 1ll * i * 1ll*(sum - i));
        }
    }
    printf("%lld\n", ans);
    return 0;
    
}