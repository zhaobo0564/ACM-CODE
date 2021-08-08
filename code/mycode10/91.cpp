#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

typedef long long ll;

int n, m, a[N], b[N], k;

map<int, int> mp[N];

int visa[N], visb[N];

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        visa[a[i]]++;
    }
    for (int i = 1; i <= k; i++) {
        cin >> b[i];
        visb[b[i]]++;
        mp[a[i]][b[i]]++;
    }
    ll ans = 0;
    for (int i = 1; i <= k; i++) {
        visa[a[i]]--;
        visb[b[i]]--;
        mp[a[i]][b[i]]--;
        ll cnta = visa[a[i]] - mp[a[i]][b[i]];
        ll cntb = visb[b[i]] - mp[a[i]][b[i]];
        ll cn =k - i - (cnta + cntb + mp[a[i]][b[i]]);
        cn = max(1ll*0, cn);
        ans += cn;
    }
    cout << ans << endl;
    for (int i = 1; i <= k; i++) {
        mp[a[i]].clear();
    }
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}