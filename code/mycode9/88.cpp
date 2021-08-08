#include <bits/stdc++.h>
using namespace std;

int a[20];

int main() {
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i <= 9; i++) {
            scanf("%d", &a[i]);
        }
        if (a[8]) {
            puts("8");
            continue;
        }
    }
}