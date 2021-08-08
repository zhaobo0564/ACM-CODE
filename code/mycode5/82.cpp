#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
string s;
int main() {
    ios::sync_with_stdio(0);
    cin >> s;
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'R') {
            cnt++;
        } else {
            ans = max(cnt, ans);
            cnt = 0;
        }
    }
    ans = max(cnt, ans);
    cout << ans << endl;
}

