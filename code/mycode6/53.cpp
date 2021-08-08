#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 7e5 + 7;
const ll mod = 998244353;
long long fac[N]; // 阶乘表
ll n, k;

vector<ll> g;

vector<pair<ll, ll> > cnt;

int get_id(ll x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

long long qpow(long long x, long long n) { 
	long long res = 1; 
	for (; n; n >>= 1, x = x * x % mod) 
		if (n & 1) res = res * x % mod; 
	return res; 
}

long long inv(long long a) { // 返回逆元 费马小定理
	return qpow(a, mod-2)%mod;
}

void solves() { // 计算阶乘表
	fac[0] = 1;
	for(int i = 1;i < N; i++) {
		fac[i] = (fac[i-1]*i)%mod;
	}
}

long long comb(long long n, long long k) {
	if(k > n) return 0;
	return (fac[n]*inv(fac[k])%mod * inv(fac[n-k])%mod) % mod;
}

ll x[N], vis[N];

void solve() {
    solves();
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        ll l, r; cin >> l >> r;
        g.push_back(l), g.push_back(r);
        cnt.push_back({l, r});
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());

    for (int i = 0; i < cnt.size(); i++) {
        int l = get_id(cnt[i].first), r = get_id(cnt[i].second);
        x[l]++, x[r + 1]--;
        vis[l]++;
    }
    for (int i = 1; i <= g.size() + 10; i++) {
        x[i] += x[i - 1];
    }
    ll ans = 0;
    for (int i = 1; i <= g.size() + 10; i++) {
        if (vis[i]) {
       
            ans = (ans + comb(x[i], k)) % mod;
            ans = (ans - comb((x[i] - vis[i]), k) + mod) % mod;
        }
            
    }
    cout << ans << endl;



}



int main() {
    ios::sync_with_stdio(0);
    int t = 1; //cin >> t;
    while (t--) {
        solve();
    }
}