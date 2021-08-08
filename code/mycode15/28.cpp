#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

ll x, y, z, n, t;

bool judge(__int128 a) {
    __int128 ans = a * (__int128)x + a * (__int128)y + (__int128)z * ((a * (a - 1)) / 2);
    if (ans > t) return false;
    return true;

} 

ll gao() {
    ll l = 0, r = 1e9, ans = 0;
    while (l <= r) {
        ll m = (l + r) / 2;
        if (judge(m)) {
            ans = m;
            l = m + 1;
        } else {
            r = m  -1;
        }

    }
 
    return ans;
}

int main() {
    cin >> n >> t;
    ll ans = 0, Ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> z;
        ll cnt = gao();
        ans = 0;
        ans += cnt * y + z * ((cnt * (cnt - 1)) / 2);
        ll res = cnt * x + cnt * y + z * ((cnt * (cnt - 1)) / 2);
        res = t - res;
        if (res >= x) {
            ans += min(res - x, y + (cnt + 1) * z);
        }
        Ans += ans;
    }
    cout << Ans << endl;
    return 0;
}

