#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
typedef long long ll;
ll a[4][N], n1, n2, n3, t;

void solve() {
    ll sum1 = 0, sum2 = 0, sum3 = 0, ans;
    cin >> n1 >> n2 >> n3;
    for (int i = 1; i <= n1; i++) {
        cin >> a[1][i];
        sum1 += a[1][i];
    }
    sort(a[1] + 1, a[1] + n1 + 1);
    for (int i = 1; i <= n2; i++) {
        cin >> a[2][i];
        sum2 += a[2][i];
    }
    sort(a[2] + 1, a[2] + n2 + 1);
    for (int i = 1; i <= n3; i++) {
        cin >> a[3][i];
        sum3 += a[3][i];
    }
    sort(a[3] + 1, a[3] + n3 + 1);

    ans = sum1 + sum2 + sum3;
    ll cnt = a[1][1] + a[2][1] + a[3][1];
    cnt = cnt - max(max(a[1][1], a[2][1]), a[3][1]);
    ans = ans - 2 * min(min({sum1, sum2, sum3}), cnt);
    cout << ans << endl;


}

int main() {
    t = 1;
    while (t--) {
        solve();
    }
}