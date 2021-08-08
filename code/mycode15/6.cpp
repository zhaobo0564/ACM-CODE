#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int a[N], b[N];
int n, m;

int gao(int l, int r) {
    int p = upper_bound(a + 1, a + n + 1, l) - a;
    int p1 = lower_bound(a + 1, a + n + 1, r) - a;
    return p1 - p;
}

void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++ ) {
        scanf("%d", &b[i]);       
    }
    sort(b + 1, b + m + 1);
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = max(ans, gao(b[i - 1], b[i]));
    }
    ans = max(ans, gao(b[m], 2e9));
    if (ans == 0) {
        puts("Impossible");
    } else {
        printf("%d\n", ans); 
    }
    

}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}