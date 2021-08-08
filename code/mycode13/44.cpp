#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n, a[N];

vector<int> v, g;

int vis[N];

set<int> s;

void solve() {
    v.clear();
    g.clear();
    s.clear();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vis[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i - 1]) {
            v.push_back(-1);
        } else {
            v.push_back(a[i]);
        }
    }
    for (int i: v) {
        if (i != -1) {
            vis[i]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            g.push_back(i);
            s.insert(i);
        }
    }
    int pos = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == -1) {
            cout << g[pos] << " ";
            pos++;
        } else {
            cout << v[i] << " ";
        }
    }
    cout << endl;
    int last = v[0];
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == -1) {
            auto it = s.lower_bound(last);
            it--;
            cout << *it << " ";
            last = *it;
            s.erase(it);
        } else {
            cout << v[i] << " ";
            last = v[i];
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