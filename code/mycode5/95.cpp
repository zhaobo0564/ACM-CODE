#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 1; i <= n; i++)
const int N = 2e5 + 7;
typedef long long ll;

ll x, y, z, xx, yy, zz;

int t, n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> x >> y >> z;
        cin >> xx >> yy >> zz;
        ll cnt =  min(z, yy);
        ll ans = cnt + cnt;
        z -= cnt, yy -= cnt;
        cnt = min(y, xx);
        y -= cnt, xx -= cnt;
        cnt = min(y, yy);
        y -= cnt, yy -= cnt;
        cnt = min(x, zz);
        x -= cnt, zz -= cnt;
        cnt = min(z, zz);
        z -= cnt, zz -= cnt;
        cnt = min(y, zz);
        ans -= 2*cnt;
        cout << ans << endl;
        
    }
}