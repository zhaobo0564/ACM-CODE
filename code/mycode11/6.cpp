#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
typedef long long ll;

int n, a[N], vis[200];

void solve() {
    cin >> n;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vis[a[i]]++;
    }
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        ans = max(ans, vis[i]);
       
    
    }
    cout << ans << endl;




}



int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}