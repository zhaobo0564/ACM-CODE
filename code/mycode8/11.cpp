#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

ll n, a[N], b[N];

struct node {
    ll x, y;
}p[N];

bool cmp(node xx, node yy) {
    return xx.x > yy.x;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        p[i].x = a[i];
        p[i].y = b[i];
    }
    sort(p + 1, p + n + 1, cmp);
    ll ans = 1e16;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        ll cnt = p[i].x;
        ll res = max(cnt, sum);
        ans = min(ans, res);
        sum += p[i].y;
    }
    ans = min(ans, sum);
    cout << ans << endl;
}


int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}