#include<bits/stdc++.h>
using namespace std;

int dp[3007][3007];

int n, m, mp[3007][3007];

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &mp[i][j]);
        }
    }
    dp[n][0] = 1;
    for(int i = n; i; i--){
        for(int j = 1; j <= m; j++){
            if(mp[i][j]){
                dp[i][j] = 0;
            }else{
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1];
                dp[i][j] %= 2333;
            }
        }
    }

    printf("%d\n", dp[1][m] % 2333);
}