#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long  n;
int main(){
    int t; scanf("%d", &t);
    while(t--){
        scanf("%lld", &n);
        ll cnt = 0;
        int f = 0;
        while(1){         
            if(n == 1)break;
            if(n % 6 == 0){
                n = n / 6;
                cnt++;
            }else if(n % 3 == 0){
                n /= 3;
                cnt += 2;
            }else{
                f = 1;
                break;
            }
   
        }
        if(f == 1){
            puts("-1");
        }else{
            printf("%d\n", cnt);
        }


        
    }
}