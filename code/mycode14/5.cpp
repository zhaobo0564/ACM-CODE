#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
typedef long long ll; 

int a[N], n, q;
vector<int> res;

vector<int> g[60];

void solve() {
    scanf("%d %d", &n, &q);
    int maxn = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        maxn = max(maxn, a[i]);
        g[a[i]].push_back(i);
    }
    int base = 0;
    while (q--) {
        int x; cin >> x;
        int pos = g[x][0];
        int ans = 0;
        for (int i = 1; i <= maxn; i++) {
            if (i == x) continue;
            int p = lower_bound(g[i].begin(), g[i].end(), pos) - g[i].begin();
            p--;
           // cout << "colot " << i << " p " << g[i][p] << endl;
            ans += p + 1;
            
        }
        res.push_back(ans + 1);
        g[x][0] = base;
        base--;
    }
    for (int i: res) {
        printf("%d ", i);
    }
    puts("");
    
}

int main() {
    //ios::sync_with_stdio(0);
    int t = 1;
    while (t--) {
        solve();
    }
}