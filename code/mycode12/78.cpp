#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;
int vis[N], miu[N], primes[N], cnt = 1, sum[N];

void mobius() {
    miu[1] = 1;
    for (int i = 2; i < N; i ++ ) {
        if (!vis[i]) {
            primes[cnt ++ ] = i;
            miu[i] = -1;
        }
        for (int j = 1; primes[j] * i < N; j ++ ) {
            int t = primes[j] * i;
            vis[t] = 1;
            if (i % primes[j] == 0) {
                miu[t] = 0;
                break;
            }
            miu[t] = miu[i] * -1;
        }
    }
}

ll work(int a, int b, int k) {
    ll ans = 0;
    a = a / k;
    b = b / k;
    int n = min(a, b);
    for (int i = 1, l; i <= n; i = l + 1) {
        int la = a / (a / i);
        int lb = b / (b / i);
        if (la > lb) {
            l = lb;
        } else {
            l = la;
        }
        ans += 1ll*(sum[l] - sum[i - 1]) * 1ll*(1ll*(a / i) * 1ll*(b / i));
    }
    return ans;
}



int main() {
    mobius();
    for (int i = 1; i < N; i++) {
        sum[i] = sum[i - 1] + miu[i];
    }
  //  cout << work(2, 2, 1);
    int t; scanf("%d", &t);
    while (t--) {
        int a, b, c, d, k;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
        ll ans = work(b, d, k);
        ll ans1 = work(a - 1, d, k);
        ll ans2 = work(b, c - 1, k);
        ll ans3 = work(a - 1, c - 1, k);
        ans = ans - ans1 - ans2 + ans3;
        printf("%lld\n", ans);

    }
    return 0;
}