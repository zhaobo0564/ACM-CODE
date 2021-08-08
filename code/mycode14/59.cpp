#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

ll n, a[N], b[N], ans[N];

vector<ll> g[N], v;

void solve() {
    scanf("%lld", &n);
    v.clear();
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        v.push_back(a[i]);
        g[i].clear();
        ans[i] = 0;
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &b[i]);
        g[a[i]].push_back(b[i]);
    }
    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
        reverse(g[i].begin(), g[i].end());
        for (int j = 1; j < g[i].size(); j++) {
            g[i][j] += g[i][j - 1];
        }
    }

    for (int i: v) {
        int cnt = g[i].size();
        for (int j = 1; j <= g[i].size(); j++) {
            if (cnt % j == 0) {
                ans[j] += g[i][cnt - 1];
            } else {
                int cn = cnt % j;
                ans[j] += g[i][cnt - cn - 1];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld ", ans[i]);
    }
    puts("");
    
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        solve();
    }
}