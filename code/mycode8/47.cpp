#include<bits/stdc++.h>
using namespace std;

const int N = 1007;

int n, a[N], t, l[N], r[N];

stack<int> q;

void solve() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        while (!q.empty() && a[q.top()] > a[i]) {
            l[q.top()] = i;
            q.pop();
        }
        q.push(i);
    }

    while (q.size()) {
        l[q.top()] = n + 1;
        q.pop();
    }

    for (int i = n; i; i--) {
        while (!q.empty() && a[q.top()] > a[i]) {
            r[q.top()] = i;
            q.pop();
        }
        q.push(i);
    }
    while (q.size()) {
        r[q.top()] = 0;
        q.pop();
    }

    for (int i = 1; i <= n; i++) {
        if (r[i] > 0 && l[i] <= n) {
            cout << "YES\n";
            cout << r[i] << " " << i << " " << l[i] << endl;
            return;
        }
    }
    cout << "NO\n";
    return;

    
}

int main() {
    ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        solve();
    }
}