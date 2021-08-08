#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

int n, a[N], vis[N];

void solve() {
    cin >> n;
    for (int i = 0; i <= 100; i++) {
        vis[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vis[a[i]]++;
    }
    for (int i = 0; i <= 100; i++) {
        if (vis[i]) {
            cout << i << " ";
            vis[i]--;
        }
    }
    for (int i = 0; i <= 100; i++) {
        if (vis[i]) {
            while (vis[i]) {
                cout << i << " ";
                vis[i]--;
            }
        }
    }
    cout << endl;
   
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}