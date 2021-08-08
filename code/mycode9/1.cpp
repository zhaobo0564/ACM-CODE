#include<bits/stdc++.h>
using namespace std;

bool judge(char x) {
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
        return true;
    }
    return false;
}

int main() {
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            int cnt = 0;
            for (int j = i; j < s.length(); j++) {
                if (judge(s[j])) {
                    cnt++;
                } else {
                    break;
                }
            }
            ans = max(ans, cnt);
        }
        cout << ans << endl;
    }
}