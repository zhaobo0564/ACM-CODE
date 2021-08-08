#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, k;

ll fn[100];

ll comb(ll x, ll y) {
    if (x == 0) return 1;
    ll res = 1, cnt = 1;
    for (ll i = x; i >= x - y + 1; i--) {
        res = res * i;
        res = res / cnt;
        cnt++;
    }
    return res;
    
}

int main() {
 
    fn[0] = 1;
    for (int i = 1; i <= 50; i++) {
        fn[i] = fn[i - 1] * 2;
    }

    cin >> a >> b >> k;
    int n = a + b;
    k--;
    for (int i = 1; i <= n; i++) {
        ll cnt = comb(a + b - 1, b);
      //  cout << "cnt = " << cnt << endl;
        if (k >= cnt) {
            k -= cnt;
            cout << "b";
            b--;
        } else {
           if (a) {
               cout << "a";
               a--;
           } else if (b) {
               cout << "b";
               b--;
           }
        }
    }
    cout << endl;
//    cout << "k = " << k << endl;

    return 0;
}