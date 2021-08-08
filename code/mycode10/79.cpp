#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 7;

typedef long long ll;

ll n, x[N], y[N], m, q;

ll a[N], b[N], fza[N], fzb[N], visa[N], visb[N];

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    cin >> m;
    a[0] = 0, b[0] = 0;
    fza[0] = fzb[0] = 1;
    visa[0] = 1, visb[0] = 2;
    for (int i = 1; i <= m; i++) {
        int op;
        cin >> op;
        if (op == 3) {
            ll p;
            cin >> p;
            a[i] = 2 * p - a[i - 1];
            b[i] = b[i - 1];
            visa[i] = visa[i - 1];
            visb[i] = visb[i - 1];
            fza[i] = -fza[i - 1];
            fzb[i] = fzb[i - 1];
        } else if (op == 4) {
            ll p;
            cin >> p;
            b[i] = 2 * p - b[i - 1];
            fzb[i] = -fzb[i - 1];
            a[i] = a[i - 1];
            visa[i] = visa[i - 1];
            visb[i] = visb[i - 1];
            fza[i] = fza[i - 1];
         } else if (op == 2) {
            if (visa[i - 1] == 1) {
                visa[i] = 2;
                visb[i] = 1;
            } else {
                visa[i] = 1;
                visb[i] = 2;
            }
            a[i] = b[i - 1];
            b[i] = a[i - 1];
            fza[i] = fzb[i - 1];
            fzb[i] = fza[i - 1];
            fza[i] = -fza[i];
            a[i] = -a[i];


        } else {
            if (visa[i - 1] == 1) {
                visa[i] = 2;
                visb[i] = 1;
            } else {
                visa[i] = 1;
                visb[i] = 2;
            }
            a[i] = b[i - 1];
            b[i] = a[i - 1];
            fza[i] = fzb[i - 1];
            fzb[i] = fza[i - 1];
            fzb[i] = -fzb[i];
            b[i] = -b[i];
        }
    }
    int q; cin >> q;
    while (q--) {
        int A, B;
        cin >> A >> B;
        ll ansx = x[B], ansy = y[B];
        if (visa[A] == 1) {
            ansx = ansx * fza[A] + a[A];
            ansy = ansy * fzb[A] + b[A];
            

        } else {
            ll cnt = ansx;
            ansx = ansy * fza[A] + a[A];
            ansy = cnt * fzb[A] + b[A];
            
        }
        cout << ansx << " " << ansy << endl;
    }

}


