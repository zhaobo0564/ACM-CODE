#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], dp[N][2];

int main(){
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    dp[2][0] = abs(a[2] - a[1]);
    //cout << dp[2][0] << endl;
    dp[2][1] = 1e8;
    for(int i = 3; i <= n; i++){
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1])+ abs(a[i] - a[i - 1]);
        dp[i][1] = min(dp[i - 2][0], dp[i - 2][1]) + abs(a[i] - a[i - 2]);
      // cout << dp[i][0] << " " << dp[i][1] << endl;
    }
    printf("%d\n", min(dp[n][0], dp[n][1]));


}