#include<bits/stdc++.h>

using namespace std;

const int N = 5007;

typedef long long ll;

ll n, m
pair<int, int> dp[N][N][2];
const ll mod = 998244353;

pair<ll, ll> dfs(int p, int last) {
    if (p > n) return {0, 1};
    ll ans = 0, cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (i != last) {
            ll cn= dfs(p + 1, i).second;
            ans += dfs(p + 1, i).first + cn;
            cnt += cn;
            
        
        } else {
            ll cn = dfs(p + 1, i).second;
            ans += dfs(p + 1, i).first;
            cnt += cn;
            
        }
    }
    return {ans, cnt};
    
} 

int main() {
    cin >> n >> m;
    ll ans = 0, cnt = 0;
    for (int i = 1; i <= m; i++) {
        cnt = dfs(2, i).second;
        ans += dfs(2, i).first + cnt;
    }
    cout << ans << endl;
    
}