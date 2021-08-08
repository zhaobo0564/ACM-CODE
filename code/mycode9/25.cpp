//#pragma comment(linker, "/STACK:102400000,102400000") 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;
vector<pair<int, int> > g[N];

int n, m;
ll fn[N];

int sz[N], maxn[N], rt, MX;
ll up[N], down[N], ans, iv[N];

void extend_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    extend_gcd(b, a % b, y , x);
    y = y - x * (a / b);
}

ll inverse(ll a, ll m) {
    ll x, y;
    extend_gcd(a, m, x, y);
    return (x % m + m) % m;
}



vector<ll> msg_up, all;
vector<pair<ll, int> > msg_down;
map<int, int> vis_up, vis_down;

int vis[N];
void get_rt(int u, int fa) {
    sz[u] = 1;
    maxn[u] = 0;
    for (auto it: g[u]) {
        int to = it.first;
        if (to == fa || vis[to])continue;
        get_rt(to, u);
        sz[u] += sz[to];
        maxn[u] = max(maxn[u], sz[to]);
    }
    maxn[u] = max(maxn[u], (n - sz[u]));
    if (MX > maxn[u]) {
        MX = maxn[u];
        rt = u;
    }
}


int deep[N];

void work(int u, int fa, ll cost, ll fa_cost, int dep) {
    msg_down.push_back({cost % m, dep});
    msg_up.push_back(fa_cost % m);
    for (auto it: g[u]) {
        int to = it.first;
        int w = it.second;
        if (to == fa || vis[to]) continue;
        work(to, u, (cost * 10 % m + w) % m, (fa_cost + w * fn[dep] % m) % m, dep + 1);
    }
}

void cal() {

    for (ll i: msg_up) {
        vis_up[i]--;
    }
    for (auto it: msg_down) {
        ll cnt = it.first;
        ll dep = it.second;
        cnt = (m - cnt + m) % m;
       // cout << "CNT = " << cnt << endl;
        cnt = cnt * iv[dep] % m;
        //cout << "cnt " << cnt << " " << vis_up[cnt] << endl;
        ans += vis_up[cnt];
    }
    for (ll i: msg_up) {
        vis_up[i]++;
    }

}



void dfs(int u, int fa) {
    msg_down.clear(), msg_up.clear();
    work(u, fa, 0, 0, 0);
    for (ll i: msg_up) {
    //    cout << i << " ";
        vis_up[i]++;
    }
  //  cout << endl;
    msg_down.clear(), msg_up.clear();
    msg_down.push_back({0, 0});
    msg_up.push_back(0);
    cal();
   // cout << "*****\n";
    for (auto it: g[u]) {
        int to = it.first;
        int w = it.second;
        if (to == fa || vis[to]) continue;
        msg_up.clear(), msg_down.clear();
        work(to, u, w, w, 1);
        cal();
    }
}

void gao(int u, int fa) {
    vis[u] = 1;
    dfs(u, fa);
    vis_up.clear(); 
    for (auto it: g[u]) {
        int to = it.first;
        if (to == fa || vis[to]) continue;
        n = sz[to];
        MX = 1e8;
        get_rt(to, u);
        get_rt(rt, 0);
       // cout << "rt = " << rt << endl;
        gao(rt, 0);
    }
}



int main() {
    fn[0] = 1;
    scanf("%d %d", &n, &m);
    for (int i = 1; i < N; i++) {
        fn[i] = fn[i - 1] * 10;
        fn[i] %= m;
        iv[i] = inverse(fn[i], m);

    }
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u++, v++;
       // u = i, v = i + 1, w = 8;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    MX = 1e8;
    get_rt(1, 0);
    get_rt(rt, 0);
    //cout << "rt = " << rt << endl;
    gao(rt, 0);
    printf("%lld\n", ans);

}