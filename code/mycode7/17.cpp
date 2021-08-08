#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 +7;
typedef long long ll;

char s[N];




void solve() {
    int n;
    cin >> n >> (s + 1);
    int ans = 0;
    int l = 1, r = n;
    int lsum = 1, rsum = 1;
    int cnt = 0;
    while (1) {
        lsum = 1, rsum = 1;
        for (int i = l + 1; i <= r; i++) {
            if (s[i] == s[i - 1]) {
                lsum++;
            } else {
                break;
            }
        }

        if (lsum > cnt) {
            lsum -= cnt;
            l += cnt;
            cnt = 0;
         
        } else {
            l = l + (lsum - 1);
            cnt = cnt - (lsum - 1);
            lsum = 1;
            

        }

        if (lsum > 1) {
            l += lsum;
            ans++;
            
        } else {
            l++;
            cnt++;
            ans++;

        }
        if (l + cnt > n) break;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}