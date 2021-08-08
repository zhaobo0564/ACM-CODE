#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

typedef long long ll;

ll n, a[N], b[N], m, cnt[N];

vector<ll> one, two;

void solve() {
    cin >> n >> m;
    one.clear();
    two.clear();
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (b[i] == 1) {
            one.push_back(a[i]);
        } else {
            two.push_back(a[i]);
        }
    }
    if (sum < m) {
        cout << -1 << endl;
        return;
    }
    sort(one.begin(), one.end());
    sort(two.begin(), two.end());
    reverse(one.begin(), one.end());
    reverse(two.begin(), two.end());

    for (int i = 0; i < two.size(); i++) {
        cnt[i + 1] = cnt[i] + two[i];
    }
    int ans = 1e9;

    int p = lower_bound(cnt + 1, cnt + two.size() + 1, m) - cnt;
    if (p <= two.size())
        ans = min(ans, p * 2);
    ll cat = 0;
    for (int i = 0; i < one.size(); i++) {
        cat += one[i];
        if (cat >= m) {
            ans = min(ans, i + 1);
            break;
        }
        int p = lower_bound(cnt + 1, cnt + two.size() + 1, m - cat) - cnt;
       // cout << "P " << p << endl;
        if (p <= two.size())
            ans = min(ans, p * 2 + (i + 1));
    }
    cout << ans << endl;
    

}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}