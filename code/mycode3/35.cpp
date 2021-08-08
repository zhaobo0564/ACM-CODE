#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[20][20][2][2];

int up[20];

ll dfs(int p, int ok, int f, int re, int total){
    if(p == 0){
        if(ok) return total;
        return 0;
    }
    if(dp[p][total][ok][f] != -1)return dp[p][total][ok][f];
    int maxn;
    if(f) maxn = up[p];
    else maxn = 9;
    ll ans = 0;
    for(int i = 0; i <= maxn; i++){
        ans += dfs(p - 1, ok|i == re, f && i == maxn, re, i == re? total + 1: total);
    }
    dp[p][total][ok][f] = ans;
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
ll ans[10], ans1[10];

int main(){
    ll l, r;
    scanf("%lld %lld", &l, &r);
    int n = work(l - 1);
    for(int k = 0; k <= 9; k++){
        for(int i = n; i; i--){
            int maxn, f = 0;
            if(i == n)maxn = up[n], f = 1;
            else maxn = 9, f = 0;
            for(int j = 1; j <= maxn; j++){
                memset(dp, -1, sizeof(dp));
                ans[k] += dfs(i - 1, j == k, f && j == maxn, k, j == k);
            }
        }
    }
    n = work(r);
    for(int k = 0; k <= 9; k++){
        for(int i = n; i; i--){
            int maxn, f = 0;
            if(i == n)maxn = up[n], f = 1;
            else maxn = 9, f = 0;
            for(int j = 1; j <= maxn; j++){
                memset(dp, -1, sizeof(dp));
                ans1[k] += dfs(i - 1, j == k, f && j == maxn, k, j == k);
            }
        }
    }


    for(int i = 0; i <= 9; i++){
        printf("%lld ", ans1[i] - ans[i]);
    }
}