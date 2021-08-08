#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

void solve() {
	ll a[4];
	cin >> a[1] >> a[2] >> a[3];
	sort(a + 1, a + 4);
	ll sum = a[1] + a[2] + a[3];
	if (sum % 9 == 0) {
		ll cnt = sum / 9;
		if (cnt > a[1]) {
			cout << "NO\n";
		} else {
			cout << "yes\n";
		}

	} else {
		cout << "No\n";
	}

}

int main() {
	ios::sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
}