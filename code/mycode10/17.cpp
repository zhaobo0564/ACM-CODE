#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int vis[40], up[40];
int top = 1;
ll dp[40][2];
vector<int> v;
ll dfs(int p, int f) {
    if (p >= v.size()) {
        return 1;
    }
    ll ans = 0;
    if (dp[p][f] != -1) return dp[p][f];
    if (f) {
        if (vis[v.size() - 1 - p] == 1) {
            if (v[p] == 0) {
                ans += dfs(p + 1, f); 
            } else {
                ans += dfs(p + 1, 0);
            }
        } else {
            if (v[p] == 1) {
                ans += dfs(p + 1, f);
                ans += dfs(p + 1, 0);

            } else {
                ans += dfs(p + 1, f);
            }
        }
    } else {
        if (vis[v.size() - 1 - p] == 1) {
            ans += dfs(p + 1, 0);
        } else {
            ans += dfs(p + 1, 0);
            ans += dfs(p + 1, 0);
        }
    }
    return dp[p][f] = ans;
    
}

int main() {
    int t; cin >> t;
    while (t--) {
        v.clear();
        ll a, x; cin >> a >> x;
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        while (a) {
            if (a & 1) {
                vis[cnt] = 1;
            }
            a = a / 2;
            cnt++;
        }
        
        while (x) {
            if (x & 1) {
                v.push_back(1);
            } else {
                v.push_back(0);
            }
            x = x / 2;
        }
        //cout << v.size() << endl;
        reverse(v.begin(), v.end());
        memset(dp, -1, sizeof(dp));
        cout << dfs(0, 1) - 1 << endl;


    }
}