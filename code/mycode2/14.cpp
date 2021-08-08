#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 7;

ll n, m, k;
ll mod = 998244353;
ll fn[200007];

ll ksm(ll a, int n){
    ll base = 1;
    while(n){
        if(n & 1)base = base * a % mod;
        a = a * a % mod;
        n = n / 2;
    }
    return base;
}



int main(){
    
    scanf("%lld %lld %lld", &n, &m, &k);
    ll ans = 0;
    fn[0] = 1;
    ll base = 1;
    ll cnt = 1;
    for(int i = 1; i < n ; i++){
        base = base * (n - i);
        base %= mod;
        cnt = cnt * (i);
        cnt %= mod;
        fn[i] = base * ksm(cnt, mod - 2);
        fn[i] %= mod;
        
    }
    for(int i = 0; i <= k; i++){
        ans += (m % mod * ksm(m - 1, n - i - 1)) % mod * fn[i];
        ans %= mod;
    }    
    cout << ans << endl;

}

