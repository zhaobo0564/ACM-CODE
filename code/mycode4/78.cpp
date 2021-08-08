#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b, c, d, e, f;

int main(){
    scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f);
    ll ans = 0;
    if(e <= f){
        ll cnt = min(b, min(c, d));
        ans = cnt * f;
        d -= cnt;
        ans += min(d, a) * e;
    }else{
        ll cnt = min(a, d);
        ans = cnt * e;
        d -= cnt;
        ans += min(b, min(c, d)) * f;
    }
    printf("%lld\n", ans);

}