#include<bits/stdc++.h>
using namespace std;

int t, n, m, k;
int a[200];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &n, &m, &k);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        int ans = 0;
        int x = m, cnt = 0;
       for(int i = 1; i < n; i++){
          // cout << "m = " << x << " ans = " << ans << endl;
           if(x == m){
                ans += a[i] / x;
                cnt = x - a[i] % x;
                if(cnt < k){
                    ans++;
                    a[i] = 0;
                }else{
                    x = cnt - k;

                }
           }else{
               if(a[i] > x){
                   a[i] -= x;
                   ans++;
                   x = m;
                   i--;
               }else{
    
                   x -= a[i];
                   a[i] = 0;
                   if(x < k){
                       ans++;
                       x = m;
                   }else{
                       x -= k;
                   //    cout << "SAD" << x << endl;
                   }
               }
           }
       }
       if(x < a[n]){
           if(x == m){
               int cn = a[n] / x;
               ans += cn;
               if(a[n] % x){
                   ans++;
               }
           }else{
               a[n] -= x;
               ans++;
               x = m;
               int cn = a[n] / x;
               ans += cn;
               if(a[n] % x){
                   ans++;
               }

           }
       }else{
           ans++;
       }
       printf("%d\n", ans);
    }
}