#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;
vector<ll> ans;
void solve() {
    ans.clear();
    ll n; cin >> n;
    int f = 0;
    if (n == 2 || n == 4 || n == 6) {
        cout << 1 << endl << 1 << endl;
        return;
    }
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            f = 1;
            break;
        }
    }
    if (f == 0) {
     
        for (ll i = 1; i <= n - 2; i++) {
            ans.push_back(i);
        }
    } else {
      
        for (ll i = 1; i < n; i++) {
            if (__gcd(i, n) == 1) {
               ans.push_back(i);
               
            }
        }
        //cout << sum << endl;
    }
    ll sum = 1;
    for (ll i: ans) {
        sum = (sum % n * i % n) % n;
    }
    if (sum != 1) ans.pop_back();
    cout << ans.size() << endl;
    for (ll i: ans) {
        cout << i << " ";
    }
    cout << endl;
    
}

int main() {
    ios::sync_with_stdio(0);
    int t = 1; //cin >> t;
    while (t--) {
        solve();
    }
}