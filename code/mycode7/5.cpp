#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
typedef long long ll;

ll n, a[N], q, vis[N];

int main() {
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        vis[a[i]]++;
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        ll u, v; cin >> u  >> v;
        sum -= 1ll* vis[u] * u;
        sum += 1ll * vis[u] * v;
        vis[v] += vis[u];
        vis[u] = 0;
        cout << sum << endl;
        
    }
    
}