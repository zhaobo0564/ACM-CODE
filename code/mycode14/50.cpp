#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500 + 7;

int a[N], mp[N][N];

bool work(int x, int y, int cnt, int base) {
    while (1) {
        if (cnt == 0) break;
        if (mp[x][y - 1] == 0) {
            mp[x][y - 1] = base;
            cnt--;
            y--;
        } else if (mp[x + 1][y] == 0) {
            mp[x + 1][y] = base;
            cnt--;
            x++;
        } else if (y + 1 < x&& mp[x][y + 1] == 0) {
            mp[x][y + 1] = base;
            cnt--;
            y++;
        } else if (cnt) {
            return false;
        }
    }
    return true;
   
}

void solve() {
    int n; cin >> n;
    memset(mp, -1, sizeof(mp));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[i][i] = a[i];
    }
    
    for (int i = 1; i <= n; i++) {
        int cnt = a[i] - 1;
        if (work(i, i, cnt, a[i])) {

        } else {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << mp[i][j] << " ";
        }
        cout << endl;
    }

}

int main() {
    ios::sync_with_stdio(0);
    int t = 1;
    while (t--) {
        solve();
    }
}