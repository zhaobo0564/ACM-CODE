#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1007;

ll a[N], b[N], n;
unordered_map<ll, int>vis;

void solve() {
   vis.clear();
   for (int i = 1; i <= n; i++) {
       vis[b[i]]++;
       if (vis[b[i]] == 2) {
           cout << "YES\n";
           return;
       }
   }
   cout << "NO\n";
   return;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &b[i]);
        }
        solve();

    }
}