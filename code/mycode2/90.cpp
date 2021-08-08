#include<bits/stdc++.h>
using namespace std;

long long dp[40][300], n;

int main(){
    scanf("%lld", &n);
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 4; j++){
            for(int z = 1; z < 200; z++){
                if(z - j >= 0){
                    dp[i][z] += dp[i - 1][z - j];
                }
            }
        }
    }
    long long ans = 3 * n;
    long long cnt = 0;
    for(long long i = ans; i < 200; i++){
        cnt += dp[n][i];
    }
    long long sum = 1ll*1 << (2 * n);
    long long g = __gcd(sum, cnt);
    printf("%lld/%lld\n", cnt / g, sum / g);

}