#include<bits/stdc++.h>
using namespace std;

int n, m, k, a[10007];

int dp[10007][107];

// int dfs(int total int p, int value, int f){
//     if(total == m) return value;

//     int ans = 0;
//     if(f >= k){
//        ans = max(ans, dfs(total + 1, p + 1, value + a[p + 1], 1));
//     }
//     if((m - total - 1) * k + p <= n  )
//         ans = max(ans, dfs(total, p + 1, value, f + 1));
// }


int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m;  j++){
            dp[i][j] = max(dp[i - k][j - 1] + a[j], dp[i][j]);
        }

    }
    cout << dp[n][m] << endl;
}