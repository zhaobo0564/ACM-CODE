#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

int n, a[N], m, vis[N];

void solve() {
    cin >> n >> m;
    for (int i = 0; i <= m; i++) {
        vis[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        vis[a[i]]++;
    }
    int ans = 0;
    for (int i = 0; i <= m; i++) {
        if (vis[i]) {
            ans++;
            if (i == 0) {
                vis[i] = 0;

            } else {
                int cnt = (m - i) % m;
                if (vis[i] > vis[cnt]) {
                    vis[i] -= (vis[cnt] + 1);
                    vis[cnt] = 0;
                } else if (vis[i] == vis[cnt]) {
                    vis[i] = vis[cnt] = 0;
                } else {
                    vis[cnt] -= (vis[i] + 1);
                    vis[i] = 0;
                }

            }
        }
        if (vis[i]) {
            i--;
        }
        
    }
  
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}