#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;
typedef long long ll;

int n, a[N];

int vis[N], cnt[N];

vector<int> v;


void solve() {
    cin >> n;
    v.clear();
    v.push_back(0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vis[i] = 0;
    }
    vis[0] = vis[n + 1] = 0;
    int last = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i - 1] == a[i]) {
            vis[i - 1] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            v.push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            if (a[i] == a[last]) {
                int l = lower_bound(v.begin(), v.end(), last) - v.begin();
                int r = lower_bound(v.begin(), v.end(), i) - v.begin();
              //  cout << v[l] << " " << v[r] << endl;
                for (int j = l; j <= r; j++) {
                    if (j < v.size() && v[j] < i && v[j] > last && a[v[j]] != a[i]) {
                        if (j + 1 < v.size()) {
                           // cout << "l " << a[v[j - 1]] << " r = " << a[v[j + 1]] << endl;
                            if (a[v[j - 1]] != a[v[j + 1]]) {
                                vis[v[j]] = 1;
                                break;
                            }
                        } else if(j < v.size()){
                            vis[v[j]] = 1;
                            break;
                        }
                    }
                }
            }
            last = i;
        }
    }

    int ans = 0;
    last = 0;
    for (int i = 1; i <= n; i++) {
       if (vis[i] == 1) {
          // cout << a[i] << " ";
           if (a[i] != last) {
               ans++;
           }
           last = a[i];
       }
    }
  //  cout << endl;
    last = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            if (a[i] != last) {
               ans++;
            }
            last = a[i];
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