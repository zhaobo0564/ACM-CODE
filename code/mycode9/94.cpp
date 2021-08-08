#include<bits/stdc++.h>
using namespace std;

int a[200], n;

void solve() {
    cin >> n;
    int one = 0, two = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            one++;
        } else {
            two++;
        }
    }
    int cnt = two % 2;
    cnt = cnt * 2;
    if (one < cnt) {
        puts("No");
    } else {
        one -= cnt;
        if (one % 2 == 0) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
   

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}