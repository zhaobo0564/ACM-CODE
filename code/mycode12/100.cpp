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

ll sum[N], n;

ll work(int a) {
    ll ans = 0;
    for (int i = 1, l; i <= a; i++) {
        l = a / (a / i);
        ans += (sum[l] - sum[i - 1]) * (a / i) * (a / i);
    }
    return ans;
}


int main() {
    mobius();
    for (int i = 1; i < cnt; i++) {
        sum[i] = sum[i - 1] + miu[i];
    }
    cin >> n;
    ll ans = 0;
    for (int i = 1; i < cnt; i++) {
        ans += work(n / primes[i]);
    }
    cout << ans << endl;



}