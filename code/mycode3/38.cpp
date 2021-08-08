#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t ; scanf("%d", &t);
    while(t--){
       ll n; scanf("%lld", &n);
       ll ans = 0;
       ll x = n;
       ll cnt = 1;
       ll cat = 0;
       while(x){
           cat = (x + 1) / 2;
           ans +=  cat * cnt;
           x =  x - cat;
           cnt++;

       }
       printf("%lld\n",ans);
        
    }
}