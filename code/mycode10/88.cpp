#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

typedef long long ll;

ll n, a[N], b[N], k, m;

bool judge(ll x) {
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
    
        if (a[i] > 0) {
            ll cnt = x / a[i];
            if (x < 0) {
                cnt--;
            } else if (x % a[i] == 0) {
                cnt--;
            }

            int p = upper_bound(b + 1, b + m + 1, cnt) - b - 1;
         //   cout << "cnt = " << cnt << " p = " << p << endl;
            ans += 1ll * p;
        } else if (a[i] < 0) {
            ll cnt = x / a[i];
            if (cnt < 0 && x % a[i]) {
                cnt--;
            }
            int p = upper_bound(b + 1, b + m + 1, cnt) - b - 1;
            p = m - p;
         //   cout << "cnt = " << cnt << " p = " << p << endl;
            ans += 1ll * p;
        } else {
            if (x > 0) {
                ans += m;
            }
        }
        
    }
//    cout << "x = " << x << " ans = " << ans << endl;
    if (ans < k) return true;
    return false;

}

int main() {
    while (1) {

    
        scanf("%lld %lld %lld", &n, &m, &k);
        for (int i = 1; i <= n; i++) {
          //  scanf("%lld", &a[i]);
            a[i] = rand() % 5;
            int f = rand() % 2;
            if (f == 1) a[i] = -a[i];
           // cout << a[i] << " ";
        }
     //   cout << endl;
        for (int i = 1; i <= m; i++) {
          //  scanf("%lld", &b[i]);
            b[i] = rand() % 5;
            int f = rand() % 2;
            if (f == 1) b[i] = -b[i];
            //cout << b[i] << " ";
        }
      //  cout << endl;
        sort(a + 1, a + n + 1);
        sort(b + 1, b + m + 1);
        k = n * m - k + 1;
       // cout << k << endl;

        ll l = -1e12, r = 1e12;

        ll ans = 0;
        while (l <= r) {
            ll mid = (l + r) / 2;
         //   cout << "l = " << l << "r " << r << endl;
            
            if (judge(mid)) {
                //cout << "ans = " << mid << endl;
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        printf("%lld\n", ans);

        vector<int> v;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                v.push_back(a[i] * b[j]);
            }
        }
        sort(v.begin(), v.end());
        // for (int i: v) {
        //     cout << i << " ";
        // }
        cout << endl;
        cout << v[k - 1] << endl;
    }
}
/*
5 5 23
-1 4 4 3 2
0 -1 -1 0 2
*/