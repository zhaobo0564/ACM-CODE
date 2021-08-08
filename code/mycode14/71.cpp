#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll n, k, ans;

int main() {
    cin >> n >> k;

    for (ll i = 1; i <= n; i++) {
        ans += i;
        ans %= mod;
    }
    cout << ans << endl;
}