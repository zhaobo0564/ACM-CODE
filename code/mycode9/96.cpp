#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
typedef long long ll;
ll a[N], n;

vector<ll> even, odd;

void solve() {
    cin >> n;
    even.clear();
    odd.clear();
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            even.push_back(a[i]);
        } else {
            odd.push_back(a[i]);
        }
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    reverse(even.begin(), even.end());
    reverse(odd.begin(), odd.end());
    ll alice = 0, bob = 0;
    int i = 0, j = 0;
    while (1) {
        if (i < even.size() && j < odd.size() && even[i] > odd[j]) {
            alice += even[i];
            i++;
        } else if (j < odd.size()){
            j++;
        } else {
            alice += even[i];
            i++;
        }

        if (i >= even.size() && j >= odd.size()) {
            break;
        }

        if (j < odd.size() && i < even.size() && even[i] < odd[j]) {
            bob += odd[j];
            j++;
        } else if (i < even.size()){
            i++;
        } else {
            bob += odd[j];
            j++;
        }
        if (i >= even.size() && j >= odd.size()) {
            break;
        }
    }
    if (alice > bob) {
        cout << "Alice\n";
    } else if (alice == bob) {
        cout << "Tie\n";
    } else {
        cout << "Bob\n";
    }

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}