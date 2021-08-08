#include<bits/stdc++.h>
using namespace std;

long long n, a[200];

void print(long long x, long long y) {
    printf("+");
    for (int i = 1; i <= x; i++) {
        printf("-");
    }
    printf("+\n");
    printf("|");
    for (int i = 1; i <= x; i++) {
        printf(" ");
    }
    printf("|%lld\n+", y);
    for (int i = 1; i <= x; i++) {
        printf("-");
    }
    printf("+\n");

}

void print_max(long long  x, long long y) {
    printf("+");
    for (int i = 1; i <= x; i++) {
        printf("-");
    }
    printf("+\n");
    printf("|");
    for (int i = 1; i < x; i++) {
        printf(" ");
    }
    printf("*|%lld\n+", y);
    for (int i = 1; i <= x; i++) {
        printf("-");
    }
    printf("+\n");
}

int main() {
    scanf("%lld", &n);
   long long maxn = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        maxn = max(maxn, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == maxn) {
            long long cnt = a[i] * 50;
            long long c = cnt / maxn;
            if (c * maxn == cnt)
                print_max(c, a[i]);
            else
                print_max(c + 1, a[i]);
            
            
        } else {
            long long cnt = a[i] * 50;
            long long c = cnt / maxn;
            if (c * maxn == cnt)
                print(c, a[i]);
            else
                print(c + 1, a[i]);
            
        }
    }
}