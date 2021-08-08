#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2007;

ll a[N], b[N], n, m;
int vis[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    ll ans = 0, sum = 0;
    for (int i = 1; i <= m; i++) {
        sum = 0;
        memset(vis, 0, sizeof(vis));
        for (int j = i - 1; j; j--) {
            if (b[i] == b[j]) {
                break;
            }
            if (vis[b[j]] == 0) {
                vis[b[j]] = 1;
                sum += a[b[j]];
            }
        }
        
    
      
        ans += sum;
    }
    cout << ans << endl;
}