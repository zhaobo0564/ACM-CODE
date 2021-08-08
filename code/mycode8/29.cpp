#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

typedef long long ll;

ll n, m, k, a[N];

bool judge(ll x) {
    ll r = 1;
    ll cnt = 0;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        while (r <= n && cnt < k) {
            if (a[r] >= x) cnt++;
            r++;
        }
//cout << "i " << i << " r = " << r << endl;
        if (cnt == k)
            ans += (n - r + 2);
        if (a[i] >= x) cnt--;
    }
   // cout << "ans " << ans << "x " << x << endl;

    if (ans >=  m) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> k >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        ll l = 1, r = 1e9, ans;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (judge(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << ans << endl;

    }
}