#include<bits/stdc++.h>
using namespace std;
const int N = 50;
typedef long long ll;

ll a[N], n, x;

vector<ll> first, second;

void dfs(int p, ll sum, int count) {
    if (p > count) {
        if (count == n / 2) {
            first.push_back(sum);
        } else {
            second.push_back(sum);
        }
        return;
    }
    dfs(p + 1, sum + a[p], count);
    dfs(p + 1, sum, count);
}


int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1, 0, n / 2);
    dfs(n / 2 + 1, 0, n);
    sort(second.begin(), second.end());
    ll ans = 0;
    for (int i = 0; i < first.size(); i++) {
        ll value = first[i];
        int p = lower_bound(second.begin(), second.end(), x - value) - second.begin();
        if (p < second.size()) {
            ans += 1ll*(second.size() - p);
        }
    }
    cout << ans << endl;

}