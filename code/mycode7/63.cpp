#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int a[N], n, k, vis[N];
vector<int> ans;
void solve() {
    ans.clear();
    cin >> n >> k;
    int maxn = 0;
    set<int> v;
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v.insert(a[i]);
        vis[a[i]] = 1;
    }
    maxn = v.size();
    if (maxn > k) {
        cout << -1 << endl;
    } else {
        int p = 0;

       for (int i = 1; i <= n; i++) {
           if (vis[i] == 1) {
               ans.push_back(i);
           }
       }
       for (int i = 1; i <= n; i++) {
           if (vis[i] == 0) {
               if (ans.size() < k) {
                   ans.push_back(i);
               }
           }
       }
       if (ans.size() < k) {
           cout << -1 << endl;
       } else {
           cout << 100 * ans.size() << endl;
           for (int i = 1; i <= 100; i++) {
               for (int j: ans) {
                   cout << j << " ";
               }
           }
           cout << endl;
       }
       
    }
    

    
   

    
    
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}