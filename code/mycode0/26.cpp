#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x, y;
vector<ll>v;

int main(){
    scanf("%lld%lld", &x, &y);
    int cnt = 0;
    if(x > y){
        printf("-1\n");
        return 0;
    }
    if(x == y && x == 0){
        printf("0\n");
        return 0 ;
    }
    if(x == y){
        printf("1\n");
        printf("%lld\n", x);
        return 0;

    }
    y = y - x;
    if(y % 2 == 0){
        
        ll a = x, b = y / 2, c = y / 2;
        if((a ^ b) == a + b){
            printf("2\n");
            printf("%lld %lld", a + b, c);
        }else if((a ^ c) == a + c){
            printf("2\n");
            printf("%lld %lld\n", a + c, b);
        }else if((b ^ c )== b + c){
            printf("2\n");
            printf("%lld %lld", a, b + c);
        }else{
            printf("3\n");
            printf("%lld %lld %lld", x, y/2, y/2);
        }
        
    }else{
        printf("-1\n");
    }
    
    

}
