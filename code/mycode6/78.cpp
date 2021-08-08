#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

int n, a[N], b[N], c[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    vector<int> ans;

    ans.push_back(a[1]);
    int last = 0;
    for (int i = 2; i < n; i++) {
        if (a[i] != ans[last]) {
            ans.push_back(a[i]);
        } else if (b[i] != ans[last]) {
            ans.push_back(b[i]);
        } else if (c[i] != ans[last]) {
            ans.push_back(c[i]);
        }
        last++;
    }
    if (a[n] != a[1] && a[n] != ans[last]) ans.push_back(a[n]);
    else if (b[n] != a[1] && b[n] != ans[last]) ans.push_back(b[n]);
    else ans.push_back(c[n]);
    for (int i: ans) {
        cout << i << " ";
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