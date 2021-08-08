#include<bits/stdc++.h>
using namespace std;

int n, t, a[10000];

int main() {
    scanf("%d %d", &n, &t);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        if (t >= a[i]) {
            t -= a[i];
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}