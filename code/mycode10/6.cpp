#include<bits/stdc++.h>
using  namespace std;
const int N = 1e5 + 7;
typedef long long ll;
ll a[N], n;

int main() {
    ll sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1);
    ll ans = 1e18;
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        sum -= (a[i] - a[i - 1]) * 1ll * (n - i + 1);
        cnt += (a[i] - a[i - 1]) * 1ll * (i - 1); 
        //cout << "sum = " << sum << endl;
      //  cout << "cnt = " << cnt << endl;
        ans = min(ans, cnt + sum);
        
    }
    cout << ans << endl;
    
}