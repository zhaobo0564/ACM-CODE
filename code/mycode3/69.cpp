#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
char s[N];

typedef long long ll;
ll dp[20][20];
int up[20];
ll cat[N];
ll mod;
int n;

ll dfs(int p, int f, int total){
  // cout << p << " " << ok  << endl;
    if(p == 0){
        if(total)return total;
        return 0;
    }
   if(!f && dp[p][total] != -1) return dp[p][total];
    int maxn;
    if(f) maxn = up[p];
    else maxn = 9;
    ll ans = 0;
    for(int i = 0; i <= maxn; i++){
        if(i == 7){
            ans += dfs(p - 1, f && i == maxn, total + 1);
        }else{
            ans += dfs(p - 1, i == maxn && f, total);
        }
        ans = ans % mod;
    }
    if(!f) dp[p][total] = ans;
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
    mod = 1000000007;
    int t; scanf("%d", &t);
    while(t--){
        scanf("%s", s );
        memset(dp, -1, sizeof(dp));
        n = strlen(s);
        for(int i = 0; i < n; i++){
            cat[i + 1] = s[i] - '0';
        }
        ll sum = 0;
        for(int i = 1; i <= n; i++){
            sum = sum  +  cat[i];
            sum %= mod;
            if(i == n)continue;
            sum *= 10;
            sum %= mod;
        }

        n = work(sum);
       // cout << sum << endl;
        ll ans = dfs(n, 1, 0);
        printf("%lld\n", ans % mod);
    }
}