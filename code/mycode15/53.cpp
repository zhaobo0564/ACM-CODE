#include <bits/stdc++.h>
using namespace std;
const int N = 807;
int a[N][N], n, k;
int mp[N][N];

bool judge(int x) {
    int base = k * k / 2;
    base = k * k - base;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] <= x) {
                mp[i][j] = 1;
            } else {
                mp[i][j] = 0;
            }
            mp[i][j] = mp[i - 1][j] + mp[i][j - 1] - mp[i - 1][j - 1] + mp[i][j];
            if (i - k + 1 > 0 && j - k + 1 > 0) {
                int sum = mp[i][j] - mp[i - k][j] - mp[i][j - k] + mp[i - k][j - k];
                
                if (sum >= base) {
                    return true;
                }
            } 
        }
    }
    return false;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    int l = 0, r = 1e9, ans = 0;
    while (l <= r) {
        int m = (l + r) / 2;
        if (judge(m)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << ans << endl;
    return 0;

}