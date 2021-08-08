#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 +7;
int k, n;

int vis[N];

void solve() {
    cin >> n >> k;
    for (int i = 0; i <= n; i++) {
        vis[i] = 0;
    }
    vis[k] = 1;
    for (int i = 1; i < k; i++) {
       if (vis[i] == 0) {
            vis[i] = 1;
            vis[k - i] = -1; 
       }
       
    }
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (vis[i] != 1) {
            v.push_back(i);
        }
    }
    cout << v.size() << endl;
    for (int i: v) {
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