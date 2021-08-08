#include<bits/stdc++.h>
using namespace std;

const int N = 1e4;

typedef long long ll;


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
ll n, k;
ll work(ll x) {
    ll res = 1;
    ll cnt = k;
    if (x > cnt) return 0;
    for (int i = 1; i <= x; i++) {
        res = res * cnt;
        res = res % mod;
        cnt--;
    }
    return res;
}


int main() {
    solve();
    cin >> n >> k;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll cnt = comb(n - 1, i);
        ans = (ans +  cnt * work(i + 1) % mod) % mod;;
    }
    cout << ans << endl;

}