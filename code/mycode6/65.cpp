#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 7;

int n, a[N], b[N];



vector<int> g[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
    for (int i = 1; i  <= n; i++) {
        cin >> a[i];
        g[a[i]].push_back(i);
        b[i] = n + 1;
    }

    for (int i = 1; i <= n; i++) {
        int last = 0;
        int mx = 0;
        for (int j = 0; j < g[i].size(); j++) {
            mx = max(g[i][j] - last, mx);
            last = g[i][j];
        }
        mx = max(mx, n + 1 - last);
        if (mx) {
            b[mx] = min(i, b[mx]);
        }
    }
    

    for (int i = 1; i < n; i++) {
        b[i + 1] = min(b[i + 1], b[i]);
    }
    for (int i = 1; i <= n; i++) {
        cout << ((b[i] == n + 1)? -1 : b[i])<< " ";
    }
    cout << endl;

    


    

}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}