#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fn[100000];
 
ll ksm(ll x, ll y) {
    ll base = 1;
    while (y) {
 
        if (y & 1) {
            base = base * x;
        }
        x =  x * x;
        y = y / 2;
    }
    return base;
}
 
int main() {
    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        ll n, k;
        scanf("%lld %lld", &n, &k);
 
            int cnt;
            if (k == 1 || k > 30) {
                printf("Case #%d: %lld\n", ca++, n);
                continue;
            }
            for (ll i = 1; i <= 50000; i++) {
                fn[i] = ksm(i, k);
                cnt = i;
                if (fn[i] > n) break;
            }
            
 
            ll ans = 0;
            for (int i = 1; i < cnt; i++) {
 
             //   cout <<"l = " <<fn[i] - 1 <<    " r = " << fn[i + 1] - 1 << endl;
              //  cout <<"res" << (fn[i + 1] -1) / i - (fn[i] - 1) / i << endl;
 
                ll cat = (fn[i + 1] -1) / i - (fn[i] - 1) / i;
                ans += cat;
            }
 
          //  cout <<"l = " <<n + 1 <<    " r = " << fn[cnt] - 1 << endl;
          //  cout <<"res" << (fn[cnt] - 1)/ (cnt -1) - (n + 1) / (cnt - 1) << endl;
 
            ans -= (fn[cnt] - 1)/ (cnt -1) - (n) / (cnt - 1);
 
 
            printf("Case #%d: %lld\n", ca++, ans);
 
 
 
    }
}