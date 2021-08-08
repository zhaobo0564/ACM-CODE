#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int N = 5007;

int n, m, fn[30];

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

ll dp[N][N], C[N][N];
int cat[N][N], top = 1;

ll dfs(int p, int sum, int cnt) {
    if (fn[p] > m) {
        if (sum == m) return 1;
        return 0;
    }
    if (sum > m) return 0;
    if (cnt > n) return 0;
    if (cnt * fn[p] > m) return 0;
    if (cat[p][cnt] == 0) cat[p][cnt] = top++;
    if (dp[sum][cat[p][cnt]] != -1) return dp[sum][cat[p][cnt]];
    ll ans = 0;
    ans += dfs(p, sum , cnt + 2);
    ans %= mod;
    ans += dfs(p + 1, sum + fn[p] * cnt, 0) * C[n][cnt];
    ans %= mod;


    return dp[sum][cat[p][cnt]] = ans;

}

int main() {
    solve();
    fn[0] = 1;
    for (int i = 1; i <= 20; i++) {
        fn[i] = fn[i - 1] * 2;
    }
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        C[n][i] = comb(n, i);
    }
    memset(dp, -1, sizeof(dp));
    ll ans = dfs(0, 0, 0);
    cout << ans << endl;
}