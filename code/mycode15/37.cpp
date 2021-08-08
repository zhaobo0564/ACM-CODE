#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
typedef long long ll;

ll a[N], n;
char c[N];

vector<ll> r, g, b, A, B, C;

ll cal(ll l, ll r) {
    int p = lower_bound(C.begin(), C.end(), l) - C.begin();
    if (p == C.size()) {
        return LLONG_MAX;
    }
    int p1 = upper_bound(C.begin(), C.end(), r) - C.begin() - 1;
    if (p1 < 0) {
        return (C[p] - l) + r - C[p];
    }
    return C[p] - l + r - C[p1];
}

ll L[N], R[N];

void gao() {
    for (int i = 0; i < C.size(); i++) {
        int p = lower_bound(A.begin(), A.end(), C[i]) - A.begin();
        ll minn = 1e17;
        if (p - 1 >= 0) {
            minn = min(minn, C[i] - A[p - 1]);
        } 
        if (p + 1 < A.size()) {
            minn = min(minn, A[p + 1] - C[i]);
        }
        if (p < A.size()) {
            minn = min(minn, A[p] - C[i]);
        }
        L[i + 1] = minn;
        R[i + 1] = minn;
    }
    L[0] = 1e17;
    for (int i = 1; i <= C.size(); i++) {
        L[i] = min(L[i - 1], L[i]);
    }
    R[C.size() + 1] = 1e17;
    for (int i = C.size(); i; i--) {
        R[i] = min(R[i + 1], R[i]);
    }
}

ll work(ll x) {
    ll ans = LLONG_MAX;
    int p = lower_bound(C.begin(), C.end(), x) - C.begin();
    if (p - 1 >= 0) {
        ll minn = abs(x - C[p - 1]);
        ans = min(ans, minn + min(L[p - 1], R[p + 1]));
    } 
    if (p + 1 < C.size()) {
        ll minn =abs( x - C[p + 1]);
        ans = min(ans, minn + min(L[p + 1], R[p + 3]));
    }
    if (p < C.size()) {
        ll minn = abs(x - C[p]);
        ans = min(ans, minn + min(L[p], R[p + 2]));
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i] >> c[i];
        if (c[i] == 'R') {
            r.push_back(a[i]);
        } else if (c[i] == 'B') {
            b.push_back(a[i]);
        } else {
            g.push_back(a[i]);
        }
        rev
    } 
    if (r.size() % 2) {
        A = r;
    } else {
        C = r;
    }
    if (b.size() % 2) {
        if (A.size() == 0) {
            A = b;
        } else {
            B = b;
        }
    } else {
        C = b;
    }
    if (g.size() % 2) {
        if (A.size() == 0) {
            A = g;
        } else {
            B = g;
        }
    } else {
        C = g;
    }
    if (A.size() == 0) {
        cout << 0 << endl;
        return 0;
    } 
    sort(C.begin(), C.end());
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    gao();
    ll ans = LLONG_MAX;
    for (ll i: B) {
        ans = min(ans, work(i));
        int  p = lower_bound(A.begin(), A.end(), i) -  A.begin();
        if (p > 0) {
            ans = min(ans, abs(i - A[p - 1]));
            ans = min(ans, cal(A[p - 1], i));
            

        }
        if (p < A.size() - 1) {
            ans = min(ans, abs(A[p + 1] - i));
            ans = min(ans, cal(i, A[p + 1]));
        }
        if (p < A.size() && p >= 0) {
            ans = min(ans, cal(i, A[p]));
            ans = min(ans, abs(A[p] - i));
        }
    }
   



    if (ans == LLONG_MAX) ans = 0;
    cout << ans << endl;
    return 0;

}