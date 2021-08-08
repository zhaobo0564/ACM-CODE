#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 1; i <= n; i++)
const int N = 2e5 + 7;

vector<int> g[N];
int n, m, p[N], fa[N];

typedef long long ll;
const ll mod = 1e9 + 7;

int cnt;

vector<ll> v;
ll sz[N];


void dfs(int u, int f) {
    sz[u] = 1;
    fa[u] = f;
    for (int it: g[u]) {
        if (it == f) continue;
        dfs(it, u);
        sz[u] += sz[it]; 
    }

}

int main() {
    int t;
    ios::sync_with_stdio(false);
    //cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }
        v.clear();
        cnt = n;
        for (int i = 1; i < n; i++) {
            int x, y; cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        cin >> m;
        for (int i = 1; i <= m; i++) {
            cin >> p[i];
        }
        dfs(1, 0);
        for (int i = n; i; i--) {
            v.push_back(1ll * sz[i] * (n - sz[i]));
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        sort(p + 1, p + m + 1);
        reverse(p + 1, p + m + 1);
        if (m > n - 1) {
            int cnt = m - (n - 1);
            ll base = 1;
            for (int i = 1; i <= cnt + 1; i++) {
                base = base * p[i];
                base %= mod;
            }
            ll ans = (base * v[0] % mod ) % mod;
            cnt += 2;
            for (int i = 1; i < v.size(); i++) {
                ans = (ans + (v[i] % mod * p[cnt++]) % mod) % mod;
            }  
            cout << ans << endl;
        } else {
            ll ans = 0;
            for (int i = 1; i <= m; i++) {
                ans = (ans + (v[i - 1] % mod * p[i] % mod) % mod) % mod;
            }
            for (int i = m; i < v.size(); i++) {
                ans = (ans + v[i]) % mod;
            }
            cout << ans << endl;
        }
    }
}