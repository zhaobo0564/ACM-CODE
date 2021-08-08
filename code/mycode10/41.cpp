#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 7;
char s[N];
int n;

typedef long long ll;
int dp[N][N][2];

const ll mod = 1e9 + 7;

int dfs(int p, int sum, int f) {
    if (p > n) return 1;
    ll ans = 0;
    if (dp[p][sum][f] != -1) return dp[p][sum][f];
    if (s[p] == 'f') {
        if (f == 0 || sum == 0) {
            ans += 1ll*dfs(p + 1, sum + 1, 0);
        } else {
            
            ans += 1ll*dfs(p, sum - 1, 1)% mod; 
            ans += 1ll*dfs(p + 1, sum + 1, 0);
        
        }
        
    } else {
        if (f == 0 || sum == 0) {
            ans += 1ll*dfs(p + 1, sum, 1);
        } else {
            ans += 1ll* dfs(p + 1, sum, 1) % mod;
            ans += 1ll*dfs(p, sum - 1, 1)% mod;

        }
        
    }
    ans = ans % mod;
    return dp[p][sum][f] = ans;
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }    
    memset(dp, -1, sizeof(dp));
    cout << dfs(1, 0, 0) << endl;
    

  
}