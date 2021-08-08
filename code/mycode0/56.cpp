#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll a, b;
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%lld %lld", &a, &b);
        if(a % b == 0){
            printf("0\n");
        }else{
            ll cnt = a / b;
            b = b * (cnt + 1);
            printf("%lld\n", b - a);
        }
    }
}