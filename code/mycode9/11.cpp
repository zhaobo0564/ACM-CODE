#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int a[N], vis[N], cnt[N];
typedef long long ll;
vector<ll> g[N];

int main() {
    for (int i = 1; i <= 1000; i++) {
        for (int j = i + 1; j <= 1000)
    }

    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        ll cnt = n;
        for (ll i = 2; i <= sqrt(n + 1); i++) {
            cnt = n;
            if (cnt % i == 0) {
                while (1) {
                    ll cn = cnt / i;
                    if (cn % i != 0) {
                        g[i].push_back(cnt);
                        break;
                    } else {
                        cnt = cnt / i;
                        g[i].push_back(i);
                    }

                }
            }
        }
        g[1].push_back(n);
        ll maxn = 0, pos;
        for (ll i = 1; i <= sqrt(n + 1); i++) {
            if (g[i].size() > maxn) {
                maxn = g[i].size();
                pos = i;
            }
        } 
        cout << maxn << endl;
        for (ll i: g[pos]) {
            cout << i << " ";
        }
        cout << endl;

        for (int i = 1; i <= sqrt(n + 1); i++) {
            g[i].clear();
        }
      
    }
}