#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[100];
int n;
ll dp[10];
ll mod = 1e9 + 7;

int main(){
    scanf("%s", s + 1);
    n = strlen(s + 1);

    for(int i = 1; i <= n; i++){
        if((s[i] - '0') % 3 == 0){
            dp[0] += dp[0] + 1;
            dp[2] += dp[2];
            dp[1] += dp[1];
        }else if((s[i] -'0') % 3 == 1){
            ll temp = dp[0];
            dp[0] += dp[2];
            dp[2] += dp[1];
            dp[1] += temp + 1;
        }else{
            ll temp = dp[0];
            dp[0] += dp[1];
            dp[1] += dp[2]; 
            dp[2] += temp + 1;
        }
        dp[0] %= mod;
        dp[1] %= mod;
        dp[2] %= mod;
    }
    printf("%d\n", dp[0]);
}