#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;

ll a[N], n, w;

multiset<ll> s;



void solve() {
   cin >> n >> w;
   s.clear();
   for (int i = 1; i <= n; i++) {
       cin >> a[i];
       s.insert(a[i]);
   }
   ll h = 0;
   while (1) {
       ll x = w;
       while (x > 0) {
           auto it = s.upper_bound(x);
           if (it == s.begin()) {
               break;
           }
           it--;
           x -= *it;
           s.erase(it);
           if (s.size() == 0) break;
       }
       h++;
       if (s.size() == 0) break;
       
   }
   cout << h << endl;

}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}