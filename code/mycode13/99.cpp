#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
set<int> q;

int vis[N];

vector<int> ans;

void solve() {
    ans.clear();
    q.clear();
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    for (int i = 0; i <= n; i++) {
        vis[i] = 0;
    }
    int sum = 0;
    for (int i = n; i >= n - (r - l); i--) {
        sum += i;
    }
    if (s > sum) {
        cout << -1 << endl;
        return;
    }
    sum = 0;
    for (int i = 1; i <= r - l + 1; i++) {
        q.insert(i);
        sum += i;
    }
    if (s < sum) {
        cout << -1 << endl;
        return;
    }
    int d = s - sum;
    int base = n;
    int cnt = r - l + 1;
    while (d) {
        int now = cnt;
        while (1) {
            now++;
            d--;
            auto it = q.lower_bound(now - 1);
            q.erase(it);
            q.insert(now);
            if (d == 0) {
                break;
            }
            if (now == base) {
                base--;
                break;
            }
        }
        cnt--;
    }
    for (auto it: q) {
        vis[it] = 1;
    }
    for (int i = 1; i < l; i++) {
        for (int j = 1; j <= n; j++) {
            if (vis[j] == 0) {
                ans.push_back(j);
                vis[j] = 1;
                break;
            }
        }
    }
    for (auto it: q) {
        ans.push_back(it);
    }
    for (int i = r + 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (vis[j] == 0) {
                ans.push_back(j);
                vis[j] = 1;
                break;
            }
        }
    }
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