#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 7;
int n;
ll a[N], dp[N][10];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j < 5; j++){
    //         dp[i][j] = -1e8;
    //     }
    // }
    dp[0][1] = -1e12;
    dp[0][2] = -1e12;
    dp[0][3] = -1e12;
    dp[0][4] = -1e12;
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 5; j++){
            dp[i][(j + a[i]) % 5] = max(dp[i - 1][(j + a[i]) % 5], dp[i - 1][j] + a[i]);
        }
    }
    printf("%lld\n", dp[n][0]);
}