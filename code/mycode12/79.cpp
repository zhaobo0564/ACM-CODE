
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;


int vis[N], miu[N], primes[N], top = 1;
ll sum[N];

void mobius() {
    miu[1] = 1;
    for (int i = 2; i < N; i ++ ) {
        if (!vis[i]) {
            primes[top ++ ] = i;
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

vector<int> v;

ll work(ll x) {
    ll ans = 0;
    for (int i: v) {
        ans += miu[i] * (x / i);
    }
    return ans;
}

ll gao(int x) {
    ll ans = 0;
    while (x) {
        ans += (x % 10);
        x = x / 10;
    }
    return ans;
}

int main() {
    mobius();
    ll n; cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        v.clear();
        for (ll j = 1; j * j <= i; j++ ) {
            if (i % j == 0) {
                v.push_back(j);
                if (j != i / j)
                    v.push_back(i / j);
            }
        }
        ans += work(n) * gao(i);
        ans -= work(i - 1) * gao(i);
    }
    cout << ans << endl;

    return 0;
}