#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

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

int work(int x) {
    int sum = 0;
    while (x) {
        sum += (x % 10);
        x = x / 10;
    }
    return sum;
}

ll gao(int x) {
    return (1ll*(1 + x) * 1ll*x) / 2;
}

int main() {
    ll ans = 0;
    mobius();
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        ans += miu[i] * (gao(n / i)) * work(i);
    }

}