#include<bits/stdc++.h>
using namespace std;
const int N = 3000 + 7;
typedef long long ll;
ll a[N], vis[N][N], n, t, cnt[N], cn[N];

int main() {
    ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                vis[i][j] = 0;
            }
        }
        for (int i = 0; i <= n; i++) {
            cnt[i] = 0;
            cn[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                vis[i][a[j]]++;
            }
        }
        for (int i = 1; i < n; i++) {
            ll sum = 0;
            for (int j = 1; j <= n; j++) cnt[j] = 0;
            cnt[a[i + 1]]++;

            for (int j = i + 2; j < n; j++) {
                sum += vis[j][a[j - 1]];
                if (a[i] == a[j]) {
                    ans += sum;
                } 
                sum -= cnt[a[j + 1]];
            
                cnt[a[j]]++;


            }
        }
        cout << ans << endl;
       

    }
}