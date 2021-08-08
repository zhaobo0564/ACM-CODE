#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 7;
int n, a[N];

int dfs(int p, int last, int now) {
    if (p > n) return !now;
    int cnt = a[p] - last - now;
    int ans = 0;
    if (cnt == 1) {
        ans += dfs(p + 1, now, 1);
    } else if (cnt == 0) {
        ans += dfs(p + 1, now, 0);
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    if (a[1] == 0) {
        ans = dfs(2, 0, 0);
    } else if (a[1] == 2) {
        ans = dfs(2, 1, 1);
    } else if (a[1] == 1) {
        ans = dfs(2, 1, 0);
        ans += dfs(2, 0, 1);
    } else {
        ans = 0;
    }
    printf("%d\n", ans);
    
}