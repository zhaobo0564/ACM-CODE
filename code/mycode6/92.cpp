#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
typedef long long ll;
const ll mod = 1e9 + 7;
ll lsum[N], rsum[N], l[N], r[N], fn[N], fn_sum[N], a[N];
string s;

void solve() {
    fn[0] = 1;
    for (int i = 1; i < N; i++) {
        fn[i] = fn[i - 1] * 10;
        fn[i] = fn[i] % mod;
    }
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        a[i + 1] = s[i] - '0';
    }
    int n = s.length();
    fn_sum[0] = 1;
    for (int i = 1; i <= n; i++) {
        fn_sum[i] = (fn_sum[i - 1] + fn[i]) % mod;
    }
    for (int i = 1; i <= n; i++) {
        l[i] = l[i - 1] * 10 + a[i];
        l[i] %= mod;
    }

    for (int i = n; i; i--) {
        r[i] = (a[i] * fn[n - i]) % mod + r[i + 1];
        r[i] %= mod; 
    }
    for (int i = n; i; i--) {
        rsum[i] = (rsum[i + 1] + r[i]) % mod;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll cnt = (fn_sum[n - i] * l[i - 1]) % mod;
      //  cout << "cnt = " << cnt << endl;
        ans = (ans + cnt + rsum[i + 1]) % mod;
        //cout << "rsum = " << rsum[i + 1] << endl;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    int t = 1;

    while (t--) {
        solve();
    }
}