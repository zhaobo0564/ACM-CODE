#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

typedef long long ll;

ll n, a[N], k, sum;

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

void init() { // 计算阶乘表
	fac[0] = 1;
	for(int i = 1;i <= 2000006; i++) {
		fac[i] = (fac[i-1]*i)%mod;
	}
}

long long comb(long long n, long long k) {
	if(k > n) return 0;
	return (fac[n]*inv(fac[k])%mod * inv(fac[n-k])%mod) % mod;
}



void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    int len = 0;
    int base = a[k];
    int pos = k;
    while (a[pos] == base) {
        pos--;
        len++;
    }

    int cnt = len;
    pos++;
    len = 0;
    while (a[pos] == base) {
        pos++;
        len++;
    }

    cout << comb(len, cnt) << endl;
    for (int i = 1; i <= n; i++) {
        a[i] = 0;
    }






}

int main() { 
    init();
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}