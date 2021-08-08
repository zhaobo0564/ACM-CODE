#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

ll a[N], n, k;

bool judge(ll x) {
    ll ans = 0;
    for (int i = 2; i <= n; i++) {
        ll cnt = a[i] - a[i - 1];
        ll cn = cnt / x;
        if (cnt % x) {
            cn++;
        }
        cn--;
        ans += cn;
    }
    return ans <= k;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    ll l = 1, r = 1e17, ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (judge(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;

}