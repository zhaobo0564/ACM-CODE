#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1007;

ll dp[N][N];

ll w[N],c[N];

int t, n, v;
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &v);
        for(int i = 1; i <= n; i++){
            scanf("%lld", &w[i]);
        }
        for(int i = 1; i <= n; i++){
            scanf("%lld", &c[i]);
        }
    
        
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= v; j++){
                if(j - c[i] >= 0)
                    dp[i][j] = max(dp[i - 1][j] , dp[i - 1][j - c[i]] + w[i]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        printf("%lld\n", dp[n][v]);
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= v; j++){
                dp[i][j] = 0;
            }
        }
    }
}