#include<bits/stdc++.h>
using namespace std;

int mp[20][20], n, m;


int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
       cin >> n >> m;
       vector<int> v;
       int ans = 0;
       for (int i = 1; i <= n; i++) {
           for (int j = 1; j <= m; j++) {
               cin >> mp[i][j];
               v.push_back(mp[i][j]);
               ans += mp[i][j];

           }
       }
       sort(v.begin(), v.end());

       int maxn = ans;

       for (int i = 2; i <= n * m; i += 2) {
           ans = 0;
           for (int j = 0; j < i; j++) {
               ans += -v[j];
           }
           for (int j = i; j < v.size(); j++) {
               ans += v[j];
           }
           maxn = max(ans, maxn);
       }
       cout << maxn << endl;

    }
}