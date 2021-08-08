#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll t, l, r;

int main() {
    cin >> t;
    while (t--) {
        cin >> l >> r;
        ll a = r + 1;
        if ( 2 * l >= a && 2 * r >= a) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        
    }
}