#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll w, h;

ll fn[40];
ll work(ll x) {
    
}

int main() {
    cin >> h >> w;
    fn[0] = 1;
    for (int i = 1; i <= 30; i++) {
        fn[i] = fn[i - 1] * 2;
    }
    ll hh = 0, ww;
    for (int i = 0; i <= 30; i++) {
        if (fn[i] > w) break;
        ll cn = work(fn[i]);
        if (cn > hh) {
            hh = cn;
            ww = fn[i];
        }
    }
    ll hh1, ww1 = 0;

    for (int i = 0; i <= 30; i++) {
        if (fn[i] > h) break;
        ll cn = work1(fn[i]);

    }
}