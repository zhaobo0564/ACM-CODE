#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;
const ll mod = 1e9 + 7;
vector<int> g[N];

char s[N];


ll a[N], ans[N];

ll ksm(ll x, ll y) {
    ll base = 1;
    x = x % mod;
    while (y) {
        if (y & 1) {
            base = base * x % mod;
        }
        x = x * x % mod;
        y = y / 2;
    }
    return base;
}

void dfs(int u, ll last, ll now) {
    ans[u] = (now + last + mod) % mod;
    for (int to :g[u]) {

        if (s[to] == '/') {
            ll cnt = now % mod * ksm(a[to], mod - 2) % mod;
            dfs(to, last, cnt % mod);

        } else if (s[to] == '*') {
            ll cnt = now % mod * a[to] % mod % mod;
            dfs(to, last, cnt);
        } else if (s[to] == '+') {
            dfs(to, (last + now + mod) % mod, a[to]);
        } else {
            dfs(to, (last + now + mod) % mod, -a[to]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        g[x].push_back(i);
    }
    cin >> (s + 2);
    dfs(1, 0, a[1]);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] <<  " ";
    }
    cout << endl;
}


