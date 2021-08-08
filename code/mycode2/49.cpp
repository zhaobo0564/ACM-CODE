#include<bits/stdc++.h>
using namespace std;
const int N = 500;
int dp[N][N][N];
  
int n, k;
char s[N];
  
  
int main(){
    scanf("%d %d", &n, &k);
    scanf("%s", s + 1);
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k <= n; k++)
                dp[i][j][k] = 1e8;
        }
    }
    for(int i = 0; i <= n; i++)dp[i][0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j ; j--){
            for(int k = 1; k <= j; k++){
                if(s[i] == '0'){
					dp[i][j][k] = dp[i - 1][j][k];
                    dp[i][j][0] = min( dp[i][j][0], min(dp[i - 1][j][0], dp[i - 1][j][k]));
                   
                    
                }else{
                    dp[i][j][0] = min( dp[i][j][0], min(dp[i - 1][j][0], dp[i - 1][j][k]));
                    dp[i][j][k] = min(dp[i - 1][j][k], dp[i - 1][j - 1][k - 1] + k);
                    
                }
            }
        }
    }

    for(int i = n ; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            if(dp[n][i][j] <= k){
                printf("%d\n", i);
                return 0;
            }
        }
    }
     
  
  
}