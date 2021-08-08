#include<bits/stdc++.h>
using namespace std;

const int N = 3007;
double a[N], dp[N][N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lf", &a[i]);
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        dp[i][0] = dp[i - 1][0] * (1 - a[i]);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i < j) break;
            dp[i][j] = (dp[i - 1][j - 1] * a[i] + dp[i - 1][j] * (1 - a[i]));
        }
    }
    double ans = 0.0;
    for(int i = 1; i <= n; i++){
        if(i * 2 > n ){
            ans += dp[n][i];
        }
    }
    printf("%.10lf\n", ans);
}