#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

typedef long long ll;

int a[N], n, b[N];

void solve() {
    cin >> n;
    vector<int> g;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (b[i] == 0) {
            g.push_back(a[i]);
        }
    }
    sort(g.begin(), g.end());
    reverse(g.begin(), g.end());
    int l = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i]) {
            cout << a[i] << " ";
        } else {
            cout << g[l] << " ";
            l++;
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
}