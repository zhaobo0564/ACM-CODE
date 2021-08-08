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
            while(x){
                a[i]--;
                x--;
                if(a[i] == 0 && x){
                    if(x <= k){
                        ans++;
                        x = m;
                    }else{
                        x -= k;
                    }
                    break;
                }else if(a[i] == 0 && x == 0){
                    x = m;
                    ans++;
                    break;
                }else if(x == 0 && a[i]){
                    ans++;
                    x = m;
                    i--;
                    break;
                }
            }
           // cout << ans << " " << x << endl;
        }
        //cout << x << endl;
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
        printf("%d\n", ans );
         
    }
}