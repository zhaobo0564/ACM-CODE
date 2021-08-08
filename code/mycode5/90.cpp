#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 7;

string s;

char vis[200][200];

int work(string a) {
    int ans = 0;
    for (int i = 0; i <a.length(); i++) {
        if (a[i] != s[i])ans++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    vis['L']['R'] = 'R';
    vis['R']['L'] = 'L';
    vis['L']['L'] = 'R';
    vis['R']['R'] = 'L';

    while (t--) {
        int n; cin >> n >> s;
        string a = "LRL";
        while(a.length() < n) {
            a += vis[a[a.length() - 2]][a[a.length() - 1]];
        }
        int ans = work(a);
        if (vis[a[a.length() - 2]][a[a.length() - 1]] != a[0]) ans++;
         while(a.length() < n) {
            a += vis[a[a.length() - 2]][a[a.length() - 1]];
        }
        if (vis[a[a.length() - 2]][a[a.length() - 1]] != a[0]) 
            ans = min(ans, work(a) + 1);
        a = "LLR";
         while(a.length() < n) {
            a += vis[a[a.length() - 2]][a[a.length() - 1]];
        }
        if (vis[a[a.length() - 2]][a[a.length() - 1]] != a[0]) 
            ans = min(ans, work(a) + 1);
        a = "RRL";
         while(a.length() < n) {
            a += vis[a[a.length() - 2]][a[a.length() - 1]];
        }
        if (vis[a[a.length() - 2]][a[a.length() - 1]] != a[0]) 
            ans = min(ans, work(a) + 1);
        cout << ans << endl;

        
        
        
    }
}