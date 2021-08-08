#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;

typedef long long ll;
int n;
ll a[N], l[N], r[N], suml[N], sumr[N];

void solve() {
    scanf("%d", &n);
    l [0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        l[i] = l[i - 1] + a[i];
    }
    r[n + 1] = 0;
    for (int i = n; i; i--) {
        r[i] = r[i + 1] + a[i];
    }
    suml[0] = 0;
    for (int i = 1; i <= n; i++) {
        suml[i] = suml[i - 1] + l[i];
    }
    sumr[n + 1] = 0;
    for (int i = n; i; i--) {
        sumr[i] = sumr[i + 1] + r[i];
    }
    ll ans = LLONG_MAX;
    for (ll i = 1; i <= n; i++) {
        ll cnt = suml[n] - suml[i - 1] - l[i - 1] * (n - i + 1);
        ll res = suml[i - 1] + (i - 1) * (l[n] - l[i - 1]);
     
        ans = min(ans, cnt + res);
     //   cout << sumr[1] << " " << sumr[i + 1] << endl;
        cnt = sumr[1] - sumr[i + 1] - r[i + 1] * (i);
        res = sumr[i + 1] + (n - i) * (r[1] - r[i + 1]);
       // cout << "end " << r[1] - r[i + 1] << endl;
       // cout << cnt << endl;
        ans = min(ans, cnt + res);
    }
    printf("%lld\n", ans);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}