#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1007][1007];
const ll mod = 1000000007;
char mp[1007][1007];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf(" %c", &mp[i][j]);
        }
    }
    dp[0][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(mp[i][j] == '#')dp[i][j] = 0;
            else{
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[n][m] << endl;
}