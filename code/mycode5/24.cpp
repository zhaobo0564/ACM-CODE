#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, x, y, z;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &x, &y, &z);
        if (x != y && y != z && x != z) {
            puts("NO");
        } else {
            
            if (x == y && x >= z) {
                puts("YES");
                printf("%d %d %d\n", max(x, z), min(x, z), min(x, z));
            } else if ( x == z && x >= y) {
                puts("YES");
                printf("%d %d %d\n", min(x, y), max(x, y), min(x, y));
            } else if (y == z && y >= x) {
                puts("YES");
                printf("%d %d %d\n", min(x, z), min(x, z), max(x, z));
            } else {
                puts("NO");
            }
        }
    }
}