#include<bits/stdc++.h>
using namespace std;

const int N = 10007;
int minn =-100000000;

int dp[N][200];

int n, m, a[N], k;

int dfs(int p, int sum){
    if(p > n){
        if(sum == m)return 0;
        return minn;
    }
    if(dp[p][sum] != minn) return dp[p][sum];
    int ans = minn;
    if(sum == m){
        return 0;
    }else{
        ans = max(ans, dfs(p + 1, sum));
        ans = max(ans, dfs(p + k, sum + 1) + a[p]);
    }
   // cout << ans << endl;
    dp[p][sum] = ans;
    return ans;
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = minn;
        }
    }
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    printf("%d\n", dfs(1, 0));
}