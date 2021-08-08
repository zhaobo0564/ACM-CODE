#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
bool judge(ll m){
    ll cnt = m / n;
    cnt = m - cnt;
    if(cnt >= k)return true;
    return false;
}

int main(){
    int t;
    
    scanf("%d", &t);
    while(t--){
        scanf("%lld %lld", &n, &k);
        ll ans , l = 1, r = 1e18;
        while(l <= r){
            ll m = (l + r) / 2;
            if(judge(m)){
                ans = m;
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        printf("%lld\n", ans);


    }
}