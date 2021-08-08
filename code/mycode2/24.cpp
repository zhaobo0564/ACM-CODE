#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll t, n;

int main(){
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        ll mid = (n + 1) / 2;
        ll l = mid * 2 - 1;
        ll sum = 0;
        ll cnt = mid - 1;
        while(cnt){
            sum += l * cnt;
            cnt--;
            l -= 2;
        }
        sum = sum * 4;
        ll ans = (mid ) * (mid - 1);
        ans = ans * 2;
        printf("%lld\n", sum - ans);
    }
}