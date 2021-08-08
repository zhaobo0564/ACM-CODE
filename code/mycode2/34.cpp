#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c, d, ans = 0;

int main(){
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    for(ll i = c; i <= d; i++){
       ll cnt = i - a;
       if(cnt < b)cnt = b - 1;
       ll len = c - cnt;
       
       if(len < 0)len = 0;
       ans += len * (b - a + 1);
       ll len1 = cnt - b + 1;
       len1 = min(len1, b - a);
      // cout << len1 << endl;
       if(len1 < 0) len1 = 0;
       ans += (b - a + b -a -len1 + 1) * len1 / 2;
       
    }
    printf("%lld\n", ans);


}