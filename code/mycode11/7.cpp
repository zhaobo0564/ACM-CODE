#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
typedef long long ll;

ll n, a[N], b[N], c[N], sum[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        sum[1] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    sum[1] = abs(a[2] - b[2]) + 2;

    ll ans = 0;

    for (int i =2; i <= n; i++) {
        ll cnt = c[i] - 1 + sum[i - 1];
        ans =  max(ans, cnt);
        if (a[i + 1] == b[i + 1]) {
            sum[i] = 2;
        } else {
            sum[i] = sum[i - 1] + min(a[i + 1], b[i + 1]) - 1 + c[i] - max(a[i + 1], b[i + 1]) + 2;
           // cout << "A " <<  << endl;
            sum[i] = max(sum[i], abs(a[i + 1] - b[i + 1]) + 2);
        }
        //cout << sum[i] << " ";
    }
   // cout << endl;
    cout << ans << endl;

}



int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}