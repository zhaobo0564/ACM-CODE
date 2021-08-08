#include<bits/stdc++.h>
using namespace std;

string s;
int vis[200];

void solve() {
    memset(vis, 0, sizeof(vis));
    int n, k;
    cin >> n >> k;
    cin >> s;
    for (char i: s) {
        vis[i]++;
    }
    int ans = 1e8;
    for (int i = 'A'; i <= 'A' + k - 1; i++) {
        ans = min(ans, vis[i]);
    }
    cout << ans * k << endl;

}

int main() {
    ios::sync_with_stdio(0);
    int t = 1; //cin >> t;
    while (t--) {
        solve();
    }
}