#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
typedef long long ll;

ll a[N], n, k;

vector<int> g[N];

void solve() {
    cin >> n >> k;
    ll nn = n;
    n = n * k;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    int base = (nn + 1) / 2, o = 1;

    ll sum = 0;
    int l = 1, r = n;
    
    while (l <= r) {
        while (g[o].size() < base - 1) {
            g[o].push_back(a[r--]);
        }
        while(g[o].size() < nn)
            g[o].push_back(a[l++]);
        o++;
    }

    for (int i = 1; i < o; i++) {
        sort(g[i].begin(), g[i].end());
        

      
    }

    for (int i = 1; i < o; i++) {
        sum += g[i][base - 1];
        g[i].clear();
    }
    cout << sum << endl;
    
}

int main() {
   ll sum = INT_MAX;
   int a = 2;
    sum += a;
    cout << sum << endl;
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}