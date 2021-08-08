#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 7;
int a[N], n, vis[N];
vector<int> g;

int get_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

vector<int> v;

void solve() {
    g.clear();
    v.clear();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        g.push_back(a[i]);
        vis[i] = 0;
    }
    vis[0] = vis[n + 1] = 0;
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    for (int i = 1; i <= n; i++) {
        a[i] = get_id(a[i]);
        vis[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[a[i]]) {
            v.push_back(vis[a[i]]);
            vis[a[i]] = 0;
        }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    ll sum = 0, cnt = 0, ans = INT_MAX;
    for (int i = 0; i < v.size(); i++) {
        cnt++;
        sum += v[i];
        ll res = sum - v[i] * cnt;
        res = res + (n - sum);
        ans = min(ans, res);
        
    }
    cout << ans << endl;

}


int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }    
}