#include<bits/stdc++.h>
using namespace std;
int t, n, k;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n , &k);
        long long sb = 1ll * k * k / 2;
        if(k % 2 != n % 2 ){
            printf("NO\n");
        }else if (sb > n){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
        
        
       
    }
}