#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

int n, a[N], vis[N], cnt[N];

vector<pair<int, int> >ans;

vector<int>g[N];

void solve() {
    ans.clear();
    cin >> n;
    for (int i = 0; i <= n + 1; i++) {
        vis[i] = cnt[i] = 0;
        g[i].clear();
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int top = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i])continue;
        g[++top].push_back(i);
        for (int j = i + 1; j <= n; j++) {
            if (vis[j]) continue;
            if (a[i] != a[j]) {
                //cout <<"UU\n";
                g[top].push_back(j);
                ans.push_back({i, j});
                vis[j] = 1;
            }
        }
    }
    int pos = -1;
   // cout << "top " << top << endl;
    for (int i = 1; i <= top; i++) {
        
        if (g[i].size() > 1) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "No\n";
    
        return;
    }
    for (int i = 1; i <= top; i++) {
        if (i == pos) continue;
        if (a[g[i][0]] != a[g[pos][0]]) {
            ans.push_back({g[i][0], g[pos][0]});
        } else {
            ans.push_back({g[i][0], g[pos][1]});
        }
    }
    if (ans.size() == n - 1) {
        cout << "Yes\n";
        for (auto it: ans) {
            cout << it.first << " " << it.second << endl;
        } 
    } else {
        cout << "No\n";
    }

  
    
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}