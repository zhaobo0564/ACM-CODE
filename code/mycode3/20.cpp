#include<bits/stdc++.h>
using namespace std;
const int N = 1007;
int t, n, a[N], x;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &x);
        int even = 0, odd = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            if(a[i] % 2){
                odd++;
            }else{
                even++;
            }
        }
       int cnt = 0;
       if(odd % 2){
           cnt = odd;
       }else{
           cnt = odd - 1;
       }


       if(odd == 0){
           puts("No");
       }else if(even == 0 && x % 2 == 0){
           puts("No");
       }else if((x - cnt) <= even){
           puts("Yes");
       }else{
           puts("No");
       }
    }
}