#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 1; i <= n; i++)
const int N = 2e5 + 7;

int t, n, m, a[N], b[N];
vector<int> g;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        g.clear();
        cin >> n;
        int minn = INT_MAX;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b[i] = a[i];
            minn = min(minn, a[i]);
        }
        sort(b + 1, b + n + 1);
        int f = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] != b[i]) {
                g.push_back(a[i]);
            }
        }
        if(g.size() == 0) {
            cout << "YES\n";
            continue;
        }
        int ans = minn;
        for (int i = 0; i < g.size(); i++) {
            int cnt = __gcd(ans, g[i]);
            if (cnt != minn) {
                f = 1;
                break;
            }
        }
        if (f) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
        
    }
}