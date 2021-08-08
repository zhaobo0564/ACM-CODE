#include<bits/stdc++.h>
using namespace std;

bool work(int a, int b, int c, int d) {
    int odd = 0, even = 0;
    if (a % 2 == 0) {
        even++;
    } else {
        odd++;
    }
    if (b % 2 == 0) {
        even++;
    } else {
        odd++;
    }
    if (c % 2 == 0) {
        even++;
    } else {
        odd++;
    }
    if (d % 2 == 0) {
        even++;
    } else {
        odd++;
    }
    if (odd > 1) return false;
    return true;

}

int main() {
    int t, r, g, b, w;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d %d", &r, &g, &b, &w);
        if (r && g && b) {
        
            if (work(r, g, b, w)) {
                puts("YES");
            } else {
               if (work(r - 1, g - 1, b - 1, w + 3)) {
                   puts("YES");
               } else {
                   puts("NO");
               }
            }
            
        } else {
            if (work(r, g, b, w)) {
                puts("YES");
            } else {
                puts("NO");
            }
        }
    }
}