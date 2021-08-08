#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;
int a[N], top = 1;
string s;
const ll mod = 1e9 + 7;

pair<ll, ll> dp[N][2][11];

pair<ll, ll> dfs(int p, int limit, int now, int ok) {
    if (p < 1) {
        if (now == ok) {
            return {0, 1};
        }
        return {0, 0};
    }
    if (dp[p][limit][now].first != -1) return dp[p][limit][now];
    int maxn = 9;
    if (limit) {
        maxn = a[p];
    }
    ll ans = 0;
    ll cnt = 0;

    for (int i = 0; i <= maxn; i++) {
        auto it =  dfs(p - 1, limit && i == maxn, i, ok);
        ans += it.first + i * it.second;
        ans %= mod;
        cnt += it.second;
        cnt %= mod;
        
    }
    
    return dp[p][limit][now] = {ans, cnt};
}

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= 10; j++) {
            dp[i][0][j].first = dp[i][1][j].first = -1;
        }
    }
}

void work() {
    ll sum = 0;
    for (int i = 0; i < s.length(); i++) {
        a[top++] = s[i] - '0';
        sum = sum * 10 + a[top - 1];
        sum %= mod;
    }
    reverse(a + 1, a + top);
    ll ans = 0, cnt = 0;
    init();
    auto it = dfs(top - 1, 1, 0, 9);
   // cout << it.first << " " << it.second << endl;
   
    ans = it.first;
    cnt = it.second;
    
    init();
    it = dfs(top - 1, 1, 0, 0);
   // cout << it.first << " " << it.second << endl;
    ans -= it.first;
    ans = (ans + mod) % mod;
    
    sum = sum + ans - cnt;
    sum = (sum - 1 + mod) % mod;
    cout << sum << endl;


    
}

int main() {
    cin >> s;
    work();
    
}