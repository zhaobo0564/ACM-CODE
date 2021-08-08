#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, total;
ll n;
ll dp[20][200][200];
int up[20];

ll dfs(int p, int sum, int value, int mod, int f){
  //  cout << sum << " " <<value << " " << mod << endl;
    if(p == 0){
        if(sum == mod && value == 0) return 1;
        return 0;
    }
    if(!f && dp[p][sum][value] != -1) return dp[p][sum][value];
    int maxn;
    if(f) maxn = up[p];
    else maxn = 9;
    ll ans = 0;
    for(int i = 0; i <= maxn; i++){
        ans += dfs(p - 1, sum + i, (value * 10 + i) % mod, mod,i == maxn && f);
    }
    if(maxn == 9) dp[p][sum][value] = ans;
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
    scanf("%d", &t);
    int Case = 0;
    while(t--){
        scanf("%lld", &n);
        total = work(n);
        memset(dp, -1, sizeof(dp));
        ll ans = 0;
        for(int i = 1; i <= 128; i++){
            ans += dfs(total, 0, 0, i, 1);
            memset(dp, -1, sizeof(dp));
        }
        printf("Case %d: ", ++Case);
        printf("%lld\n", ans);
    }
}