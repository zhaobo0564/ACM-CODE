#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
int fa[N];
ll a[N], p, n, cnt;
ll ans = 0;

vector<pair<int, int> > g;

int find(int x) {
    if (x != fa[x]) {
        return fa[x] = find(fa[x]);
    }
    return x;
}

void work(int pos, int f) {
    ll now = pos + f, va = a[pos];
    while (1 <= now && now <= n) {
        int gcd = __gcd(a[now], va);
        if (gcd == va) {
            int fx = find(now);
            int fy = find(pos);
            if (fx != fy) {
                fa[fx] = fy;
                ans += va;
                cnt--;
            } else {
                break;
            }
        } else {
            break;
        }
        now += f;
    }
}

void solve() {
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    g.clear();
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        g.push_back({a[i], i});
    }
    sort(g.begin(), g.end());
    cnt = n - 1;
    ans = 0;
    for (auto it: g) {
        if (it.first >= p) {
            break;
        } else {
            work(it.second, 1);
            work(it.second, -1);
        }
    }
    cout << ans + cnt * p << endl;
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}