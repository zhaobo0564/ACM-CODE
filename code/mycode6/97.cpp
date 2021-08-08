#include<bits/stdc++.h>
using namespace std;

const int N = 2007;

typedef long long ll;

ll a[N], b[N], c[N], d[N], n, m, vis[1000007];

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> c[i] >> d[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (c[j] >= a[i] && d[j] >= b[i]) {
                vis[c[j] - a[i]] = max(vis[c[j] - a[i]], d[j] - b[i] + 1);
            }
        
        }
    }
    ll cnt = 0, ans = 1e6+ 7;
    for (int i = 1000000; i >= 0; i--) {
        cnt = max(cnt, vis[i]);
        
        ans = min(ans, cnt + i);
    }

    cout << ans << endl;
}