#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m;

int main() {
    cin >> n >> m;
    ll ans = 0;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= m + 1; j++) {
            // 1
            ll ucnt = i - 1;
            ll dcnt = n + 1 - i;
            ll cnt = min(ucnt, dcnt);
            ans += cnt;
            ll lcnt = j - 1;
            ll rcnt = m + 1 - j;
            cnt = min(lcnt, rcnt);
            ans += cnt;
        }
    }
    //cout << ans << endl;
    for (int i = 2; i <= n; i += 2) {
        for (int j = 2; j <= m; j += 2) {
            ll cnt = (n - i + 1) * (m - j + 1);
            ans += cnt * 2;
        }
    }
    cout << ans << endl;
}