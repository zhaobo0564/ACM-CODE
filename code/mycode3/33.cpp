#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b;

int up[20];
ll dp[20][200][200];

ll dfs(int p, int sum, int value, int mod, int f){
   // cout << p << endl;
    if(p == 0){
        if(sum == mod && value == 0)return 1;
        return 0;
    }
    if(!f && dp[p][sum][value] != -1) return dp[p][sum][value];
    int maxn;
    if(f) maxn = up[p];
    else maxn = 9;
    ll ans = 0;
    for(int i = 0; i <= maxn; i++){
        ans += dfs(p - 1, sum + i, (value * 10 + i) % mod, mod, f && i == maxn);
    }
    if(!f) dp[p][sum][value]= ans;
    return ans;
}

int work(ll x){
    int cnt = 0;
    while(x){
        up[++cnt] = x % 10;
        x = x / 10;
    }
    return cnt;
}


int main(){
    scanf("%lld %lld", &a, &b);
    int n = work(a - 1);
    ll ans = 0;
    for(int i = 1; i <= n * 9; i++){
        memset(dp, -1, sizeof(dp));
        ans += dfs(n, 0, 0, i, 1);
    }
    n = work(b);
    ll ans1 = 0;
    for(int i = 1; i <= n * 9; i++){
        memset(dp, -1, sizeof(dp));
        ans1 += dfs(n, 0, 0, i, 1);
    }
    printf("%lld\n", ans1 - ans);
}