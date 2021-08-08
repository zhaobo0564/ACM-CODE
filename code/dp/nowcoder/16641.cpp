#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1007;

int m, s, t;

ll dp[300007][20];



ll dfs(int time, int sum) {
    if (time == 0) return 0;
    ll ans = 0; 
    if (dp[time][sum] != -1) return dp[time][sum];
     if (sum >= 10) {
        ans = max(ans, dfs(time - 1, sum - 10) + 60);  
    } else {
        ans = max(ans, dfs(time - 1, sum + 4));
    }
    ans = max(ans, dfs(time - 1, sum) + 17);
    
   
    return dp[time][sum] = ans;
    
}


int main () {
    memset(dp, -1, sizeof(dp));
    scanf("%d %d %d", &m, &s, &t);
     ll ans = -1, maxn = 0;
    for (int i = 1; i <= t; i++) {
        ll cnt = 0;
        if (i * 10 <= m) {
            cnt = i * 60;
        } else {
            cnt = (m / 10) * 60;
            int time = i - (m / 10);
            int cn = m % 10;

            ll cat = dfs(time, cn);
            cnt += cat;
        }
        maxn = max(cnt, maxn);
        if (cnt >= s) {
            ans = i;
            break;
        }
        
    }
    if (ans == -1) {
        cout << "No\n" << maxn << endl;
    } else {
        cout << "Yes\n" << ans << endl;
    }

}