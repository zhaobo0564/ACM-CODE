#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

int a[N], n, b[N], vis[N];

int cnt[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        vis[a[i]] = i;
    } 
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        if (vis[b[i]] >= i) {
            cnt[vis[b[i]] - i]++;
        }

    }
    int ans = INT_MAX;
    for (int i = 0; i <= n; i++) {

        int cn = n - cnt[i];
        ans = min(ans, cn);
    }
    cout << ans << endl;
}