#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;

int main() {
    cin >> n >> k;
    if (k >= n) {
        int r;
        ll ans = 0;
        for (ll i = 1; i <= n; i = r + 1) {
            r = k / (k / i);     
         //   cout << r << endl;   
            r = min(1ll*r, n);              
            ans += ((r + i) * (r - i + 1) / 2) * (k / i);
        }
    //    cout << ans << endl;
   //     cout << n * k << endl;
        ans = n * k - ans;
        cout << ans << endl;
        
    } else {
        int r;
        ll ans = 0;
        for (ll i = 1; i <= k; i = r + 1) {
            r = k / (k / i);
            r = min(1ll*r, n);
            ans += ((r + i) * (r - i + 1) / 2) * (k / i);
        }
        ans = k * k -  ans;
       // cout << ans << endl;
        ans += (n - k) * k;
        cout << ans << endl;
    }
}