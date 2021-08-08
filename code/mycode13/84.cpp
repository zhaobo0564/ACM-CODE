#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
#define int long long
vector<int> g[N];

void init() {
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i ) {
            if (i * i <= j) {
                if (i != j)
                    g[j].push_back(i);
                if (j / i != i) {
                    if (j != j / i)
                        g[j].push_back(j / i);
                }
            } 
        }
    }
   
}
const long long mod = 998244353;
long long dp[N][22];

long long dfs(int u, int d) {
  //  cout << "to = " << u << " d = " <<d  << endl;
    if (d == 0) return 1;
    long long ans = 0;
    if (dp[u][d] != -1) return dp[u][d]; 
    for (int to: g[u]) {
        ans += dfs(to, d - 1);
        ans %= mod;
    }
    return dp[u][d] = ans;
}

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
	for(int i = 1;i < 2000006; i++) {
		fac[i] = (fac[i-1]*i)%mod;
	}
}

long long comb(long long n, long long k) {
	if(k > n) return 0;
	return (fac[n]*inv(fac[k])%mod * inv(fac[n-k])%mod) % mod;
}



int32_t main() {
    init();
    solve();
    int n, m;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
   // cout << dfs(10, 4) << endl;;
    long long ans = 0;
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= m; j++) {
            long long cnt = dfs(j, i - 1);
            //cout << "j = " << j << " i = " << i << " cnt " << cnt << endl;

            ans += cnt % mod * comb(n - 1, i - 1) % mod;
            ans %= mod;
        }
    }
    cout << ans << endl;


}