#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b;

bool judge(ll x){
    for(ll i = 2; i * i <= x; i++){
        if(x % i == 0){
            return false;
        }
    }
    if(x == 1)return false;
    return true;
}

int main(){
    scanf("%lld %lld", &a, &b);
    ll aa, bb, cc,dd;
    ll cnt = b - a; 
    int f = 10;
    if(judge(cnt)){
        printf("%lld->%lld\n", a, b);
        return 0;
    }else if(judge(b - 2)){
        
         if(judge(a - 2)){
             f = 3;
             aa = a, bb = 2, cc = b;
        }else if(judge(a + 2)){
            f = 4;
            aa = a, bb = a + 2, cc = 2, dd = b;

        }else{
            f = 6;
           // puts("Unlucky Benny");
        }
        
    }
    if(judge(b + 2)){
        if(a == 2){
            if(f == 3){
                puts("Poor Benny");
                return 0 ;
            }
            if(3 < f){
                f = 3;
                aa = a, bb  = b + 2, cc = b;
            }
            
        }else if(judge(a - 2)){
            if(f == 4){
                puts("Poor Benny");
                return 0 ;
            }
            if(4 < f){
                f = 4;
                aa = a, bb = 2, cc = b + 2, dd = 2;
            }
        

        }else if(judge(a + 2)){
            if(5 < f){
                f = 5;
                aa = a, bb = a + 2, cc = 2, dd = b + 2;
            }
        }else{
            if(f == 6)
            puts("Unlucky Benny");
            f= 6;
        }
    }else{
        if(f == 6){
           puts("Unlucky Benny"); 
           return 0;
        }
        f = 6;
        
    }
    if(f == 3){
        printf("%lld->%lld->%lld\n", aa, bb, cc);
    }else if(f == 4){
        printf("%lld->%lld->%lld->%lld\n", aa, bb, cc, dd);
    }else if(f == 5){
        printf("%lld->%lld->%lld->%lld->%lld\n", aa, bb, cc, dd, b);
    }else{
        puts("Unlucky Benny");
    }
       
}