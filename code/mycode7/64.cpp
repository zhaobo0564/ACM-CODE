#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int n, k, vis[300];
string s;
string ans[N];

vector<string>g;

void solve() {
    cin >> n >> k;
    cin >> s;
    g.clear();
    for (int i = 1; i <= k; i++) {
        ans[i] = "";
    }
    for (int i = 'a'; i <= 'z'; i++) {
        vis[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        vis[s[i]]++;
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 'a'; j <= 'z'; j++) {
            if (vis[j]) {
                ans[i] = char(j);
                vis[j]--;
                break;
            }
        }
    }
    int count = 0;
    for (int i = 'a'; i <= 'z'; i++) {
        if (vis[i]) {
            count++;
        }
    }
    if (k > 1 && ans[k] != ans[1]) {
        cout << ans[k] << endl;
        return;
    }


    if (count == 1) {
        for (int j = 'a'; j <= 'z'; j++) {
            if (vis[j] == 0) continue;
            for (int i = 1; i <= k; i++) {
                if (vis[j]) {
                    ans[i] += char(j);
                    vis[j]--;
                }
            }
            j--;
        }
    } else {
        
        for (int j = 'a'; j <= 'z'; j++) {
            if (vis[j]) {
                ans[k] += char(j);
                vis[j]--;
                j--;
            }
            
        }
    }
    for (int i = 1; i <= k; i++) {
       // cout << ans[i] << endl;
        g.push_back(ans[i]);
    }
    sort(g.begin(), g.end());
    cout << g[g.size() - 1] << endl;
 
    
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}