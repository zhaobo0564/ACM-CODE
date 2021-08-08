#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int a[N], n, vis[N];

vector<int> ans;

void solve() {
    ans.clear();
    cin >> n;

    for (int i = 1; i <= n; i++) vis[i] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vis[a[i]]++;
    }
    sort(a + 1, a + n + 1);
    ans.push_back(a[n]);
    int sum = a[n];
    vis[a[n]]--;
    int l = 0;
    for (int i = 2; i <= n; i++) {
        int maxn = 0;
        for (int j = n; j; j--) {
            if (vis[a[j]] == 0) continue;
            int cnt = __gcd(sum, a[j]);
            maxn = max(maxn, cnt);
        }
         for (int j = n; j; j--) {
            if (vis[a[j]] == 0) continue;
             int cnt = __gcd(sum, a[j]);
           //  cout << cnt << " "<< a[j] << endl;
            if (cnt == maxn) {
                ans.push_back(a[j]);
                sum = __gcd(sum, a[j]);
                vis[a[j]]--;
                break;
            }
        }
    }
    
    for (int i: ans) {
        cout << i << " ";
        vis[i] = 0;
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