#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

int n, a[N], pos[N];

int work(int x) {
    int cnt = 0;
    int maxn = 0;
    while (x) {
        if (x & 1) {
            maxn = max(maxn, cnt);
        }
        cnt++;
        x = x / 2;
    }
    return maxn;
}

ll vis[200];

void solve() {
    for (int i = 0; i < 40; i++) {
        vis[i] = 0;
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[i] = work(a[i]);
    }
    

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        //cout << pos[i] << " ";
        ans = ans + vis[pos[i]];
        vis[pos[i]]++;
    }
   // cout << endl;
    cout << ans << endl;




}



int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}