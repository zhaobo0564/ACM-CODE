#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

ll a[N], n;

void solve() {
   cin >> n;
   for (int i = 1; i <= n; i++) {
       cin >> a[i];
   }
   ll ans = LLONG_MAX;
   ll min_odd = LLONG_MAX, min_even = LLONG_MAX;
   ll sum_odd = 0, sum_even = 0;
   ll cnt_even = 0, cnt_odd = 0;
   ll cnt1 = 0, cnt2 = 0;
   for (int i = 1; i <= n; i++) {
       if (i % 2 == 0) {
            sum_even += a[i];
            cnt_even++;
            min_even = min(min_even, a[i]);
            cnt1 = sum_even - min_even + (n - cnt_even + 1) * min_even;
       } else {
            sum_odd += a[i];
            cnt_odd++;
            min_odd = min(min_odd, a[i]);
         //   cout <<"min " << min_odd << endl;
            cnt2 = sum_odd - min_odd + (n - cnt_odd + 1) * min_odd;
       }
       if (i > 1) {
            
            ans = min(ans, cnt1 + cnt2);  
       }
       
   }
   cout << ans << endl;
}

int main() {

    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}