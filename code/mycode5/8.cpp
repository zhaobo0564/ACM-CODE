#include<bits/stdc++.h>
using namespace std;
const int N = 500007;

typedef long long ll;

int n, q;
ll a[N];


int main(){
    scanf("%d", &n);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        ans = a[i] - ans;
    }
    scanf("%d", &q);
   // cout << ans << endl;
   if(n % 2){
        while(q--){
            int l, r;
            ll v;
            scanf("%d %d %lld", &l, &r, &v);
            if(l % 2 == 0 && r % 2 == 0){
                ans = ans - v;
            }else if(l % 2 && r % 2){
                ans += v;
            }else{

            }
            printf("%lld\n", ans);
        }
   }else{
       while(q--){
           int l, r;
            ll v;
            scanf("%d %d %lld", &l, &r, &v);
            if(l % 2 == 0 && r % 2 == 0){
                ans = ans + v;
            }else if(l % 2 && r % 2){
                ans -= v;
            }else{

            }
            printf("%lld\n", ans);
       }
      
   }
  
}