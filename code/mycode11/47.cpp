#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;
typedef long long ll;
int n;
ll a[N];
vector<ll> v;

int main() {
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    ll ave = sum / n;
    sum = 0;
    ll cnt = ave;
    for (int i = n; i; i--) {
        sum += a[i];
        v.push_back(cnt - sum);
       // cout << cnt - sum << " ";
        cnt += ave;
    }
  //  cout << endl;
    sort(v.begin(), v.end());

    int pos = v.size() / 2;
    ll ans = LLONG_MAX;
    for (int i = max(0, pos - 10); i < min((int)v.size(), pos + 10); i++) {
        ll base = v[i];
        ll res = 0;
        for (ll j: v) {
            res += abs(base - j);
        }
        ans = min(ans, res);
    }
    cout << ans << endl;
}
