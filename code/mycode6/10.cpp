#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 7;

int main() {
    ios::sync_with_stdio(0);
    int t, a, b;
    cin >> t; while (t--) {
        cin >> a >> b;
        int c = abs(a - b);
        int ans = c / 10;
        if (c % 10) ans++;
        cout << ans << endl;
    }
}