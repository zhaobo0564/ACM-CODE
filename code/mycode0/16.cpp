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

int t,n,a[107];
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int f=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(abs(a[i]-a[j])%2){
                    f=1;
                    break;
                }
            }
        }
        if(f){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }
}