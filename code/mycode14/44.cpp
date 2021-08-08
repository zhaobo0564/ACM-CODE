#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
int a[N], k, z, n;
ll sum[N], cnt[N];

vector<ll> g[N];

int main() {
    scanf("%d %d %d", &n, &k, &z);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i];
        cnt[i] = (cnt[i - 1] + a[i]) % k;
    }
    ll ans = 0;
    g[0].push_back(0);
    for (int i = 1; i <= n; i++) {
        ll x = sum[i] - z;
        if (x >= 0) {
            int p = upper_bound(g[cnt[i]].begin(), g[cnt[i]].end(), x) - g[cnt[i]].begin() + 1;
            p--;
            ans += 1ll * p;
        }
        g[cnt[i]].push_back(sum[i]);
    }
    printf("%lld\n", ans);
}