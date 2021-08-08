#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e3 + 7;
ll c[N][N];
const ll mod = 998244353;

void C() {
    int i,j;
    for(i=0;i<N;i++)
        c[i][0]=c[i][i]=1;
    for(i=1;i<N;i++)
        for(j=1;j<=i;j++)
            c[i][j] = (c[i-1][j]+c[i-1][j-1]) % mod;
}

int n, m;

ll dp[N][N];

ll dfs(int p, int k) {
    if (p > n) return 1;
    if (k >= m) return 1;
    if (dp[p][k] != -1) return dp[p][k];
    ll ans = 0;
    ans = ans + dfs(p + 1, k);
    ans %= mod;
    ans = ans + dfs(p + 1, k + 1) * c[m - k][1] % mod;
    ans %= mod;
    return dp[p][k] = ans;
}

int main() {
    C();
    cin >> n >> m;
    memset(dp, -1,sizeof(dp));
    cout << dfs(1, 0) << endl;

}