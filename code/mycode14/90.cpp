#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> ans;

int main() {
    ll n; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i * j > n) break;
            ans.push_back(i * j);
        }
    }
    ll res = 0;
    for (ll i: ans) {
        ll cnt = n / i;
        res += cnt;
    }
    cout << res << endl;
    
}