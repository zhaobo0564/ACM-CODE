#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll cnt = n + 1;
    while (1) {
        int f = 1;
        for (int i = 2; i <= n; i++) {
            if (cnt % i != 1) {
                f = 0;
                break;
            }
        }
        if (f) break;
        cnt += n;
    }
    cout << cnt << endl;
}