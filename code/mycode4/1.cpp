#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[30];

ll ksm(ll a, ll n){
    ll base = 1;
    while(n){
        if(n & 1) base = base * a;
        a = a * a;
        n = n / 2;
    }
    return base;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        ll a, b, n;
        scanf("%lld %lld %lld", &a, &b, &n);
        ll sum = a + b;
        ll cnt = max(a, b);
        ll ans = 1;
        ll last;
        while(sum <= n){
            last = sum;
            sum = sum + cnt;
            cnt = last;
            ans++;
        }
        printf("%d\n", ans);
    }
}