#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll m;
string x;

bool judge(ll mid) {
    ll cnt = m;
    vector<ll> v;
    while (cnt) {
        v.push_back(cnt % mid);
        cnt = cnt / mid;
    }
    
    if (v.size() > x.length()) {
        return true;
    } else if (v.size() < x.length()) {
        return false;
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > x[i] - '0') {
            return true;
        } else if (v[i] < x[i] - '0') {
            return false;
        }
    }
    return true;


    
}


int main() {
    cin >> x >> m;
    //reverse(x.begin(), x.end());
    if (x.length() == 1) {
        int cnt = x[0] - '0';
        if (cnt <= m) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    }
    int maxn = 0;
    for (int i = 0; i < x.length(); i++) {
        maxn = max(maxn, x[i] - '0');
    }
    ll l = maxn + 1, r = 1e18;
    ll ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (judge(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }

    }
    if (ans == 0) {
        cout << ans << endl;
        return 0;
    }
    cout << ans - maxn << endl;
    
    
}