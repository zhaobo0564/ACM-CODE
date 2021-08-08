#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 400;

ll mp[N][N];

int main() {
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            mp[i][j] = 1e15;
        }
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        mp[a][b] = min(mp[a][b], c);
        mp[b][a] = min(mp[b][a], c);
    }
    int k; cin >> k;
    ll ans = 1e15;
    while (k--) {
        int cnt; cin >> cnt;
        int last = 0;
        ll sum = 0;
        for (int i = 1;i <= cnt; i++) {
            int x; cin >> x;
            sum += mp[last][x];
            last = x;
        }
        sum += mp[0][last];
        if (cnt == n) {
            ans = min(ans, sum);
        }

    }
    if (ans >= 1e15) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}