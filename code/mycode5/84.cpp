#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll x, k, d;
    cin >> x >> k >> d;
    if (x < 0) x = -x;
    ll cnt = x / d;
    if (x % d) {
        cnt++;
    }
    if (k >= cnt) {
        ll cat = k - cnt;
        ll ans;
        if (cat % 2) {
            ans = x - d * cnt;
            ans += d;
            cout << abs(ans) << endl;
        } else {
            ans = x - d * cnt;
            cout << abs(ans) << endl;
        }
    } else {
     
            ll ans = x - d * k;
            cout << abs(ans) << endl;

        
    }
}