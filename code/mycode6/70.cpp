#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

typedef long long ll;

char s[N];

int n;

const ll mod = 1e9 + 7;

ll dp[200], fn[N], lsum[N], rsum[N], lcnt[N], rcnt[N];

void solve() {
    cin >> n >> (s + 1);

    fn[0] = 1;
    for (int i = 1; i <= n; i++) {
        fn[i] = fn[i - 1] * 3 % mod;
        if (s[i] == 'a') {
            lsum[i] = (lsum[i - 1] + 1) % mod;
            lcnt[i] = lcnt[i - 1];
        } else if (s[i] == '?') {
            lsum[i] = lsum[i - 1] ;
            lcnt[i] = lcnt[i - 1] + 1;
        } else {
            lsum[i] = lsum[i - 1];
            lcnt[i] = lcnt[i - 1];
        }
    }

    for (int i = n; i; i--) {
        if (s[i] == 'c') {
            rsum[i] = (rsum[i + 1] + 1) % mod;
            rcnt[i] = rcnt[i + 1];
        } else if (s[i] == '?') {
            rsum[i] = rsum[i + 1];
            rcnt[i] = rcnt[i + 1] + 1;
        } else {
            rsum[i] = rsum[i + 1];
            rcnt[i] = rcnt[i + 1];
        }
    }

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'b' || s[i] == '?') {
            ll cat = lsum[i - 1] * rsum[i + 1] % mod;
            cat = cat * fn[lcnt[i - 1]] % mod;
            cat = cat * fn[rcnt[i + 1]] % mod;
            ll cn = lcnt[i - 1] * rsum[i + 1] % mod;
            cn = cn * fn[rcnt[i + 1]] % mod;
            if (lcnt[i - 1] - 1 >= 0)
                cn = cn * fn[lcnt[i - 1] - 1] % mod;
            ll ct = lcnt[i - 1] * rcnt[i + 1] % mod;
            if (lcnt[i - 1] - 1 >= 0)
                ct = ct * fn[lcnt[i - 1] - 1] % mod;
            if (rcnt[i + 1] - 1 >= 0)
                ct = ct * fn[rcnt[i + 1] - 1] % mod;
            ll cd = rcnt[i + 1] * lsum[i - 1] % mod;
            cd = cd * fn[lcnt[i - 1]] % mod;
            if (rcnt[i + 1] - 1 >= 0)
                cd = cd * fn[rcnt[i + 1] - 1] % mod;
            ans = (ans + cat + cn + ct + cd) % mod;
        } 
    }

    cout << ans << endl;


    

}


int main() {
    ios::sync_with_stdio(0);
    int t = 1;
    while (t--) {
        solve();
    }
}










