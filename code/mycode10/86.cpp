#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
int vis[507];

inline void write(__int128 x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}

void solve() {
    cin >> n >> k;
    memset(vis, 0, sizeof(vis));
    for (int i = 2 * k; i <= n; i += k) {
        int minn = 1e7;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                if (j > k) {
                    if (j % k == 0) {
                        minn = min(minn, j / k);
                    } else {
                        minn = min(minn, j);
                    }
                }
            }
        }
        vis[minn] = 1;
    }
    __int128 ans = k;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            ans = ans * 1ll * i;
        }
    }
    write(ans);
    puts("");

}


int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}