#include<bits/stdc++.h>
using namespace std;
string s;

int main() {
    cin >> s;
    int last = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] =='.') {
            last = s[i + 1] - '0';
            break;
        }
    }
    if (last >= 5) {
        vector<int> ans;
        ans.push_back(0);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '.') break;
            ans.push_back(s[i] - '0');
        }
        for (int i = ans.size() - 1; i >= 0; i--) {
            ans[i]++;
            if (ans[i] == 10) {
                ans[i] = 0;
            } else {
                break;
            }
        }
        if (ans[0]) {
            cout << ans[0];
        }
        for (int i = 1; i < ans.size(); i++) {
            cout << ans[i];
        }
        cout << endl;
    } else {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '.') break;
            cout << s[i];
        }
        cout << endl;
    }
}