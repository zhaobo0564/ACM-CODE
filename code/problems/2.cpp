#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll dp[40][2][2][2];

int up[40], n;

ll dfs(int p, int one, int one1, int zero, int f){
    if(p == n){
        if(one && one1 && zero)
            return 1;
        return 0;
    }
    if(!f && dp[p][one][one1][zero] != -1)return dp[p][one][one1][zero];
    int maxn;
    if(f){
        maxn = up[p];
    }else{
        maxn = 9;
    }
    ll ans = 0;
    for(int i = 0; i <= maxn; i++){
        if(one == 0 && i == 1){
            ans += dfs(p + 1, 1, one1, zero, f && i == maxn);
        }else if(one && one1 == 0 && i == 1){
            ans += dfs(p + 1, one, 1, zero, f && i == maxn);
        }else if(one && one1 && zero == 0 && i == 0){
            ans += dfs(p + 1, one, one1, 1, f && i == maxn);
        }else{
            ans += dfs(p + 1, one, one1, zero, f && i == maxn);
        }
    }
    if(!f)dp[p][one][one1][zero] = ans;
    return ans;
}

int main(){
    cin >> s;
    n = s.length();
    for(int i = 0; i < n; i++){
        up[i] = s[i] - '0';
    }
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", dfs(0, 0, 0, 0, 1));
}