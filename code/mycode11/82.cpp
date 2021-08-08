#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 7;
int n, a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int one = 0, two = 0, three = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] % 3 == 0) {
            one++;
        } else if (a[i] % 3 == 1) {
            two++;
        } else if (a[i] % 3 == 2) {
            three++;
        }
    }
    int ans = 0;
    int cnt = n / 3;
  //  cout << one << " " << two << " " << three << endl;
    if (one > cnt) {
        int cn = one - cnt;
        one = cnt;
        ans += cn;
        two += cn;
    }
    if (two > cnt) {
        ans += (two - cnt);
        three += (two - cnt);
        two = cnt;
    }
    if (three > cnt) {
        ans += (three - cnt);
        one += (three - cnt);  
        three = cnt;
    }
 //   cout << one << " " << two << " " << three << endl;

    if (one > cnt) {
        int cn = one - cnt;
        one = cnt;
        ans += cn;
        two += cn;
    }
    if (two > cnt) {
        ans += (two - cnt);
        
        three += (two - cnt);
        two = cnt;
    }
    if (three > cnt) {
        ans += (three - cnt);
        
        one += (three - cnt);
        three = cnt;
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