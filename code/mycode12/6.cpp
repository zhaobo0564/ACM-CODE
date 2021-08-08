#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;

const int M = (int)5e6;
const int N = (int)1e3;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;

int n, m;
string k;
string s[40];
int sz[41];

int p[M + 5];
int mod = (int)1e9 + 7;
vector<int> h[41];

void init()
{
    sz[n] = k.size();
    p[0] = 1;
    for(int i = 1; i <= sz[n]; ++i)
    {
        p[i] = 1ll * p[i - 1] * 27 % mod;
    }
    for(int i = 0; i < n; ++i)
    {
        sz[i] = s[i].size();
        h[i].resize(sz[i] + 1);
        for(int j = 1; j <= sz[i]; ++j)
        {
            h[i][j] = (1ll * h[i][j - 1] * 27 + s[i][j - 1] - 'a' + 1) % mod;
        }
    }
    h[n].resize(sz[n] + 1);
    for(int j = 1; j <= sz[n]; ++j)
    {
        h[n][j] = (1ll * h[n][j - 1] * 27 + k[j - 1] - 'a' + 1) % mod;
    }
}

int getH(int u, int l, int r)
{
    return ((h[u][r] - 1ll * h[u][l - 1] * p[r - l + 1]) % mod + mod) % mod;
}

int mp[M + 5];

void dfs1(int u, int len, int h0)
{
    if(u == m)
    {
        mp[len]++;
        return;
    }
    dfs1(u + 1, len, h0);
    if(len + sz[u] <= sz[n])
    {
        int h2 = (1ll * h0 * p[sz[u]] + getH(u, 1, sz[u])) % mod;
        if(h2 == getH(n, 1, len + sz[u]))
            dfs1(u + 1, len + sz[u], h2);
    }
}



ll ans = 0;

void dfs2(int u, int len, int h0)
{
    if(u == m - 1)
    {
        ans += mp[sz[n] - len];
//        mp[1][len]++;
        return;
    }
    dfs2(u - 1, len, h0);
    if(len + sz[u] <= sz[n])
    {
        int h2 = (1ll * getH(u, 1, sz[u]) * p[len] + h0) % mod;
        if(h2 == getH(n, sz[n] - (len + sz[u]) + 1, sz[n]))
            dfs2(u - 1, len + sz[u], h2);
    }
}

void work()
{
    cin >> n >> k;
    for(int i = 0; i < n; ++i) cin >> s[i];
    init();
    m = n / 2
    dfs1(0, 0, 0);
    dfs2(n - 1, 0, 0);
//    ll ans = 0;
//    for(auto x: mp[0])
//    {
//        ans += 1ll * x.second * mp[1][sz[n] - x.first];
//    }
    cout << ans << "\n";
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    int T; scanf("%d", &T);
//    while(T--) work();
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}
