#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;

int dp[N], a[N], n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[i] >= a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(dp[i], ans);
    }
    ans++;
    cout << n - ans << endl;
}