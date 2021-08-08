#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int a[N], n;

int main() {
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sort(a + 1, a + n + 1);
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        ans += 1ll*sum;
        sum -= a[i];
    }
    cout << ans << endl;
}