#include<bits/stdc++.h>
using namespace std;
int t;
typedef long long ll;
ll xx1, xx2, yy1, yy2;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%lld %lld %lld %lld", &xx1, &yy1, &xx2, &yy2);
        ll cnt = xx2 - xx1;
        ll cnt1 = yy2 - yy1;
        ll ans = 1;
        ans = ans + cnt1 * cnt;
        printf("%lld\n", ans);
    }
}