#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;

ll p, f, cnts, cntw, s, w;

ll work(ll ff, ll cns, ll cnw) {
    ll res = 0;
    if (s > w) {
        ll cn = ff / w;
        if (cn <= cnw) {
            res += cn;
        } else {
            res += cnw;
            cn = cnw;
        }
        ff -= cn * w;
        cn = ff / s;
        if (cn <= cns) {
            res += cn;
        } else {
            res += cns;
        }
    } else {
        ll cn = ff / s;
        if (cn <= cns) {
            res += cn;
        } else {
            res += cns;
            cn = cns;
        }
        ff -= cn * s;
        cn = ff / w;
        if (cn <= cnw) {
            res += cn;
        } else {
            res += cnw;
        }
    }
    return res;
}

int main() {
    
    ios::sync_with_stdio(0);
    int t; 
    cin >> t;
    while (t--) {

    
        cin >> p >> f >> cnts >> cntw >> s >> w;
        ll ans = 0;
        for (ll i = 0; i <= cnts; i++) {
            if (i * s <= p) {
                ll x = i;
                ll pp = p - i * s;
                ll cnty = pp / w;
                ll res = x;
                if (cnty <= cntw) {
                    res += cnty;
                } else {
                    res += cntw;
                    cnty = cntw;
                }
                res += work(f, cnts - x, cntw - cnty);
                ans = max(ans, res);
                    
            } else break;
        }

        for (ll i = 0; i <= cntw; i++) {
            if (i * w <= p) {
                ll y = i;
                ll pp = p - i * w;
                ll cntx = pp / s;
                ll res = y;
                if (cntx <= cnts) {
                    res += cntx;
                } else {
                    res += cnts;
                    cntx = cnts;
                }
                res += work(f, cnts - cntx, cntw - i);
                ans = max(ans, res);
            }else break;
        }
        cout << ans << endl;
    }
}