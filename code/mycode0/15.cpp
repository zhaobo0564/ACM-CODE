#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[5007] ,vis[5007];

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
    cin>>t;
    while(t--){
        scanf("%d",&n);
        for(int i = 1; i<=n;i++){
            scanf("%d",&a[i]);
        }
        int f=0;
        for(int i=1;i<=n;i++){
            if(vis[a[i]]&&a[i]!=a[i-1]){
                f=1;
                break;
            }
            if(vis[a[i]]>=2){
                f=1;
                break;
            }
            vis[a[i]]++;
        }
        if(f){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
        for(int i=1;i<=n;i++){
            vis[a[i]]=0;
        }

    }
}