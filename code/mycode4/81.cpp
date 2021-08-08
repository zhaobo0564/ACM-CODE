#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sum[1000000];
ll n, k;

bool judge(ll m){
    ll cnt = 1;
    ll x = 2 * m;
    while(x <= n){
        cnt++;
        if(x + 1 <= n){
            cnt++;
        }
        x = x * 2;
    }
    x = (m + 1);
    if(x <= n)cnt++;
    x = x * 2;
    while(x <= n){
        cnt++;
        if(x + 1 <= n){
            cnt++;
        }
        x = x * 2;
    }
    return cnt >= k;
}

bool judge1(ll m){
    ll cnt  = 1;
    if(m == 1)return true;
    m = m * 2;
    while(m <= n){
        cnt++;
        if(m + 1 <= n)cnt++;
        m = m * 2;
    }
    return cnt >= k;
}

int main(){
    scanf("%lld %lld", &n, &k);

    ll l = 2, r = (n / 2) * 2;
    ll ans = 0;
    while(l <= r){
        ll m = (l + r) / 2;
        if(m % 2)m++;
        if(judge(m)){
            ans = m;
            l = m + 2;
        }else{
            r = m - 2;
        }
    }   
    l = 1;
    if(n  % 2 == 0){
        r = n - 1;
    }else{

        r = n;
    }
 //   cout << judge1(5) << endl;
   // cout << l <<" " << r << endl;
    while(l <= r){
        ll m = (l + r) / 2;
        if(m % 2 == 0)m++;
     //   cout << m << endl;
        if(judge1(m)){
            ans = max(ans, m);
            l = m + 2;
        }else{
            r = m - 2;
        }
    }
    printf("%lld\n", ans);

}