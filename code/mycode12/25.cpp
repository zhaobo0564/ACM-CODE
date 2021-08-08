#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 +7;

int prime[N],vis[N],top=1;

void Prime(){
    for(int i=2;i<N;i++){
        if(!vis[i])prime[top++]=i;
        for(int j=1;j<top&&prime[j]*i<N;j++){
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)break;

        }
    }
}
int n, a[N], Q;



vector<pair<int, int> > g[N];

void init() {
    for (int i = 1; i < N; i++) {
        int x = i;
        for (int j = 1; j < top; j++) {
            if (prime[j] > x || vis[x]) {
                break;
            }
            if (x % prime[j] == 0) {
                int ct = 0;
                while (x % prime[j] == 0) {
                    ct++;
                    x = x / prime[j];
                }
                g[i].push_back({prime[j], ct});
            }
        }
        if (x > 1) {
            g[i].push_back({x, 1});
        }
    }
}

struct segment{
    int minn, sum, l, r;
}tree[40 * N];

int  rt[N], o = 1;
#define m (l + r) / 2
void update(int pos, int v, int l, int r, int &node) {
    if (!node) node = o++;
    if (l == r) {
        tree[node].minn += v;
        tree[node].sum = 1;
        return;
    }
    if (pos <= m) update(pos, v, l, m, tree[node].l);
    else update(pos, v, m + 1, r, tree[node].r);
    tree[node].minn = min(tree[tree[node].l].minn, tree[tree[node].r].minn);
    tree[node].sum = tree[tree[node].l].sum + tree[tree[node].r].sum;
}
const ll mod = 1e9 + 7;

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
map<int, int> cnt;

void solve() {
    cin >> n >> Q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 0; j < g[a[i]].size(); j++) {
            int x = g[a[i]][j].first;
            int y = g[a[i]][j].second;
            update(i, y, 1, n, rt[x]);
        }
    }

    ll ans = 1;
    for (int i = 1; i < top; i++) {
        if (tree[rt[prime[i]]].sum == n) {
            int minn = tree[rt[prime[i]]].minn;
            ans = ans * ksm(prime[i], minn) % mod;
        }
    }
    while (Q--) {
        int x, y;
        cin >> x >> y;
        cnt.clear();
        for (int i = 0; i < g[y].size(); i++) {
            cnt[g[y][i].first] = tree[rt[g[y][i].first]].minn;
            update(x, g[y][i].second, 1, n, rt[g[y][i].first]);
        }
        for (int i = 0; i < g[y].size(); i++) {
            if (tree[rt[g[y][i].first]].sum == n) {
                int minn = tree[rt[g[y][i].first]].minn;
                ans =ans % mod * ksm(g[y][i].first, minn - cnt[g[y][i].first]) % mod;
                ans = ans % mod;
             }
        }
        cout << ans << endl;


    }
}

int main() {
    Prime();
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i < top; i++) {
        vis[prime[i]] = 1;
    }
    init();

    ios::sync_with_stdio(0);
    int t = 1;
    while (t--) {
        solve();
    }
}