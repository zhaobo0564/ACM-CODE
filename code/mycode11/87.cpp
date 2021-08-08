#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 7;
ll n, a[N], m, x[N];

map<ll, int> mp;

vector<ll> v;

void solve() {
    cin >> n >> m;
    mp.clear();
    v.clear();
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        if (mp[sum] == 0) {
            mp[sum] = i;
            v.push_back(sum);
        }
        
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    ll last = v[0];
    for (ll i: v) {
        mp[i] = min(mp[i], mp[last]);
        last = i;
    }
    reverse(v.begin(), v.end());
    for (int i = 1; i <= m; i++) {
        cin >> x[i];
        ll cat = lower_bound(v.begin(), v.end(), x[i]) - v.begin();
      //  cout <<"a " << v[cat] << endl;
        if (cat < v.size() && mp[v[cat]] > 0) {
            cout << mp[v[cat]] - 1 << " ";
        } else {
            if (sum <= 0) {
                cout << -1 << " ";
                continue;
            }
            ll maxn = v[v.size() - 1];
            ll cnt = x[i] / sum;
            int r = cnt, l = 1;
            if (x[i] % sum) {
                r++;
            }
            ll dog = 0;
            while (l <= r) {
                int mid = (l + r) / 2;
                ll res = mid * sum + maxn;
                if (res >= x[i]) {
                    dog = mid;
                    r =  mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            cnt = x[i] - sum * dog;
            ll cat = lower_bound(v.begin(), v.end(), cnt) - v.begin();
            if (cnt == 0) {
                cout << n * dog - 1 << " ";
            } else {
                cout << n * dog + mp[v[cat]] - 1 << " ";
            }
        }
    }
    cout << endl;

}


int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }    
}