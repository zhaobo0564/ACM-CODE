#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int  t, m, n;
const int N = 1e6 + 7;

ll a[N], mod = 1e9 + 7;

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

ll C(int n, int m){  // 求c[n][m]
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
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++){
            scanf("%lld", &a[i]);
        }
        sort(a + 1, a + n + 1);
        ll ans = 1 ;
        ll Ans = a[m];
        int l = m - 1, r = m - 1;
        for(int i = m + 1; i <= n; i++){
            // (l + 1)/l- r + 1 * ans
           // cout <<"l=" << l + 1 << " r= "<< l- r + 1<<endl;
            ll cnt = (ans*(l + 1) % mod) * fpow(l - r + 1, mod - 2) % mod;
          //  cout <<" cnt= "<<cnt<<endl;
            cnt = cnt % mod;
            Ans = (Ans + cnt*a[i]%mod)%mod;
            ans = cnt;

            l++;


        }
        printf("%lld\n", Ans);
        
    }
}