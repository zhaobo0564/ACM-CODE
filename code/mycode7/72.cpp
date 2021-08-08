#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
ll n, x, pos, a[N];
const ll mod = 1e9 + 7;

ll fn[N];



void solve() {
    cin >> n >> x >> pos;
    for (int i = 0; i <= n; i++) {
        a[i] = 0;
    }
    int left = 0;
    int right = n;
    while (left < right) {
        int middle = (left + right) / 2;
        if (middle <= pos) {
            left = middle + 1;
            a[middle] = -1;   

        } else {
            right = middle;
            a[middle] = 1;
        }
    }
    a[left - 1] = 0;
    int big = 0, small = 0;
    for (int i = 0; i < n; i++) {
     //   cout << a[i] << " ";
        if (a[i] == 1) {
            big++;
        } else if (a[i] == -1) {
            small++;
        }
    }
   // cout << endl;
    if (big > n - x) {
        cout << 0 << endl;
    } else if (small >= x) {
        cout << 0 << endl;
    } else {
        ll cn = 1;
        ll base = n - x;
        for (ll i = 1; i <= big; i++) {
            cn = cn * base;
            cn %= mod;
            base--;
        }
        base = x - 1;
        ll cn1 = 1;
        for (ll i = 1; i <= small; i++) {
            cn1 = base * cn1;
            cn1 %= mod;
            base--;
        }
        

        ll ans = (cn % mod * cn1 % mod) % mod;
        ll cnt = (ans%mod * fn[n - 1 - big - small]%mod) % mod;
        cout << cnt << endl;
    }


    

    
}



int main() {
    int t;
    fn[0] = 1;
    for (ll i = 1; i <= 10000; i++) {
        fn[i] = fn[i - 1] * i;
        fn[i] %= mod;
    }

    ios::sync_with_stdio(0);
    //cin >> t;
    t = 1;
    while (t--) {
        solve();
    }

}