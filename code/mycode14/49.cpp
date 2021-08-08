#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e3 + 7;

ll a[N][N], n, m;

vector<ll> v, ans[N];

multiset<ll> cnt[N], s;

void solve() {
    v.clear();
    s.clear();
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        cnt[i].clear();
        ans[i].clear();
        
    }
    for (int i = 1; i <= n; i++) {
        ans[i].push_back(0);
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            cnt[i].insert(a[i][j]);
            v.push_back(a[i][j]);
            ans[i].push_back(-1);
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < m; i++) {
        s.insert(v[i]);
    }
    for (int i = 1; i <= m; i++) {
        auto it = s.begin();
        for (int j = 1; j <= n; j++) {
            auto cat = cnt[j].lower_bound(*it);
            if ((*cat) == (*it)) {
                ans[j][i] = *it;
                cnt[j].erase(cat);
                s.erase(it);
                break;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) { 
           if (cnt[j].size() == 0) continue; 
           auto it = cnt[j].begin();
           int f = 0;
           for (int k = 1; k < ans[j].size(); k++) {
               if (ans[j][k] == -1) {
                   ans[j][k] = *it;
                   f = 1;
                   break;
               }
           }
           cnt[j].erase(it);

        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << ans[i][j] << " ";
        } 
        cout << endl;
    }

}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}