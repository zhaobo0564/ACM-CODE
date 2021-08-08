#include<bits/stdc++.h>
using namespace std;

int  n, t, a[100007];

int main() {
    scanf("%d", &t);
    while (t--) {
       scanf("%d", &n);
       for (int i = 1; i <= n; i++) {
           scanf("%d", &a[i]);
       }
        int one = 0, two = 0;
       for (int i = 1; i <= n; i++) {
           if (a[i] > 1) two++;
           if (two == 0) {
               one++;
           }
       }
       if (two == 0) {
           if (one % 2 == 0) {
               puts("Second");
           } else {
               puts("First");
           }
       } else {
           if (one % 2 == 0) {
               puts("First");
           } else {
                puts("Second");
           }
       }
       

        
    }
}