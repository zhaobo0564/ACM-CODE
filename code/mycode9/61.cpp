#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
ll n, a[N];

void solve() {
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    vector<int> ans;
    ans.push_back(a[1]);
    ll now = a[1];
    for (int i = 2; i <= n; i++) {
        if (a[i > now]) {
            ll cnt = a[i] % now;
            if (cnt * 2 > a[i]) {
                now = (a[i] / now + 1) * now;
            } else {
                now = (a[i] / now) * now;
            }
        } else {
            ll cnt = now - a[i];
            if (cnt * 2 > a[i]) {
                now = now / 2;
            }
        }

    }

    
}

int main() {
	ios::sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
}