#include<bits/stdc++.h>
using namespace std;

int n;
char a[200], b[200];
int main() {
    cin >> n;
    for (int i =1 ; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int ans = 0, ans1 = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) {
            ans += 2;
        } else {
            ans++;
        }
    }
    cout << ans << " " << ans1 << endl;

}