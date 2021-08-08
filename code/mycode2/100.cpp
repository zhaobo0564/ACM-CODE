#include<bits/stdc++.h>
using namespace std;
int n, sum, x;
const int N = 57;
int dp[N][2500][10][10];
int mod = 1000009;

int dfs(int p, int su, int pre1, int pre2){
   // cout << p << endl;
    if(dp[p][su][pre1][pre2] != -1)return dp[p][su][pre1][pre2];
    if(p == n + 1 && su == sum) return 1;
    else if(p == n + 1)return 0;
    int ans = 0;
    for(int i = 0; i <=  9; i++){
        if((pre1 * 10 + pre2 * 100+ i) % x == 0){
            ans += dfs(p + 1, su + i, i, pre1);
            ans = ans % mod;

        }
    }
    dp[p][su][pre1][pre2] = ans;
    return ans % mod;;
}

int main(){
    scanf("%d %d %d", &n, &sum, &x);
    int ans = 0;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i <= 9; i++){
        for(int j = 0; j <= 9; j++){
            ans += dfs(3, i + j, i, j);
            ans %= mod;
        }
    }
    printf("%d\n", ans);
}