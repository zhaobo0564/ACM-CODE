#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;
int n, a[N];

vector<int> odd,even;

void solve() {
    odd.clear();
    even.clear();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] % 2) {
            odd.push_back(a[i]);
        } else {
            even.push_back(a[i]);
        }
    }
    if (odd.size() > even.size()) {
        for (int i: odd) {
            cout << i << " ";
        }
        for (int i: even) {
            cout << i << " ";
        }
    } else {
        for (int i: even) {
            cout << i << " ";
        }
        for (int i: odd) {
            cout << i << " ";
        }
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