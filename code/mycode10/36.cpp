#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 7;

typedef long long ll;

ll n, a[N];

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    ll sum = 0;
    int f = 0;
    ll minn = 1e10;
    ll maxn = -1e10;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] < 0) {
            f++;
        } 
        minn = min(a[i], minn);
        maxn = max(a[i], maxn);
        sum += abs(a[i]);
    }
    if (n == 1) {
        cout << a[1] << endl;
        return 0;
    }
    if (f) {
        if (f != n) {
            cout << sum << endl;
        } else {
            cout << sum - 2 * abs(maxn) << endl;
        }
       
    } else {
        cout << sum - 2 * minn << endl;
    }

}