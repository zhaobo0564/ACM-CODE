#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;

char s[N];

int ans[N];

int n, t, x;

int main() {
    ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> (s + 1);
        cin >> x;
        n = strlen(s + 1);
        for (int i = 1; i <= n; i++) {
            ans[i] = -1;
        }
        int ok = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') {
                if (i + x <= n && i - x >= 1) {
                    ans[i + x] = 0;
                    ans[i - x] = 0;
                } else if (i + x <= n) {
                    ans[i + x] = 0;
                } else if (i - x >= 1) {
                    ans[i - x] = 0;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (s[i] == '1') {
                int f = 0;
                if (i + x <= n && i - x >= 1) {
                    if (ans[i - x] == -1) {
                        ans[i - x] = 1;
                    } else if (ans[i - x] == 0) {
                        f++;
                    }
                    if (f) {
                        if (ans[i + x] == -1) {
                            ans[i + x] = 1;
                        } else if (ans[i + x] == 0) {
                            f++;
                        }
                    }
                    if (f == 2) {
                        ok = 1;
                        break;
                    }
                } else if (i + x <= n) {
                    if (ans[i + x] == -1) {
                        ans[i + x] = 1;
                    } else if (ans[i + x] == 0) {
                        f = 1;
                    }
                    if (f) {
                        ok = 1;
                        break;
                    }
                    
                } else if (i - x >= 1) {
                    if (ans[i - x] == -1) {
                        ans[i - x] = 1;
                    } else if (ans[i - x] == 0) {
                        f = 1;
                    }
                    if (f) {
                        ok = 1;
                        break;
                    }
                } else {
                    ok = 1;
                    break;
                }
            }
        }
        if (ok) {
            cout << "-1\n";
        } else {
            for (int i = 1; i <= n; i++) {
                if (ans[i] == -1) {
                    cout << 0;
                } else {
                    cout << ans[i];
                }
            }
            cout << "\n";
        }

           
    }
}