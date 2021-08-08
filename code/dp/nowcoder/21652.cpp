#include<bits/stdc++.h>
using namespace std;

const int N = 3000 + 7;

char s[N], t[N];

typedef long long ll;
int n, ls, lt;
const ll mod = 1e9 + 7;

ll dp[N][N];

ll dfs(int i, int j, int sum) {
    
    ll ans = 0;
    
    if (i > ls && j > lt) {
        if (sum == 0) return 1;
        return 0;
    }

    if (dp[i][j] != -1) return dp[i][j] % mod;
    if (sum) {
        if (j <= lt) {
            if (t[j] == ')') {
                ans = (ans + dfs(i, j + 1, sum - 1)) % mod;
            } else {
                ans = (ans + dfs(i, j + 1, sum + 1)) % mod;
            }
        }
        if (i <= ls) {
            if (s[i] == ')') {
                ans = (ans + dfs(i + 1, j, sum - 1)) % mod;
            } else {
                ans = (ans + dfs(i + 1, j, sum + 1)) % mod;
            }
        }
     
    } else {
        if (j <= lt) {
            if (t[j] == '(') {
                ans = (ans + dfs(i, j + 1, sum + 1)) % mod;
            }
        }
       
        if (i <= ls) {
            if (s[i] == '(') {
                ans = (ans + dfs(i + 1, j, sum + 1)) % mod;
            } 
        }
       
    }
    return dp[i][j] = ans;
}

int main() {
    scanf("%s %s", s + 1, t + 1);
    ls = strlen(s + 1);
    lt = strlen(t + 1);
    n = lt + ls;
    memset(dp, -1, sizeof(dp));
    cout << dfs(1, 1, 0) << endl;
}

