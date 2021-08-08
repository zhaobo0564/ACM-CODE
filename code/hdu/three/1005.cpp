#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 7;

struct node{
    int one, two, value;
    int sum;
}fa[N];

int a[N];

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



int find(int x) {
    if (x != fa[x].value) {
        return fa[x].value = find(fa[x].value);
    }
    return x;
}

int main() {
    solve();
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }   
        ll one = 0, two = 0;
        
        for (int i = 1; i <= n; i++) {
            fa[i].value = i;
            if (a[i] == 1) {
                fa[i].one = fa[i].sum = 1;
                fa[i].two = 0;
                one++;
            } else {
                fa[i].two = fa[i].sum = 1;
                fa[i].one = 0;
                two++;
            }
        }

        ll ans = (comb(two, 2) * one ) % mod;
        ans = (ans + comb(two, 3)) % mod;
        printf("%lld\n", ans);

        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            int fx = find(u);
            int fy = find(v);
            if (fx == fy) continue;

            ll u2 = fa[fx].two;
            ll v2 = fa[fy].two;
            ll others2 = two - (u2 + v2);
            ll u1 = fa[fx].one;
            ll v1 = fa[fy].one;
            ll others1 = one - (u1 + v1);
            ll cnt = ((u2 % mod * v2 % mod) % mod * (others1 % mod)) % mod;
            cnt = (cnt + ((others2 % mod * u2 % mod) % mod * v1 % mod) % mod) % mod;
            cnt = (cnt + (((others2 % mod * v2 % mod) % mod) * u1 % mod) % mod) % mod;
            cnt = (cnt + ((u2 % mod * v2 % mod) % mod * others2 % mod) %mod) % mod;
            fa[fx].value = fy;
            fa[fy].one += fa[fx].one;
            fa[fy].two += fa[fx].two;

            ans = (ans - cnt + mod) % mod;
            printf("%lld\n", ans);
        }
        

    }
}
