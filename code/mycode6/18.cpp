#include<bits/stdc++.h>
using namespace std;


const int N = 3e5 + 7;

typedef long long ll;

int n, k;
char s[N];

void solve() {
    cin >> n >> k;
    cin >> (s + 1);
    int f = 0;
    for (int i = 1; i <= k; i++) {
        int ok = 0; 
        char c = 'a';
        for (int j = i; j <= n; j += k) {
            if (s[j] == '1') {
                if (c == 'a') c = '1';
                else if (c == '0') {
                    ok = 1;
                    break;
                }
            } else if (s[j] == '0') {
                if (c == 'a') c = '0';
                else if (c == '1') {
                    ok = 1;
                    break;
                }
            }
        }
        if (ok == 1) {
            f = 1;
            break;
        }
        if (c != 'a') {
            s[i] = c;
        }
    }
    // for (int i = 1; i <= k; i++) {
    //     cout << s[i];
    // }
    // cout << endl;
    if (f) cout << "NO\n";
    else {
        int ans = 0, an = 0;
        for (int i = 1; i <= k; i++) {
            if (s[i] == '1') ans++;
            else if (s[i] == '?') an++;
        }
        if (ans > (k / 2)) {
            cout << "NO\n";
        } else if (ans + an >= k / 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
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