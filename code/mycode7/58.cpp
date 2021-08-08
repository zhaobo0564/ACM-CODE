#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

typedef long long ll;

void solve() {
    ll x, y, c[10], ans;
    cin >> x >> y;
    for (int i = 1; i <= 6; i++) {
        cin >> c[i];
    }
    if (x <= 0 && y >= 0) {
        ll down = abs(x);
        ll right = abs(y);
        ans = down * c[3] + right * c[2];
        ll cnt = (right + down) * c[2] + down * c[4];
        ans = min(ans, cnt);
        cnt = (right + down) * c[3] + right * c[1];
        ans = min(ans, cnt);
    } else if (x >= 0 && y <= 0) {
        ll up = abs(x);
        ll left = abs(y);
        ans = up * c[6] + left * c[5];
        ll cnt = (up + left) * c[6] + left * c[4];
        ans = min(ans, cnt);
        cnt = (up + left) * c[5] + up * c[1];
        ans = min(ans, cnt);  
    } else if (x >= 0 && y >= 0) {
        ll up = x;
        ll right = y;
        ans = up * c[6] + right * c[2];
        if (x >= y) {
            ll cnt = y * c[1] + (x - y) * c[6];
            ans = min(cnt, ans);
            cnt = x * c[1] + (x - y) * c[5];
            ans = min(cnt, ans);
        
        } else {
            ll cnt = x * c[1] + (y - x) * c[2];
            ans = min(ans, cnt);
            cnt = y * c[1] + (y - x) * c[3];
            ans = min(ans, cnt);
        }
    } else {
        x = abs(x);
        y = abs(y);
        ans = x * c[3] + y * c[5];
        if (x >= y) {
            ll cnt = y * c[4] + (x - y) * c[3];
            ans = min(ans, cnt);
            cnt = x * c[4] + (x - y) * c[2];
            ans = min(ans, cnt);
           
        } else {
            ll cnt = x * c[4] + (y - x) * c[5];
            ans = min(ans, cnt);
            
            cnt = y * c[4] + (y - x) * c[6];
            ans = min(ans, cnt);
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
}