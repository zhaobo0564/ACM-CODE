#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

int a[N], b[N], n, q, c[N];

int vis[N];


void solve() {
    memset(vis, 0, sizeof(vis));
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }
    for (int i = 1; i <= q; i++) {
        scanf("%d", &c[i]);
    }
    sort(c + 1, c + q + 1);
    int ans = 0, pos = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (vis[j] == 0) {
                if (b[i] > b[j] && a[i] != a[j]) {
                    ans++;
                    vis[j] = 1;
                }
            }
        }
        while (pos <= q && i == c[pos]) {
            for (int j = 1; j <= i; j++) {
                b[j]++;
            }
            pos++;
        }
    }
    cout << n - ans << endl;
    
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        solve();
    }
}