//#pragma comment(linker, "/STACK:102400000,102400000") 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;
vector<pair<int, int> > g[N];

int n;
ll m;
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



vector<ll> msg_up;
vector<pair<int, int> > msg_down;

map<int, int> vis_up;

int vis[N];
void get_rt(int u, int fa) {
    sz[u] = 1;
    maxn[u] = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int to = g[u][i].first;
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
    if (cost >= m) {
        cost = cost % m;
    }
    if (fa_cost >= m) {
        fa_cost = fa_cost % m;
    }
    msg_down.push_back({cost, dep});
    msg_up.push_back(fa_cost);
    for (int i = 0; i < g[u].size(); i++) {
        int to = g[u][i].first;
        ll w = g[u][i].second;
        if (to == fa || vis[to]) continue;
        work(to, u, (cost * 1ll*10  + w) , (fa_cost + w * fn[dep] ) , dep + 1);
    }
}

void cal() {

    for (int i = 0; i < msg_up.size(); i++) {
        vis_up[msg_up[i]]--;
    }
    for (auto it: msg_down) {
        ll cnt = it.first;
        ll dep = it.second;
        cnt = (m - cnt);
        if (cnt < 0) {
            cnt = cnt + m;
        } else if (cnt >= m) {
            cnt = cnt - m;
        }
       // cout << "CNT = " << cnt << endl;
        cnt = (cnt * iv[dep]);
        if (cnt >= m) {
            cnt = cnt % m;
        }
        //cout << "cnt " << cnt << " " << vis_up[cnt] << endl;
        ans += vis_up[cnt];
    }
    for (int i = 0; i < msg_up.size(); i++) {
        vis_up[msg_up[i]]--;
    }

}



void dfs(int u, int fa) {
    msg_down.clear(), msg_up.clear();
    work(u, fa, 0, 0, 0);
    for (ll i = 0; i < msg_up.size(); i++) {
    //    cout << i << " ";
        vis_up[msg_up[i]]++;
    }
  //  cout << endl;
    msg_down.clear(), msg_up.clear();
    msg_down.push_back({0, 0});
    msg_up.push_back(0);
    cal();
   // cout << "*****\n";
    for (int i = 0; i < g[u].size(); i++) {
        int to = g[u][i].first;
        int w = g[u][i].second;
        if (to == fa || vis[to]) continue;
        msg_up.clear(), msg_down.clear();
        work(to, u, w, w, 1);
        cal();
    }
}

void gao(int u, int fa) {
    dfs(u, fa);
    vis_up.clear();
    vis[u] = 1; 
    for (int i = 0; i < g[u].size(); i++) {
        int to = g[u][i].first;
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
    scanf("%d %lld", &n, &m);
    for (int i = 1; i < N; i++) {
        fn[i] = fn[i - 1] * 10;
        fn[i] %= m;
        iv[i] = inverse(fn[i], m);

    }
    for (int i = 1; i < n; i++) {
        int u, v, w;
        //scanf("%d %d %d", &u, &v, &w);
        //u++, v++;
        u = i, v = i + 1, w = 8;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    MX = 1e8;
    get_rt(1, 0);
    //cout << "rt = " << rt << endl;
    get_rt(rt, 0);
    gao(rt, 0);
    printf("%lld\n", ans);

}