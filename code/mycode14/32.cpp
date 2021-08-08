#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;
int vis[N];
ll n, a[N];

vector<int> v, ans;

void dfs(int p, ll sum) {
    if (p > n) {
        if (sum == 1) {
            if (ans.size() < v.size()) {
                ans = v;
            }
        }
        return;
    }   
    v.push_back(a[p]);
    dfs(p + 1, sum * a[p] % n);
    v.pop_back();
    dfs(p + 1, sum);
}

void solve() {
    ans.clear();
    v.clear();
    cin >> n;
    for (int i = 1; i < n; i++) {
        a[i] = i;
    }
    dfs(1, 1);
    cout << ans.size() << endl;
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