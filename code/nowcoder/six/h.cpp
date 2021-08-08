#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100 + 7;
ll dp[N][2000][2][2][2];
int up[N], n;

const ll mod = 1e9 + 7;

ll dfs(int p, int sum, int f, int f1,int ok) {
   if (p == n) {
       if (ok && sum > 1000) {
           return 1;
       } 
       return 0;
   }
   if (dp[p][sum][f][f1][ok] != -1) return dp[p][sum][f][f1][ok];
   int maxn, maxn1;
   if (f) {
       maxn = up[p];
   } else {
       maxn = 9;
   }
   if (f1) {
       maxn1 = up[p];
   } else {
       maxn1 = 9;
   }
   ll ans = 0;
   for (int i = 0; i <= maxn; i++) {
       for (int j = 0; j <= maxn1; j++) {
            if (!ok && i > j) continue;
            ans = (ans + dfs(p + 1, sum + i - j, f && i == maxn, f1 && j == maxn1, ok | (j > i? 1: 0)));
            ans = ans % mod;
       }
   }
   return dp[p][sum][f][f1][ok] = ans;
    
}

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        up[i] = s[i] - '0';
    }
    n = s.length(); 
    memset(dp, -1, sizeof(dp));
    ll ans = dfs(0, 1000, 1, 1, 0);
   
    printf("%lld\n", ans);
    



}

