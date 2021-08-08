#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 7;

ll a[N], n, k;

vector<ll>ne, pos, ze;

bool judge(ll x) {
    ll ans = 0;
    if (x >= 0) {
        ll cnt = ne.size();
        ll cn = pos.size();
        ans = cn * cnt ;
        ll res = 0;
        ll same = 0;
        for (int i = 0; i < ne.size(); i++) {
            ll cat = x / ne[i];

            int p = lower_bound(ne.begin(), ne.end(), cat) - ne.begin();
            res += 1ll*(ne.size() -  p);
            if (ne[i] * ne[i] <= x) same++;

        }
        ans += (((res + same) / 2) - same); 
        res = 0;
        same = 0;
        for (int i = 0; i < pos.size(); i++) {
            ll cat = x / pos[i];
            int p = upper_bound(pos.begin(), pos.end(), cat) - pos.begin();
            res += 1ll * p;
            if (pos[i] * pos[i] <= x) same++;
        }
        ans += (((res + same) / 2) - same);
        ll zero = ze.size();
        ans += zero * cnt;
        ans += zero * cn;
        ans += (zero * (zero - 1)) / 2;
       // cout << ans << endl;
    } else {
        for (int i = 0; i < ne.size(); i++) {
            ll cat = x / ne[i];
            if (x % ne[i]) {
                cat++;
            }
            int p =lower_bound(pos.begin(), pos.end(), cat) - pos.begin();
            ans += 1ll*(pos.size() - p);
        }
       // cout << ans << endl;
    }
    if (ans >= k) return true;
    return false;
}

vector<ll> v;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        
        if (a[i] > 0) {
            pos.push_back(a[i]);
        } else if (a[i] == 0) {
            ze.push_back(a[i]);
        } else {
            ne.push_back(a[i]);
        }
    }
    sort(pos.begin(), pos.end());
    sort(ne.begin(), ne.end());
    ll l = -1e18, r = 1e18, ans;
    while (l <= r) {
        ll m = (l + r) / 2;
     //   cout << "l " << l << " r = " << r << endl;
        if (judge(m)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << ans << endl;

}