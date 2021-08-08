#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 +7;
typedef long long ll;



vector<pair<int, int> >ans;


void solve() {
    ans.clear();
    ll n;
    cin >> n;
    if (n == 2) {
        cout << 2 << endl;
        cout << 1 << " " << 2 << endl;
        return;
    }
    ans.push_back({n, n - 2});
    ans.push_back({n - 1, n - 1});
    int cnt = n - 1;
    for (int i = n - 3; i > 0 ; i--) {
        ans.push_back({cnt, i});
        cnt = (cnt + i) / 2;
    }

    cout << cnt << endl;
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