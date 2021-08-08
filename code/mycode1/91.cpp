#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k;
ll mod = 1000000007;

ll ksm(ll a, ll c){
    ll base = 1;
    while(c){
        if(c & 1){
            base = (base % mod * a % mod) % mod;
        }
        c = c / 2;
        a = (a % mod * a % mod) % mod;
    }
    return base % mod;
}


int main(){
    scanf("%lld %lld %lld", &n, &m, &k);
    if(n % 2 != m % 2 && k == -1) puts("0");
    else{

    
    ll ans = ksm(2, n - 1);
    ans = ksm(ans , m - 1);
    printf("%lld\n", ans);
    }

}