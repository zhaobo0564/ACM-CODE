#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int a[N], b[N], n, q;

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    while (q--) {
       int op; cin >> op;
       if (op == 1) {
           int l, r; cin >> l >> r;
           for (int i = l; i <= r; i++) {
               a[i]++;
               if (a[i] >= 99996) {
                   a[i] %= 99996;
               }
           }
        
       } else {
           int pos; cin >> pos;
           int x = 0;
           for (int i = pos; i <= n; i++) {
               if (a[i] == b[i]) {
                   x++;
               } else {
                   break;
               }
           }
           cout << x << endl;
       }
    }
}