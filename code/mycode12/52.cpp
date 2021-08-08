#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, q;
const int N = 2e5 + 7;

ll inv[N][5];
void init(ll mod, int id) {
      
    inv[1][id] = 1;
    for(ll i = 2; i < N; i++)
        inv[i][id] = inv[mod % i][id] * (mod - mod / i + mod) % mod;

}

long long fac[200006][5]; // 阶乘表


long long in(long long a, ll mod, int id) { // 返回逆元 费马小定理
	return inv[a][id] % mod;
}

void solve(ll mod, int id) { // 计算阶乘表
	fac[0][id] = 1;
	for(int i = 1;i < 200006; i++) {
		fac[i][id] = (fac[i-1][id]*i)%mod;
	}
}

long long comb(long long n, long long k, ll mod, int id) {
	if(k > n) return 0;
	return (fac[n][id]*in(fac[k][id], mod, id)%mod * in(fac[n-k][id], mod, id)%mod) % mod;
}

ll Lucas(ll x, ll y, ll mod, int id) {
    if (y == 0) return 1;
    if (y <= x && x < mod) {
        return comb(x, y, mod, id);
    }
    return comb(x % mod, y % mod, mod, id) * Lucas(x / mod, y / mod, mod, id) % mod;
}

void ex_gcd(ll a,ll b,ll &d,ll &x,ll &y) {
    if(b==0){
        d=a;
        x=1,y=0;
    }
    else{
        ex_gcd(b,a%b,d,y,x);
        y-=(a/b)*x;
    }
}
//中国剩余定理
// m为是模数， a是余数
ll China(int n,ll *m,ll *a) {
    ll M=1,d,y,x=0;
    for(int i=0;i<n;i++) M*=m[i];
    for(int i=0;i<n;i++){
        ll w=M/m[i];
        ex_gcd(m[i],w,d,d,y);
        x=(x+y*w*a[i])%M;
    }
    return (x+M)%M;
}

ll work(ll i) {
    ll a[5];
    a[0] = Lucas(n, i, 2, 1);
    a[1] = Lucas(n, i, 3, 2);
    a[2] = Lucas(n, i, 4679, 3);
    a[3] = Lucas(n, i, 35617, 4);

    ll m[] = {2, 3, 4679, 35617};
    ll x = China(4, m, a);
    return x;
}

ll ksm(ll x, ll y, ll mod) {
    ll base = 1;
    x = x % mod;
    while (y) {
        if (y & 1) {
            base = base * x % mod;
        }
        x = x * x % mod;
        y = y / 2;
    }
    return base;
}

int main() {
    cin >> n >> q;
    if (q % 999911659 == 0) {
        cout << 0 << endl;
        return 0;
    }
    init(2, 1);
    init(3, 2);
    init(4679, 3);
    init(35617, 4);
    solve(2, 1);
    solve(3, 2);
    solve(4679, 3);
    solve(35617, 4);
    ll ans = 0;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
           ans += work(i);
           if (n / i != i) {
              ans += work(n / i);
           }
           ans = ans % 999911658;
        }
    }
 
    cout << ksm(q, ans, 999911659) << endl;
    return 0;


}