#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 1e6 + 7;
ll n;

int prime[N], vis[N], top = 1;

void init() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) prime[top++] = i;
        for (int j = 1; j < top && i * prime[j] < N; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

ll cnt[N];

int main() {
    init();
    cin >> n;
    for (int i = 1; i < top; i++) {
        ll p = prime[i];
        while ((n / p) > 0) {
            cnt[prime[i]] += n / p;
            p = p * prime[i];
        }
    }
    ll ans = 1;
    for (int i = 1; i < N; i++) {
        if (cnt[i]) {
            cnt[i] += cnt[i];
            ans = (ans % mod * (cnt[i] + 1) % mod) % mod;
            
        }
    }
    
    cout << ans << endl;
}