#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

string a, b;

map<string, int> vis;

void solve() {
    vis.clear();
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++) {
        string ans = "";
        for (int j = i; j < a.length(); j++) {
            ans += a[j];
            vis[ans] = j - i + 1;
        }
    }
    int maxn = 0;
    for (int i = 0; i < b.length(); i++) {
        string ans = "";
        for (int j = i; j < b.length(); j++) {
            ans += b[j];
            maxn = max(maxn, vis[ans]);
        } 

    }
  
    cout << a.length() + b.length() - 2 * maxn << endl;

}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}