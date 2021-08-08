#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
typedef long long ll;
const ll mod = 1e9 + 7;
int prime[N], vis[N], top = 1;
int n, a[N];

void init() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) prime[top++] = i;
        for (int j = 1; j < top && i * prime[j] < N; j++) {
            vis[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
ll cat[N];

vector<pair<int, int> > g[N];

void work(int id, int x) {
    for (int i = 1; i < top; i++) {
        if (x == 1 || x < prime[i] || vis[x] == 0) break;
        if (x % prime[i] == 0) {
            int cnt = 0;
            while (x % prime[i] == 0) {
                x = x / prime[i];
                cnt++;
            }
            g[id].push_back({prime[i], cnt});
        }
    }
    if (x > 1) {
        g[id].push_back({x, 1});
    }
}

vector<ll> ans[N];

ll res = 1;

int flag[N];

ll ksm(ll x, ll y) {
    ll base = 1;
    x = x % mod;
    while (y) {
        if (y & 1) base = base * x % mod;
        x = x * x % mod;
        y = y / 2;
    }
    return base;
}

void gao(int id) {
    for (auto it: g[id]) {
        if (it.second % 2) {
            ans[id].push_back(it.first);
        }
    }
}


int main() {
    init();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        work(i, a[i]);
        gao(i);
    }
    for (int i = 1; i <= n; i++) {
        for (ll j: ans[i]) {
            flag[j]++;
        }
    }
    for (int i = 1; i < N; i++) {
        if (flag[i] * 2 > n) {
            res = res * ksm(i, n - flag[i]) % mod;
        } else {
            res = res * ksm(i, flag[i]) % mod;
        }
    }
    cout << res << endl;
    

    

    return 0;
}