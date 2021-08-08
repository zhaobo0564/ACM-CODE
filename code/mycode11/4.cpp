#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
typedef long long ll;

ll n, k, p[200];

int cmp(pair<ll, ll> x, pair<ll, ll> y) {
    if (x.first * y.second > y.first * x.second) {
        return 1;
    } else  {
        return 0;
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    ll sum = 0;
    ll res = 0;

    for (int i = 1; i < n; i++) {
        res += p[i];
        int ok = cmp({p[i + 1], res}, {k, 100});
        if (ok == 0) {

        } else if (ok == 1) {
            ll cnt = (p[i + 1] * 100) / k;

            if ((p[i + 1] * 100) % k) {
                cnt++;
            }

            sum += (cnt - res);
            res = cnt;
        
        }          
    }

    
    cout << sum << endl;
}



int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}