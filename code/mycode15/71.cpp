#include<bits/stdc++.h>
using namespace std;
const int N = 2007;
typedef long long ll;
int mp[N][N], a[N], n, m;
ll res = 0;

void work(int x) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (mp[x][i] == 0) {
            ans++;
        } else {
            if (ans >= m) {
                res += (ans - m + 1);
            }
            ans = 0;
        }
    }
    if (ans >= m) {
        res += (ans - m + 1);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%1d", &mp[i][j]);
        }
    }
    for (int i = 1; i <= m; i++) {
        scanf("%1d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        work(i);
    }
    cout << res << endl;
    return 0;

}