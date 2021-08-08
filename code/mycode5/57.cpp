#include<bits/stdc++.h>
using namespace std;

int t, a[1000], n;

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        int f = 0;
        if (n == 1) {
            puts("YES");
        } else {
           for (int i = 2; i <= n; i++) {
               if (a[i] - a[i - 1] >= 2) {
                   f = 1;
                   break;
               }
            } 
            if (f) {
                puts("NO");
            } else {
                puts("YES");
            }
        }
        
    }
}