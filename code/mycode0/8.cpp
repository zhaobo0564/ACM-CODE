#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 998244353;

ll fpow(ll a, ll x){
    ll base = 1;
    while(x){
        if(x & 1){
            base = base * a % mod;
        }
        a = a * a %mod;
        x = x / 2;
    }
    return base;
}

ll C(int n, int m){
    ll res = 1;
    for(int i = n; i > n - m; i--){
        res = res * i % mod;
    }
    ll res1 = 1;
    for(int i = 1; i <= m; i++){
        res1 = res1 * i % mod;
    }
    res = res * fpow(res1, mod - 2)%mod;
    return res ;
}


int main(){
    ll n, m;
    scanf("%lld%lld", &n, &m);
    ll sum = C(m , n -1);
   // cout<<sum<<endl;
    sum = sum * fpow(2, n - 3) % mod;
    sum = sum * (n - 2) % mod;
    printf("%lld\n", sum);


  
  
  
}