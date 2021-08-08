#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200], b[200];

int n, m, k, c[20], d[20];

int ans = 0, vis[200];

void dfs(int p) {
    if (p > k) {
        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            if (vis[a[i]] && vis[b[i]]) {
                cnt++;
            }
        }
        ans = max(ans, cnt);
        return;
    }
    vis[c[p]]++;
    dfs(p + 1);
    vis[c[p]]--;
    vis[d[p]]++;
    dfs(p + 1);
    vis[d[p]]--;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> c[i] >> d[i];
    }
    dfs(1);
    cout << ans << endl;
}