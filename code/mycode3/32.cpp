#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll l, r, dp[20][2][2][2];

int t, up[20];

ll dfs(int p, int zero, int zero1, int seven, int f, ll value){
    if(p == 0){
        if(zero && zero1 && seven){
            //cout << value << endl;
            return 1;
        } 
        return 0;
    }
    if(!f&&dp[p][zero][zero1][seven] != -1) return dp[p][zero][zero1][seven];
    int maxn;
    if(f) maxn = up[p];
    else maxn = 9;
    ll ans = 0;
    for(int i = 0; i <= maxn; i++){
        if(zero == 0 && i == 0){
            ans +=dfs(p - 1, 1, zero1, seven, i == maxn && f, value * 10 + i);
        }else if(zero && zero1 == 0 && i == 0){
            ans += dfs(p - 1, zero, 1, seven, i == maxn && f, value * 10 + i);
        }else if(zero && zero1 && seven == 0 && i == 7){
            ans += dfs(p - 1, zero, zero1, 1, i == maxn && f, value * 10 + i);
        }else{
            ans += dfs(p - 1, zero, zero1, seven, f && i == maxn, value * 10 + i);
        }
    }
    if(!f)dp[p][zero][zero1][seven] = ans;
    return ans;

}

int work(ll x){
    memset(dp, -1, sizeof(dp));
    int cnt = 0;
    while(x){
        up[++cnt] = x % 10;
        x = x / 10;
    }
    return cnt;
}


int main(){
    scanf("%d", &t);
    ll ans = 0;
    while(t--){
        scanf("%lld %lld", &l, &r);
        int n = work(l - 1);
        ll ans1  = 0;
        for(int i = n; i; i--){
            int maxn;
            if(i == n) maxn = up[i];
            else maxn = 9;
            for(int j = 1; j <= maxn; j++){
               // cout << i << endl;
               if(i == n)
                    ans1 += dfs(i - 1, 0, 0, 0, j == maxn , j);
                else ans1 += dfs(i - 1, 0, 0, 0, 0, 0);
            }
        }
       // cout << ans1 << endl;
        ll ans2 = 0;
        n = work(r);
        for(int i = n; i; i--){
            int maxn;
            if(i == n) maxn = up[i];
            else maxn = 9;
            for(int j = 1; j <= maxn; j++){
               // cout << i << endl;
                 if(i == n)
                    ans2 += dfs(i - 1, 0, 0, 0, j == maxn , j);
                else ans2 += dfs(i - 1, 0, 0, 0, 0, 0);
            }
        }
        //cout << ans2 - ans1 << endl;
        ans = ans ^ (ans2 - ans1);
    }
    printf("%lld\n",ans);
}