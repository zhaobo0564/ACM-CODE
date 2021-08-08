#include <bits/stdc++.h>
using namespace std;

int t, n, a[107];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        string s = "";
        for (int i = 1; i <= 200; i++) s += 'a';
        cout << s << endl;
        for (int i = 1; i <= n; i++) {
            string ans = "";
           for (int j = 0; j < a[i]; j++) {
               ans += s[j];
           }
           for (int j = a[i]; j < 100; j++) {
               if (s[j] == 'z') {
                   ans += 'a';
               } else {
                   ans += (s[j] + 1);
               }
           }
           cout << ans << endl;
           s = ans;


        }
    }
}