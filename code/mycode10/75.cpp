#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll v[2000], p[2000], n, x;

int main() {
    cin >> n >> x;

    ll sum = 0;
    x = x * 100;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> p[i];
       
    }
    for (int i = 1; i <= n; i++) {
        sum += v[i] * p[i];
        if (sum > x) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}