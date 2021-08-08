#include<bits/stdc++.h>
using namespace std;

double dp[100008][1000];
double mp[1000][1000];


int m, n, a[100008];

int main(){
    while(~scanf("%d", &m)){
        int cnt = 1;
        for(int i = m ; i >= m - 2; i--){
            cnt *= i;
        }
        cnt = cnt / 6;
        for(int i = 1; i <= cnt; i++){
            for(int j = 1; j <= cnt; j++){
                scanf("%lf", &mp[i][j]);
            }
        }
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            a[i]++;
        }
        double maxn = 0;
        for(int i = 1; i <= cnt; i++){
            dp[1][i] = mp[i][a[1]];
            maxn = max(dp[1][i], maxn); 
        }
        
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= cnt; j++){
                if(j != a[i - 1]){
                    dp[i][j] = dp[i-1][j] * mp[j][a[i]];
                }else{
        
                    dp[i][j] = maxn * mp[j][a[i]];
                }
            }
            maxn = 0;
            for(int j = 1; j <= cnt; j++){
                maxn = max(dp[i][j], maxn);
            }
        }
        for(int i = 1; i <= cnt; i++){
            dp[n][1] = max(dp[n][1], dp[n][i]);
        }
        // for(int i = 1; i <= cnt; i++){
        //     for(int j = 1; j <= n; j++){
        //         printf("%.6lf ", dp[j][i]);
        //     }
        //     printf("\n");
        // }

        printf("%.6lf\n", dp[n][1]);

    }
}