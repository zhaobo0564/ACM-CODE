#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

char s[500][500];
int n;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> (s[i] + 1);
    }
    vector<pair<int, int> >ans;
    if (s[1][2] == '0' && s[2][1] == '0') {
        if (s[n][n - 1] == '0') {
            ans.push_back({n, n - 1});
        }
        if (s[n - 1][n] == '0') {
            ans.push_back({n - 1, n});
        }
    } else if (s[1][2] == '0' && s[2][1] == '1') {
        if (s[n - 1][n] == '0' && s[n][n - 1] =='0') {
            ans.push_back({1, 2});
        } else if (s[n - 1][n] == '1' && s[n][n - 1] =='1') {
            ans.push_back({2, 1});
        } else if (s[n - 1][n] == '1' && s[n][n - 1] == '0') {
            ans.push_back({2, 1});
            ans.push_back({n, n - 1});
        } else {
            ans.push_back({2, 1});
            ans.push_back({n - 1, n});
        }
    } else if (s[1][2] == '1' && s[2][1] == '0') {
        if (s[n - 1][n] == '0' && s[n][n - 1] =='0') {
            ans.push_back({2, 1});
        } else if (s[n - 1][n] == '1' && s[n][n - 1] =='1') {
            ans.push_back({1, 2});
        } else if (s[n - 1][n] == '1' && s[n][n - 1] == '0') {
            ans.push_back({1, 2});
            ans.push_back({n, n - 1});
        } else {
            ans.push_back({1, 2});
            ans.push_back({n - 1, n});
        }
    } else {
        if (s[n][n - 1] == '1') {
            ans.push_back({n, n - 1});
        }
        if (s[n - 1][n] == '1') {
            ans.push_back({n - 1, n});
        }
    }
    cout << ans.size() << endl;
    for (auto it: ans) {
        cout << it.first << " " << it.second << endl;
    }

}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}