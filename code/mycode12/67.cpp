#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e7 + 7;

int vis[N], miu[N], primes[N], cnt = 1;

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




int sum[N];

int main() {
    mobius();
    int n; cin >> n;
    for (int i = 1; i < N; i++) {
        sum[i] = sum[i - 1] + miu[i];
    }
    ll ans = 0;
    for (int j = 1; j < cnt; j++) {
        if (primes[j] > n) break;
        int cnt = n / primes[j];
        for (int i = 1, l; i <= cnt; i = l + 1) {
            l = cnt / (cnt / i);
            ans += 1ll*(sum[l] - sum[i - 1]) * 1ll*(cnt / i) * (cnt / i);
        }
    }
   
   // ans = ans * 1ll*(cnt - 1);
    cout << ans << endl;

    
    
}
