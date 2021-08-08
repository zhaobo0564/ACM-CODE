#include<bits/stdc++.h>
using namespace std;

int dp[50000];
int a[50], n, t;
double p;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %lf", &n, &p);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        memset(dp,0,sizeof(dp));
        dp[0] = 1, dp[a[1]] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 40000; j>=0; j--){
                if(j - a[i] >= 0)
                    dp[j] =dp[j] + dp[j - a[i]];
    
            }   
           
        }
        long long sum = 1ll << n;
        double ans = 0.0;
        for(int i = 0; i <= 40000; i++){
            ans += (double)dp[i] / double(sum);
            if (ans >= p){
                printf("%d\n", i);
                break;
            }
            
        }
    }
}

