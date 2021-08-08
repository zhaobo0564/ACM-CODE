#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod;

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

const int N = 3e6 + 7;
ll sum[N];


int main(){
    mod = 1000000007;
   // build(1, N - 1, 1);
    int t; scanf("%d", &t);
    sum[0] = 1; 
    for(int i = 1; i < N; i++){
        sum[i] = (sum[i - 1] % mod * i % mod) % mod; 
    }
    while(t--){
        int n, mm;
        scanf("%d %d", &n, &mm);
        n--, mm--;
        int ans = n + mm;
      // cout << "l " << sum[ans] << " r " << sum[ans - mm ] << endl;
        ll cnt1 = (sum[ans] % mod) * (fpow(sum[ans -mm ], mod - 2) % mod) % mod;
        ll cnt2 = sum[mm];
      //  cout << cnt1 << " " << cnt2 << endl;
        ll res = (cnt1 % mod) * (fpow(cnt2, mod - 2) % mod);
        printf("%lld\n", res % mod);

        
    }
}