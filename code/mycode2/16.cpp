#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;

long long dp[N][N][2];
long long n, p[N], t[N];

int main(){
   scanf("%lld", &n);
   for(int i = 1; i <= n; i++){
       for(int j = 1; j <= n; j++){
           dp[i][j][0] = dp[i][j][1] = INT_MAX;
       }
   }
   for(int i = 1; i <= n; i++){
       scanf("%lld", &p[i]);
   }
   for(int i = 1; i <= n; i++){
       scanf("%lld", &t[i]);
       if(t[i] == 0){
           dp[i][i][0] = 0;
           dp[i][i][1] = 0;
       }
   }
   for(int i = 1; i <= n; i++){
       for(int j = 1; j <= n; j++){
           int l = j, r = j + i;
           if(r > n)break;
           if(dp[l + 1][r][0] + p[l + 1] - p[l] <= t[l]){
               dp[l][r][0] = min(dp[l][r][0], dp[l + 1][r][0] + p[l + 1] - p[l]);
           }
           if(dp[l + 1][r][1] + p[r] - p[l] <= t[l]){
               dp[l][r][0] = min(dp[l][r][0], dp[l + 1][r][1] + p[r] - p[l]);
           }
           if(dp[l][r - 1][1] + p[r] - p[r - 1] <= t[r]){
               dp[l][r][1] = min(dp[l][r][1], dp[l][r - 1][1] + p[r] - p[r - 1]);
           }
           if(dp[l][r - 1][0] + p[r] - p[l] <= t[r]){
               dp[l][r][1] = min(dp[l][r][1], dp[l][r - 1][0] + p[r] - p[l]);
           }

       }
   }
   long long ans = min(dp[1][n][0], dp[1][n][1]);
   if(ans == INT_MAX){
       puts("-1");
   }else{
       printf("%lld\n", ans);
   }

}