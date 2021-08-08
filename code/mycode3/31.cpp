#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l, r;
int up[20];
ll dp[20][20][20][2][3][2];

ll dfs(int p, int ok, int cat, int f, int last, int llast){
   //
   //cout << "value " << value << endl;
    if(p == 0){
         //cout << p << " " << ok << " " << cat  << " " << last  <<" " << llast << endl;
        if(ok)return 1;
        return 0;
    }
    if( dp[p][last][llast][ok][cat][f] != -1) return dp[p][last][llast][ok][cat][f];
    int maxn;
    if(f) maxn = up[p];
    else maxn = 9;
    ll ans = 0;
    for(int i = 0; i <= maxn; i++){
        if(i == 4){
            if(cat == 2)continue;
            if(last == llast && last == 4){
                ans += dfs(p - 1, 1, 1, i == maxn && f, i, last);
            }else{
                ans += dfs(p - 1, ok, 1, i == maxn && f, i, last);
            }
        }else if(i == 8){
            if(cat == 1)continue;
            if(last == llast && last == 8){
                 ans += dfs(p - 1, 1, 2, i == maxn && f, i, last);
            }else{
                 ans += dfs(p - 1, ok, 2, i == maxn && f, i, last);
            }
        }else{
            if(last == llast && last == i){
                ans += dfs(p - 1, 1, cat, i == maxn && f, i, last);
            }else{
                ans += dfs(p - 1, ok, cat, i == maxn && f, i, last);
            }
        }
    }
    dp[p][last][llast][ok][cat][f] = ans;
    return ans;
}

int work(ll x){
    int cnt = 0;
    while(x){
        up[++cnt] = x % 10;
        x /= 10;
    }
    return cnt;
}

int main(){
    memset(dp, -1, sizeof(dp));
    scanf("%lld %lld",&l, &r);
    int n = work(l - 1);
    ll ans = 0;
    for(int i = 1; i <= up[n]; i++){
        if(i == 4){
            ans += dfs(n - 1, 0, 1, i == up[n], i, -1);
        }else if(i == 8){
            ans += dfs(n - 1, 0, 2, i == up[n], i , -1);
        }else{
            ans += dfs(n - 1, 0, 0, i == up[n], i, -1);
        }
    }
    //cout << ans << endl;
    if(l == 10000000000)ans = 0;   
    ll sum = 0;
    memset(dp, -1, sizeof(dp));
    n = work(r);
    for(int i = 1; i <= up[n]; i++){
        if(i == 4){
            sum += dfs(n - 1, 0, 1, i == up[n], i, -1);
        }else if(i == 8){
            sum += dfs(n - 1, 0, 2, i == up[n], i , -1);
        }else{
            sum += dfs(n - 1, 0, 0, i == up[n], i, -1);
        }
    }
   // cout << sum << endl;
   if(sum -ans < 0)puts("0");
   else printf("%lld\n", sum - ans);
}