#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
int n, a[N];

vector<int> g, v;

int get_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

int vis[N];

priority_queue<int> q;

void solve() {
    cin >> n;
    g.clear();
    v.clear();
    while (q.size()) q.pop();
  
    for (int i = 0; i <= n + 100; i++) {
        vis[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        g.push_back(a[i]);
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    for (int i = 1; i <= n; i++) {
        a[i] = get_id(a[i]);
        vis[a[i]]++;
    }
    for (int i = 1; i <= g.size(); i++) {
        if (vis[i]) {
            q.push(vis[i]);
            vis[i] = 0;
        }
    }
    int res = 0;

    while (q.size() > 1) {
        int cnt = q.top();
        q.pop();
        int cnt1 = q.top();
        q.pop();
        cnt--, cnt1--;
        if (cnt) q.push(cnt);
        if (cnt1) q.push(cnt1);
    }
    while (q.size()) res += q.top(), q.pop();
    cout << res << endl;

}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}