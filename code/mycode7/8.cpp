#include<bits/stdc++.h>
using namespace std;

char mp[2000][2000];


int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == '.' && mp[i + 1][j] == '.') {
                ans++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            if (mp[i][j] == '.' && mp[i][j + 1] == '.') {
                ans++;
            }
        }
    }
    cout << ans << endl;
}