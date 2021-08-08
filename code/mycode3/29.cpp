#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[20][20];
ll m, s;
vector<int>g;
int n;

ll dfs(int p, int sum, ll value, int f){
   // cout  << p << " " << sum << " " << value << endl;
    if(p == -1){
        if(sum == 0 )return 1;
        return 0;
    }
    if(!f && dp[p][sum] != -1){
     //   cout << "p " << p << "sum" << sum << " " << dp[p][sum] << endl;
        return dp[p][sum];
    }
    int maxn;
    if(f)maxn = g[p];
    else maxn = 9;
    ll ans = 0;
    for(int i = 0; i <= maxn; i++){
        if(i == 7 )continue;
        ans += dfs(p - 1, (sum * 10 + i) % 7, value * 10 + i, f && maxn == i);
    }
    if(!f)dp[p][sum] = ans;
    return ans;
}

ll dp1[20][4];

ll dfs1(int p, int sum, int f){
   // cout << p << " " << sum << " " << f << endl;
    if(p == -1){
        if(sum)return 1;
        return 0;
    }
    if(!f && dp1[p][sum] != -1)return dp1[p][sum];
    int maxn;
    if(f)maxn = g[p];
    else maxn = 9;
    ll ans = 0;
  //  cout <<"maxn " << maxn << endl;
    for(int i = 0; i <= maxn; i++){
        ans += dfs1(p - 1, sum | i == 7, f && i == maxn);
    }
    if(!f) dp1[p][sum] = ans;
    return ans;
}

int work(ll x){ 
    memset(dp1, -1, sizeof(dp1));
    memset(dp, -1, sizeof(dp));
    g.clear();
    while(x){
        g.push_back(x % 10);
        x = x / 10;
    }
    return g.size() - 1;
}

int main(){
    cin >> m >> s;
    n = work(m);
    ll cnt = dfs(n, 0, 0, 1) - 1;
    //printf("%lld\n", cnt);
    cnt += dfs1(n, 0, 1);
   // printf("%lld\n", cnt);
    ll l = 1, r = 1e18, ans;
    cnt += s;
    while(l <= r){
        ll mid = (l + r) / 2;
        n = work(mid);
        ll cat = dfs(n, 0, 0, 1) - 1;
        cat += dfs1(n, 0, 1);
        //cout << cat << " " << mid << endl;
        if(cat >= cnt){
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    printf("%lld\n", ans);

}