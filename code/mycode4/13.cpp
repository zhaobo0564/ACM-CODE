#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
const ll mod = 1e9 + 7;
vector<ll> g, v;

ll fn[N]; 

ll ksm(ll a, ll n){
    ll base = 1;
    while(n){
        if(n & 1)base = (base % mod * a % mod) % mod;
        a = (a % mod * a % mod) % mod;
        n = n / 2;
    }
    return base;
}

int main(){
    ll sum = 0;
    fn[0] = 1;
    for(ll i = 2; i < N; i++){
        sum = sum + i;
        fn[i - 1] = (fn[i - 2] % mod * i % mod) % mod;
        g.push_back(sum);
        v.push_back(i);
    }
    int t; scanf("%d", &t);
    while(t--){
        ll n; scanf("%lld", &n);
        int p = upper_bound(g.begin(), g.end(), n) - g.begin();
        if(p < g.size() && g[p] > n){
            p--;
        }
     //   cout << p << endl;
        if(p >= 0){
            sum = g[p];
            ll cnt = n - sum;
            if(cnt != 0){
                int p1 = upper_bound(v.begin(), v.end(), v[p] - cnt) - v.begin();
                ll ans = fn[p + 1];
                ans = (ans%mod * ksm(v[p1], mod - 2))%mod;
                ans = (ans%mod * (v[p1] + cnt) % mod)%mod;
                printf("%lld\n", ans);
            }else{
                printf("%lld\n", fn[p + 1]);
            }
            
            
        }else{
            puts("1");
        }


    }
}