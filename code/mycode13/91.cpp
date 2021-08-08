#include<bits/stdc++.h>
using namespace std;

const int N = 507;

int a[N], n, l, r, s;
int vis[N];

vector<int> v;
int cnt[N], ok = 0;

void dfs(int p, int sum) {
    if (p == 0) {
        if (sum == 0) {
            ok = 1;
            return;
        }
        return;
    }
    if (ok == 1) return;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            v.push_back(i);
            vis[i] = 1;
            dfs(p - 1, sum - i);
            if (ok) return;
            vis[i] = 0;
            v.pop_back();
        }
        if (ok) return;
    }
    if (ok) return;
}




void solve() {
    v.clear();
    cin >> n >> l >> r >> s;
    int top = 1;
    ok = 0;
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
    }
    int cnt = r - l + 1;
    int res = 0;
    for (int i = n; i >= n - cnt + 1; i--) {
        res += i;
    }
    if (s > res) {
        cout << -1 << endl;
        return;
    }
    res = 0;
    for (int i = 1; i <= cnt; i++) {
        res += i;
    }
    if (s < res) {
        cout << -1 << endl;
        return;
    }
    dfs(cnt, s);
    for (int i = 1; i <= n; i++) vis[i] = 0;
    for (int i: v) {
        vis[i] = 1;
    }

    for (int i = 1; i < l; i++) {
        for (int j = 1; j <= n; j++) {
            if (vis[j] == 0) {
                a[top++] = j;
                vis[j] = 1;
                break;
            }
        }
    }
    for (int i: v) {
        a[top++] = i;
    }
    for (int i = r + 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (vis[j] == 0) {
                a[top++] = j;
                vis[j] = 1;
                break;
            }
        }
    }
    for (int i = 1; i < top; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}