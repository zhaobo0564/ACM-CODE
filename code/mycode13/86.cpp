#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 100019;

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

long long C(long long n, long long k) {
	if(k > n) return 0;
	return (fac[n]*inv(fac[k])%mod * inv(fac[n-k])%mod) % mod;
}


ll Lucas(ll x, ll y, ll mod) {
    if (y == 0) return 1;
    if (y <= x && x < mod) {
        return C(x, y);
    }
    return C(x % mod, y % mod) * Lucas(x / mod, y / mod, mod) % mod;
}

int main() {
   ll n; cin >> n;
   ll ans = 0;
   solve();
   if (n == 1) {
       cout << 9 << endl;
       return 0;
   }
   for (int i = 1; i <= 9; i++) {
       ll all = 9 - i + 1;
       for (int j = 1; j <= min(all, n - 1); j++) {
           //cout << " c " << C(all, j) << " c " << Lucas(n - 2, j - 1, mod) << endl;
           ans += C(all, j) * Lucas(n - 2, j - 1, mod) % mod;
           ans = ans % mod;
       }
   }
   cout << ans << endl;
}