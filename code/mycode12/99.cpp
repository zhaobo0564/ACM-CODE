#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1007;

ll euler_phi(ll n) {
  ll ans = n;
  for (ll i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        ans = ans / i * (i - 1);
        while (n % i == 0) n /= i;
    }
  }
  if (n > 1) ans = ans / n * (n - 1);
  return ans;
}

int main() {
    int t; cin >> t;
    int ca = 1;
    while (t--) {
        int n, ans = 0; 
        cin >> n;
        for (int i = 1; i <= n; i++) {
            ans += euler_phi(i);
        }
        cout << ca++ << " " << n <<" " << ans + ans + 1  << endl;
    }
   
}