#include<bits/stdc++.h>
using namespace std;

const int N = 2000;
typedef long long ll;
const ll mod = 1e8 + 7;
ll n, s, a, b;

ll dp[N][N];

vector<pair<int, char> >  v;

ll dfs(int p, int sum) {
    if (p <= 0) {
        if ((s - sum + n) % n == 0) {
           
            return 1;
        }
        return 0;
    }
    if (dp[p][sum] != -1) return dp[p][sum];
    ll ans = 0;
 
    ans += dfs(p - 1, (sum + a * p % n + n) % n);
    ans %= mod;
   
    ans += dfs(p - 1, (sum - b * p % n + n) % n );
    ans %= mod;
    return dp[p][sum] = ans;
}

int main() {
    cin >> n >> s >> a >> b;
    memset(dp, -1, sizeof(dp));
    s = (s + n) % n;
    cout << dfs(n - 1, 0) << endl;
    


}