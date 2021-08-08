#include<bits/stdc++.h>
using namespace std;
const int N = 2007;

int n, a[N];

int main(){
    scanf("%d", &n);
    int odd = 0, even = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if(a[i] % 2){
            odd++;
        }else{
            even++;
        }
    }
    if(odd == even){
        puts("0");
    }else if(abs(odd - even) == 1){
        puts("0");
    }else{
       sort(a + 1 , a + n + 1);
       int ans = 0;
       if(odd > even){
           int cnt = odd - even - 1;
           
           
           for(int i = 1; i <= n; i++){
               if(a[i] % 2){
                   ans += a[i];
                   cnt--;
               }
               if(cnt == 0)break;
           }
       }else{
           int cnt =even - odd - 1;
           for(int i = 1; i <= n; i++){
               if(a[i] % 2 == 0){
                   ans += a[i];
                   cnt--;
               }
               if(cnt == 0)break;
           }
       }
       printf("%d\n", ans);
    }
}