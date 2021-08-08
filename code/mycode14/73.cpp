#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll n, m, k;
vector<pair<ll, ll> >v;
const long long mod = 1e9+7;
long long fac[2000006]; // 阶乘表

long long qpow(long long x, long long n) { 
	long long res = 1; 
	for (; n; n >>= 1, x = x * x % mod) 
		if (n & 1) res = res * x % mod; 
	return res; 
}

long long inv(long long a) { // 返回逆元 费马小定理
	return qpow(a, mod-2)%mod;
}

void solve() { // 计算阶乘表
	fac[0] = 1;
	for(int i = 1;i <= 2000006; i++) {
		fac[i] = (fac[i-1]*i)%mod;
	}
}

long long comb(long long n, long long k) {
	if(k > n) return 0;
	return (fac[n]*inv(fac[k])%mod * inv(fac[n-k])%mod) % mod;
}



int main() {
    solve();
    cin >> n >> m >> k;
    v.push_back({1, 1});
    for (int i = 1; i <= k; i++) {
        int x, y; cin >> x >> y;
        v.push_back({x, y});
    }
    v.push_back({n, m});
    ll ans = 1;
    for (int i = 1; i < v.size(); i++) {
        n = abs(v[i].first - v[i - 1].first) + 1;
        m = abs(v[i].second - v[i - 1].second) + 1;

        ll cnt = comb(n + m - 2, m - 1);

        ans = ans * cnt % mod;
        ans %= mod;
    }
    cout << ans << endl;


}