#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int t, a[N], n;

vector<int> g[N];

int main() {
    ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i <= n + 1; i++) {
            g[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int ans = 2;
        g[1].push_back(1);
        int l = 1, r = 2;
        a[n + 1] = -1;
        int cnt = 0;
        while (1) {
            while (a[r] > a[l]) {
                g[ans].push_back(a[r]);
                r++;
                l++;
            }
            a[l] = 0;
            cnt++;
            if (cnt >= g[ans - 1].size()) {
                cnt = 0;
                ans++;
            }
            if (r > n) {
                break;
            }
        }
        if (g[ans].size() == 0) ans--;
        cout << ans - 1 << endl;
    }
}