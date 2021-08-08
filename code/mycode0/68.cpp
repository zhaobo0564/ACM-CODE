#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a, b, c;

int main(){
    while(~scanf("%lld%lld%lld", &a, &b, &c)){
        ll cnt = 0, sum = a + b +c;
        ll ans;
        if(a >= 2 && b >= 2 && c >= 2){
            ans = 15 +(sum - 6) * 6;
        }else if(a >= 2 && b >= 2 && c == 1){
            ans = 10 + (sum - 5) * 5;
        }else if(a >= 2 && b >= 2 && c == 0){
            ans = 6 + (sum - 4) * 4;
        }else if(a == 1 && b >= 2 && c >= 2){
            ans = 10 + (sum - 5) * 5;
        }else if (a == 0 && b >= 2 && c >= 2){
            ans = 6 + (sum - 4) * 4;
        }else if(a >= 2 && b == 1 && c >= 2){
            ans = 10 + (sum - 5) * 5;
        }else if(a >= 2 && b == 0 && c >= 2){
            ans = 6 + (sum - 4) * 4;
        }else if (a >= 2 && b == 1 && c == 1){
            ans = 6 + (sum - 4) * 4;
        }else if(a >= 2 && b ==  1 && c == 0){
            ans = 3 + (sum - 3) * 3;
        }else if(a >= 2 && b== 0 && c == 1){
            ans = 3 + (sum - 3) * 3;
        }else if(a >= 2 && b == 0 && c == 0){
              ans = 1 + (sum - 2) * 2;
        }else if(a == 1 && b >= 2 && c== 1){
            ans = 6 + (sum - 4) * 4;
        }else if(a == 0 && b >= 2 && c == 1){
            ans = 3 + (sum - 3) * 3;
        }else if(a == 0 && b >= 2 && c == 0){
            ans = 1 + (sum - 2) * 2;
        }else if(a == 1 && b >= 2 && c == 0){
            ans = 3 + (sum - 3) * 3;
        }else if(a == 1 && b == 1 && c >= 2){
             ans = 6 + (sum - 4) * 4;
        }else if(a == 0 && b == 1 && c >= 2){
             ans = 3 + (sum - 3) * 3;
        }else if (a == 1 && b == 0 && c>= 2){
             ans = 3 + (sum - 3) * 3;
        }else if(a == 0 && b == 0 && c>=2){
            ans = 1 + (sum - 2) * 2;
        }else if (a == 1 && b == 1 && c== 1){
            ans = 3;
        }else if(a == 1 && b == 1 && c == 0){
            ans = 1;
        }else if(a == 1 && b == 0 && c == 0){
            ans = 0;
        }else if(a == 0 && b == 1 && c == 1){
            ans = 1;
        }else if(a == 0 && b == 1 && c == 0){
            ans = 0;
        }else if(a == 0 && b == 0 && c == 0){
            ans = 0;
        }else if (c == 1 && a == 1 && b == 0){
            ans = 1;
        }else if(c ==  1 && a == 0 && b == 0){
            ans = 0;
        }
        printf("%lld\n", ans);


    }
}