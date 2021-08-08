#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int dp[N], a[N], n, k;

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        dp[i] = 1e9;
    }
    
    dp[0] = dp[1] = 0;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(j > i - 1)break;
            dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]));
            
        }
    }
    printf("%d\n", dp[n]);
}