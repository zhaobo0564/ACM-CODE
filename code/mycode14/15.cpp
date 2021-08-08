#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 7;

string s[N];
map<string, int> vis;

int main() {
    ios::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        string ans = "";
        for (int j = s[i].length() - 1; j >= 0; j--) {
            ans += s[i][j];

            vis[ans]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        reverse(s[i].begin(), s[i].end());
    
        cout << vis[s[i]] << endl;
    }
    return 0;
}