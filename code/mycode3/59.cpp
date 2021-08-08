#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[300], n;
ll a[300], fn[300];

int main(){
    fn[0] = 1;
    for(int i = 1; i <= 32; i++){
        fn[i] = fn[i - 1] * 2;
    }
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        dp[i] = 1e15;
    }
    dp[1] = 0;
    for(int i = 2; i <= n; i++){
        if(a[i] - a[i - 1] == 1){
            dp[i] = dp[i - 1] + 1;
        }
        for(int j = i - 1; j; j--){
            for(int k = 1; k < min(j, 32); k++){
                if(fn[k] + a[j - k] >= a[i]){
                    dp[i] = min(dp[i], dp[j] + k + 1);
                }
            }
        }
    }
    if(dp[n] > 1e8){
        puts("-1");
    }else{
        printf("%lld\n", dp[n]);
    }

}