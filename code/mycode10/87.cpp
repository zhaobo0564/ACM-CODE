#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

typedef long long ll;

ll n, a[N], b[N], k, m;

bool judge(ll x) {
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) {
            ll cnt = x / a[i];
            if (x < 0 ) {
                cnt--;
            } else if (x % a[i] == 0) {
                cnt--;
            }
            int p = upper_bound(b + 1, b + m + 1, cnt) - b - 1;
            //cout << " cnt = " << cnt << " p = " << p << endl;
            ans += 1ll * p;
        } else if (a[i] < 0) {
            ll cnt = x / a[i];
            if (cnt < 0 && x % a[i]) {
                cnt--;
            }
            int p = upper_bound(b + 1, b + m + 1, cnt) - b - 1;
            p = m - p;
            ans += 1ll * p;
        } else {
            if (x > 0) {
                ans += m;
            }
        }
    }
    //cout << "x = " << x << " ans = " << ans << endl;
    if (ans < k) return true;
    return false;

}

int main() {
    scanf("%lld %lld %lld", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%lld", &b[i]);
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    k = n * m - k + 1;
   // cout << k << endl;

    ll l = 1, r = 24;

    ll ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (judge(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    printf("%lld\n", ans);
}