#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[1000], n, t, vis[1000];

int main() {
    ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            vis[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            vis[a[i]]++;

        }
        int ans = 0;
        for (int i = 1; i <= 2 * n; i++) {
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                if (i - a[j] <= 0) continue;
                if (vis[a[j]] == 0) continue;
                vis[a[j]]--;
                if (vis[i - a[j]] > 0) {
                    cnt++;
                    vis[i - a[j]]--;
                } else {
                    vis[a[j]]++;
                }
            }
            ans = max(ans, cnt);
            for (int j = 1; j <= 2*n; j++) {
                vis[j] = 0;
            }
            for (int j = 1; j <= n; j++) {
                vis[a[j]]++;
            }
        }
        cout << ans << endl;
    }
}