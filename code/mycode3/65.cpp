#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, k, mod, mp[2007][2007];
ll fn[67];
ll cnt[2007][2007];
ll sum[2007];
int main(){
    fn[0] =  1; 
    scanf("%lld %lld %lld %lld", &n, &m, &k, &mod);
    int top = 1;
    for(int i = 1; i <= 60; i++){
        fn[i] = fn[i - 1] * k;
        top++;
        if(fn[i] > 1000000000007)break;
    }
   
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j++){
            scanf("%lld", &mp[i][j]);
            int c = lower_bound(fn, fn + top, mp[i][j]) - fn;
            cnt[i][j] = c;
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            sum[i] += cnt[i][j];
            //cout << cnt[i][j] << " ";
        }
       // cout << endl;
        ans = max(ans, sum[i]);
    }
    ll res = 1;
    for(int i = 1; i <= ans; i++){
        res = (res % mod * k % mod) % mod;
    }
    printf("%lld\n", res);

}