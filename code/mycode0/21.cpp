#include<bits/stdc++.h>
using namespace std;
const int N = 2007;
long long dp[N][N];
long long a[N], n, h, l, r;

int main(){
    scanf("%lld%lld%lld%lld",&n, &h, &l, &r);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    memset(dp,-0x3f3f3f3f,sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0 ; j <= h ;j++){
            if((j + a[i]) % h >= l && (j + a[i]) % h <= r){
                dp[i][(j + a[i]) % h] = max(dp[i][(j + a[i]) % h], dp[i - 1][j] + 1);
            }else{
                dp[i][(j + a[i]) % h] = max(dp[i][(j + a[i]) % h], dp[i - 1][j]);
            }
            a[i]--;
            if((j + a[i]) % h >= l && (j + a[i]) % h <= r){
                dp[i][(j + a[i]) % h] = max(dp[i][(j + a[i]) % h], dp[i - 1][j] + 1);
            }else{
                dp[i][(j + a[i]) % h] = max(dp[i][(j + a[i]) % h], dp[i - 1][j]);
            }
            a[i]++;
        }
    }
    long long ans = 0;
    for(int i = 0; i < h; i++){
        ans = max (ans, dp[n][i]);
    }
    printf("%lld\n", ans);
}