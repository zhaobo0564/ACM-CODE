#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;

string s;

int sum[N];

void solve() {
  
    int n; cin >> n;
    cin >> s;
    for (int i = 0; i <= n; i++) {
        sum[i] = 0;
    }
    int ct = 0, T = 0, M = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'T') {
            T++;
        } else {
            M++;
        }
        sum[i] = T;
    }
    if (M * 2 != T) {
        cout << "NO\n";
        return;
    }
    T = 0, M = 0;
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'T') {
            if (M && T) {
                M--, T--;
                ans++;
            } else {
                
                if (cnt) {
                    cnt--;
                    ans++;
                } else {
                    T++;
                }
            }
        } else {
            if (T) {
                M++;
            } else {
                if (ans) {
                    cnt += 2;
                    ans--;
                } else {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    if (ans == n / 3)
        cout << "YES\n";
    else cout << "NO\n";
    
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}