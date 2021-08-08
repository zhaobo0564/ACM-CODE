#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e7 + 7;
int vis[N], cnt[N];

ll c, d, x;

ll work(ll g) {
    if ((x / g + d) % c) return 0;
    return 1ll* 1 << 1ll*cnt[(x / g + d) / c];
}


int main() {
    for (int i = 2; i < N; i++) {
        if (vis[i]) continue;
        for (int j = i; j < N; j += i) {
            cnt[j]++;
            vis[j] = 1;
        }
    }
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%lld %lld %lld", &c, &d, &x);
        ll ans = 0;
        for (ll i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                ans += work(i);
                if (x / i != i) ans += work(x / i);
            }
        }
        printf("%lld\n", ans);
    }
    
}