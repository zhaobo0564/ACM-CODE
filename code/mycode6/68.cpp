#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

typedef long long ll;
ll n;

void solve() {
    cin >> n;
    ll ans = 1e15;
    
    for (int i = 1; i <= 70010; i++) {
        ll cnt = i - 1;
        ll cat = (n / i);
        cat--;
        if (n % i) {
            cat++;
        }
        ans = min(ans, cat + cnt);

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