#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10000007;
int n, k, a[N];

int vis[10000007], prime[N], top = 1;
map<int, int> mp;

void init() {
    for (int i = 2; i < 10000001; i++) {
        if (!vis[i]) prime[top++] = i;
        for (int j = 1; j < top && i * prime[j] < 10000007; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

void solve() {
    //vis.clear();
    cin >> n >> k;
    mp.clear();
    
    ll maxn = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    int l = 1;
    for (int i = 1; i <= n; i++) {
        int cnt = 1;
        for (int j = 1; j < top; j++) {
            if (prime[j] > a[i]  || vis[a[i]]) break;
            if (a[i] % prime[j] == 0) {
                int ct = 0;
                while (a[i] % prime[j] == 0) {
                    a[i] = a[i] / prime[j];
                    ct++;
                }
                if (ct % 2 == 1) {
                    cnt = cnt * prime[j];
                }

            }
        }
        if (a[i] > 1) {
            cnt  = cnt * a[i];
        }
        if (mp[cnt]) {
            ans++;
            mp.clear();
            mp[cnt] = 1;
        } 
        mp[cnt] = 1;

        
    }
    cout << ans + 1 << endl;
    

}

int main() {
    init();
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i < top; i++) {
        vis[prime[i]] = 1;
    }
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}