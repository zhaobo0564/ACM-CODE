#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;

int  n, t, k;
char s[N];

int sum[N], dp[N][2];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        scanf("%s", s + 1);
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(s[i] == '1')ans++;
            sum[i] = ans;
        }
        for(int i = 1; i <= n; i++){
            int cn = 0;
            if(s[i] == '1')cn++;
            int cn1 = 0;
            if(s[i] == '0')cn1++;
            if(i - k > 0)
                dp[i][1] = min(dp[i - k][1] + sum[i - 1] - sum[i - k] + cn1, sum[i - 1]);
            else 
                dp[i][1] = cn1 + sum[i - 1];
           // cout <<"i = " << i << " "<< dp[i][1] << endl;
            dp[i][0] = min(dp[i - 1][0] + cn, dp[i - 1][1] + cn);
        }
    //    cout << dp[n][0] << endl;
        ans = min(dp[n][1], dp[n][0]);
        printf("%d\n", ans);
        
    }
}